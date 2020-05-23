#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <chrono>
#include <algorithm>
#include <cctype>
#include <string>
#include <functional>

#include "main.hpp"
#include "state.hpp"
#include "attack.hpp"
#include "search.hpp"

#ifndef WASM
const int PV_TABLE_KEY_SIZE_IN_BITS = 22;
#else
const int PV_TABLE_KEY_SIZE_IN_BITS = 22;
#endif

const Magic PV_TABLE_SIZE = (1<<PV_TABLE_KEY_SIZE_IN_BITS);
const Magic PV_TABLE_MASK = PV_TABLE_SIZE - 1;

bool search_stopped;

Move root_move;
bool has_root_move;
Move finished_root_move;
bool has_finished_root_move;
Move finished_ponder_move;
bool has_finished_ponder_move;

PvEntry pv_table[PV_TABLE_SIZE];

PvEntry get_pv_entry(State *st){
	Magic key = st->hash_key & PV_TABLE_MASK;
	PvEntry entry = pv_table[key];
	if(entry.key == st->hash_key){
		entry.ok = true;
		return entry;
	}
	entry.ok = false;
	return entry;
}

void set_pv_entry(State *st, Move move, Depth depth){	
	PvEntry old_entry = get_pv_entry(st);
	if(old_entry.ok){
		if(old_entry.depth < depth){
			return;
		}
	}
	Magic key = st->hash_key & PV_TABLE_MASK;	
	PvEntry new_pv_entry = old_entry;
	new_pv_entry.depth = depth;
	new_pv_entry.key = st->hash_key;
	new_pv_entry.ok = true;
	for(int i = MAX_PV_MOVES-1; i > 0; i--){
		new_pv_entry.moves[i] = new_pv_entry.moves[i-1];
	}
	new_pv_entry.moves[0] = move;
	pv_table[key] = new_pv_entry;
}

int comp_sort_moves(const void *vm1, const void *vm2){
	MoveSortEntry m1 = *((MoveSortEntry*)vm1);
	MoveSortEntry m2 = *((MoveSortEntry*)vm2);
	if(m1.is_pv != m2.is_pv) return m1.is_pv ? -1 : 1;	
	if(m1.capture != m2.capture) return m1.capture > m2.capture ? -1 : 1;
	return m1.attack > m2.attack ? -1 : 1;
}

bool is_ignored_root_move(LinearGame* lg, Move move){
	for(Move *ptr=lg->ignored_root_moves;ptr<lg->last_ignored_root_move;ptr++){
		if(move == *ptr) return true;
	}
	return false;
}

Score alpha_beta_rec(LinearGame *lg, AlphaBetaInfo abi){
	if(search_stopped) return 0;

	State *curr = &lg->states[lg->state_ptr];

	if(abi.current_depth >= abi.max_depth){
		nodes++;
		return eval_state(curr);
	}

	Move legal_moves[MAX_MOVES];	

	Move *last_legal = generate_legal(curr, legal_moves);

	if(last_legal == legal_moves){
		if(is_in_check(curr)){
			// mate
			return -MATE_SCORE + abi.current_depth;
		}

		// stalemate
		return 0;
	}

	PvEntry pv_entry = get_pv_entry(curr);

	MoveSortEntry sort_legal_moves[MAX_MOVES];

	MoveSortEntry *msptr = sort_legal_moves;

	Move *ptr;

	Bitboard king_bb_them = curr->by_figure[KING] & curr->by_color[1-curr->turn];
	Square king_sq_them = pop_square(&king_bb_them);	
	Bitboard king_attack_them = KING_ATTACK[king_sq_them];

	for(ptr = legal_moves; ptr < last_legal; ptr++){
		Move move = *ptr;

		Square from_sq = from_sq_of(move);
		Square to_sq = to_sq_of(move);

		Piece from_p = piece_at_square(curr, from_sq);
		Piece to_p = piece_at_square(curr, to_sq);
		
		Bitboard mob = mobility_for_piece_at_square(curr, from_p, to_sq, true, true);

		Score attack = pop_cnt(king_attack_them & mob);

		if(bitboard_of(king_sq_them) & mob) attack+= 3;

		attack += pop_cnt(mob & curr->by_color[1-curr->turn] & (curr->by_figure[QUEEN]||curr->by_figure[ROOK]));

		attack += pop_cnt(mob & curr->by_color[1-curr->turn]);		

		bool is_pv = false;

		if(pv_entry.ok){
			for(int i = 0; i < MAX_PV_MOVES; i++){
				if(pv_entry.moves[i]==move){
					is_pv=true;
					break;
				}
			}
		}

		*msptr++ = MoveSortEntry{
			move,
			is_pv,
			to_p,
			attack,
		};
	}

	MoveSortEntry *last_sorted_legal = msptr;

	qsort(sort_legal_moves, last_sorted_legal - sort_legal_moves, sizeof(MoveSortEntry), comp_sort_moves);

	Score alpha = abi.alpha;

	msptr = sort_legal_moves;

	while(msptr < last_sorted_legal){
		MoveSortEntry move_sort_entry = *msptr++;

		Move move = move_sort_entry.move;

		if(is_ignored_root_move(lg, move)) continue;

		push_state(lg);
		make_move(&lg->states[lg->state_ptr], move); 

		Depth max_depth = abi.max_depth;

		Score score = -alpha_beta_rec(lg, AlphaBetaInfo{
			(Score)(-abi.beta),
			(Score)(-alpha),
			(Depth)(abi.current_depth + 1),
			(Depth)(max_depth),
		});

		pop_state(lg);

		if(score > alpha){
			alpha = score;
			set_pv_entry(curr, move, abi.current_depth);						
			if(abi.current_depth == 0){
				root_move = move;
				has_root_move = true;
			}
		}

		if(score >= abi.beta){
			return abi.beta;
		}		
	}

	return alpha;
}

