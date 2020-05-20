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

	Move sorted_legal[MAX_MOVES];

	PvEntry pv_entry = get_pv_entry(curr);

	Move *ptr = legal_moves;

	if(pv_entry.ok){
		sorted_legal[0] = pv_entry.move;
		Move *sptr = sorted_legal + 1;
		for(Move *cptr = legal_moves; cptr < last_legal; cptr++){
			if(*cptr != pv_entry.move){
				*sptr++ = *cptr;
			}
		}

		ptr = sorted_legal;
		last_legal = sptr;
	}

	Score alpha = abi.alpha;

	while(ptr < last_legal){
		Move move = *ptr++;

		push_state(lg);
		make_move(&lg->states[lg->state_ptr], move); 

		Depth max_depth = abi.max_depth;

		if(pv_entry.ok && ((ptr - sorted_legal) > 1 )){
			max_depth = max_depth - 1;
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

void search(LinearGame *lg, Depth depth){
	std::cout << "info string search to depth " << (int)depth << std::endl << std::endl;

	nodes = 0;

	begin = std::chrono::steady_clock::now();	

	bool ok = true;

	for(Depth iter_depth = 1; (iter_depth <= depth) && ok; iter_depth++){		
		Score score = alpha_beta_rec(lg, AlphaBetaInfo{
			-INFINITE_SCORE,
			INFINITE_SCORE,
			0,
			iter_depth
		});

		end = std::chrono::steady_clock::now();

		BSPRINTF(nbuff, "%lld", nodes);

		int ms = (int)std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() + 1;

		int nps = (int)(nodes / ms)*1000;
		
		std::cout << "info depth " << (int)iter_depth << " time " << ms << " ";
		std::cout << "nodes " << nbuff << " nps " << nps << " score " << (int)score << " pv " << get_pv(lg, iter_depth) << std::endl;

		if((score < -9000) || (score > 9000)){
			ok = false;
		}
	}	

	PvEntry root_entry = get_pv_entry(&lg->states[lg->state_ptr]);

	std::cout << "bestmove " << uci_of_move(root_entry.move) << std::endl;
}
