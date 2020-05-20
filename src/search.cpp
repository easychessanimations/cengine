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
const int PV_TABLE_KEY_SIZE_IN_BITS = 24;
#else
const int PV_TABLE_KEY_SIZE_IN_BITS = 18;
#endif

const Magic PV_TABLE_SIZE = (1<<PV_TABLE_KEY_SIZE_IN_BITS);
const Magic PV_TABLE_MASK = PV_TABLE_SIZE - 1;

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
	pv_table[key] = PvEntry{
		depth,
		move,
		st->hash_key,
		true,
	};
}

int comp_sort_moves(const void *vm1, const void *vm2){
	MoveSortEntry m1 = *((MoveSortEntry*)vm1);
	MoveSortEntry m2 = *((MoveSortEntry*)vm2);
	if(m1.is_pv && (!m2.is_pv)) return -1;
	if((!m1.is_pv) && m2.is_pv) return 1;
	if(m1.capture > m2.capture) return -1;
	return m1.attack > m2.attack ? -1 : 1;
}

Score alpha_beta_rec(LinearGame *lg, AlphaBetaInfo abi){
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
	Square king_sq = pop_square(&king_bb_them);
	Bitboard king_attack = KING_ATTACK[king_sq]	;

	for(ptr = legal_moves; ptr < last_legal; ptr++){
		Move move = *ptr;

		Square to_sq = to_sq_of(move);

		Bitboard to_bb = bitboard_of(to_sq);

		Score attack = to_bb & king_attack ? 1 : 0;

		if(to_sq == king_sq) attack += 3;

		*msptr++ = MoveSortEntry{
			move,
			pv_entry.ok && ( move == pv_entry.move ),
			piece_at_square(curr, to_sq),
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

		push_state(lg);
		make_move(&lg->states[lg->state_ptr], move); 

		Depth max_depth = abi.max_depth;

		if((msptr - sort_legal_moves)>4){
			max_depth--;
		}

		if((msptr - sort_legal_moves)>8){
			max_depth--;
		}

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
	do{
		PvEntry entry = get_pv_entry(&st);
		if(entry.ok){
			buff += uci_of_move(entry.move) + " ";						
			make_move(&st, entry.move);
		}else{
			ok = false;
		}
		max_depth--;
	}while(ok && (max_depth > 0));	
	return buff;
}

bool mate_found;

void search_inner(LinearGame *lg, Depth depth){
	std::cout << "info string search to depth " << (int)depth << std::endl << std::endl;

	nodes = 0;

	begin = std::chrono::steady_clock::now();	

	mate_found = false;

	Score last_score = 0;

	for(Depth iter_depth = 1; (iter_depth <= depth) && (!mate_found); iter_depth++){		
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

			if(score == alpha){
				window_low *= 2;
			}else if(score == beta){
				window_high *= 2;
			}else{
				succ = true;
			}
		}

		last_score = score;

		end = std::chrono::steady_clock::now();

		BSPRINTF(nbuff, "%lld", nodes);

		int ms = (int)std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() + 1;

		int nps = (int)(nodes / ms)*1000;
		
		std::cout << "info depth " << (int)iter_depth << " time " << ms << " ";
		std::cout << "nodes " << nbuff << " nps " << nps << " score " << (int)score << " pv " << get_pv(lg, iter_depth) << std::endl;

		if((score < -9000) || (score > 9000)){
			mate_found = true;
		}
	}	

	PvEntry root_entry = get_pv_entry(&lg->states[lg->state_ptr]);

	std::cout << "bestmove " << uci_of_move(root_entry.move) << std::endl;
}

void search(LinearGame *lg, Depth depth){
	for(Depth iter_depth = 1; iter_depth <= depth; iter_depth++){
		search_inner(lg, iter_depth);
		if(mate_found){
			return;
		}
	}
}