std::chrono::steady_clock::time_point begin;
std::chrono::steady_clock::time_point end;

std::string get_pv(LinearGame *lg, Depth max_depth){
	bool ok = true;
	State st = lg->states[lg->state_ptr];	
	std::string buff = "";
	bool root = true;
	do{
		PvEntry entry = get_pv_entry(&st);		
		if(root && (!has_root_move)){
			break;
		}
		if(root){
			entry.ok = true;
			entry.moves[0] = root_move;
			root = false;
		}		
		if(entry.ok){
			if(buff != "") buff += " ";
			buff += uci_of_move(entry.moves[0]);						
			make_move(&st, entry.moves[0]);
		}else{
			ok = false;
		}
		max_depth--;
	}while(ok && (max_depth > 0));	
	return buff;
}

bool mate_found;

const Depth DOUBLE_ITERATION_LIMIT = MAX_STATES;

void print_multipv_info_item(MultipvInfoItem *mi){
	std::cout << "info multipv " << (int)mi->index << " depth " << (int)mi->depth << " time " << mi->time << " ";
	BSPRINTF(nbuff, "%lld", mi->nodes);
	std::cout << "nodes " << nbuff << " nps " << mi->nps << " score cp " << (int)mi->score << " pv " << mi->pv << std::endl;	
}

void search_inner(LinearGame *lg, Depth depth){
	mate_found = false;

	Score last_score = 0;

	for(Depth iter_depth = 1; iter_depth <= depth; iter_depth++){		
		lg->last_ignored_root_move = lg->ignored_root_moves;
		lg->current_multipv.num_items = 0;
		for(int8_t multipv = 1; multipv <= lg->eff_multipv; multipv++){
			Score window_low = INFINITE_SCORE;
			Score window_high = INFINITE_SCORE;

			if(iter_depth > 4){
				window_low = 50;
				window_high = 50;
			}

			bool succ = false;		

			Score score;

			while(!succ){
				Score alpha = last_score - window_low;
				Score beta = last_score + window_high;

				score = alpha_beta_rec(lg, AlphaBetaInfo{
					alpha,
					beta,
					0,
					iter_depth
				});		

				if(search_stopped){
					break;
				}

				if(score == alpha){
					window_low *= 2;
				}else if(score == beta){
					window_high *= 2;
				}else{
					succ = true;
				}
			}

			last_score = score;

			if((score < -WIN_SCORE) || (score > WIN_SCORE)){
				mate_found = true;
			}

			end = std::chrono::steady_clock::now();			

			int ms = (int)std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() + 1;

			int nps = (int)(nodes / ms)*1000;

			bool print_pv = depth <= DOUBLE_ITERATION_LIMIT ? depth == iter_depth : iter_depth > DOUBLE_ITERATION_LIMIT;

			if(mate_found){
				print_pv = true;
			}

			if(print_pv){
				MultipvInfoItem* ci = &lg->current_multipv.items[multipv-1];

				ci->depth = depth;
				ci->time = ms;
				ci->nodes = nodes;
				ci->nps = nps;
				ci->score = score;
				ci->pv = get_pv(lg, iter_depth);

				has_finished_ponder_move = false;

				if(has_root_move){
					has_finished_root_move = true;
					finished_root_move = root_move;
					*lg->last_ignored_root_move++ = root_move;
					State st = lg->states[lg->state_ptr];					
					make_move(&st, finished_root_move);
					PvEntry entry = get_pv_entry(&st);
					if(entry.ok){
						has_finished_ponder_move = true;
						finished_ponder_move = entry.moves[0];
					}
				}

				lg->current_multipv.num_items = multipv;
			}

			if(search_stopped || mate_found){
				break;
			}
		}

		if(search_stopped || mate_found){
			break;
		}
	}	
}

void print_multipv(MultipvInfo* mi){
	for(int i=0;i<mi->num_items;i++){
		mi->items[i].index = i+1;
		print_multipv_info_item(&mi->items[i]);
	}
}

int comp_multipv(const void *m1, const void *m2){
	MultipvInfoItem mi1 = *((MultipvInfoItem*)m1);
	MultipvInfoItem mi2 = *((MultipvInfoItem*)m2);
	if(mi1.depth != mi2.depth){
		return mi1.depth > mi2.depth ? -1 : 1;
	}
	return mi2.score - mi1.score;
}

void sort_multipv(MultipvInfo* mi){
	if(mi->num_items<=0){
		return;
	}
	qsort(mi->items, mi->num_items, sizeof(MultipvInfoItem), comp_multipv);
}

void search(LinearGame *lg, Depth depth){
	nodes = 0;

	begin = std::chrono::steady_clock::now();	

	has_root_move = false;
	has_finished_root_move = false;
	has_finished_ponder_move = false;

	lg->last_good_multipv.num_items = 0;

	lg->eff_multipv = lg->multipv;

	Move check_legal_moves[MAX_MOVES];
	Move *last_legal = generate_legal(&lg->states[lg->state_ptr], check_legal_moves);

	if((last_legal - check_legal_moves) < lg->multipv){
		lg->eff_multipv = (int8_t)(last_legal - check_legal_moves);
	}

	if(lg->eff_multipv <= 0){
		std::cout << "info string no legal moves" << std::endl;
		std::cout << "bestmove (none)" << std::endl;
		return;
	}

	for(Depth iter_depth = 1; iter_depth <= depth; iter_depth++){
		if(iter_depth <= DOUBLE_ITERATION_LIMIT){
			search_inner(lg, iter_depth);
		}else{
			iter_depth = depth;
			search_inner(lg, depth);
		}
		sort_multipv(&lg->current_multipv);
		bool has_full_multipv = false;
		if(lg->current_multipv.num_items >= lg->eff_multipv){
			lg->last_good_multipv = lg->current_multipv;
			has_full_multipv = true;
		}
		if(has_full_multipv || mate_found){
			print_multipv(&lg->current_multipv);
		}
		if(search_stopped || mate_found) break;
	}

	MultipvInfo final_multipv_info = lg->last_good_multipv;

	if((final_multipv_info.num_items <= 0) || mate_found){
		final_multipv_info = lg->current_multipv;
	}

	has_finished_root_move = false;
	has_finished_ponder_move = false;

	std::string finished_root_move_uci = "";
	std::string finished_ponder_move_uci = "";

	if(final_multipv_info.num_items > 0){
		std::string final_pv = final_multipv_info.items[0].pv;

		std::string pv_moves[MAX_STATES];
        int num_pv_moves = split(final_pv, " ", pv_moves);

        if(num_pv_moves > 0){
        	has_finished_root_move = true;
        	finished_root_move_uci = pv_moves[0];
        }

        if(num_pv_moves > 1){
        	has_finished_ponder_move = true;
        	finished_ponder_move_uci = pv_moves[1];
        }
	}

	if(has_finished_root_move){
		std::cout << "bestmove " << finished_root_move_uci;	
		
		if(has_finished_ponder_move){
			std::cout << " ponder " << finished_ponder_move_uci << std::endl;
		}else{
			std::cout << std::endl;
		}
	}else{
		std::cout << "bestmove (none) " << std::endl;	
	}	

	search_stopped = true;
}
