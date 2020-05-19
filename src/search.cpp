#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <chrono>
#include <algorithm>
#include <cctype>
#include <string>

#include "main.hpp"
#include "state.hpp"
#include "attack.hpp"
#include "search.hpp"

Score alpha_beta_rec(LinearGame *lg, AlphaBetaInfo abi){
	State *curr = &lg->states[lg->state_ptr];

	if(abi.current_depth == abi.max_depth){
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

	Move *ptr = legal_moves;

	Score alpha = abi.alpha;

	while(ptr < last_legal){
		Move move = *ptr++;

		push_state(lg);
		make_move(&lg->states[lg->state_ptr], move); 

		Score score = -alpha_beta_rec(lg, AlphaBetaInfo{
			(Score)(-abi.beta),
			(Score)(-abi.alpha),
			(Depth)(abi.current_depth + 1),
			(Depth)(abi.max_depth),
		});

		pop_state(lg);

		if(score > alpha){
			alpha = score;
			if(abi.current_depth == 0){
				std::cout << "info string alpha improved by " << uci_of_move(move) << " to " << (int)alpha << std::endl;
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

void search(LinearGame *lg, Depth depth){
	std::cout << "info string search to depth " << (int)depth << std::endl << std::endl;

	nodes = 0;

	begin = std::chrono::steady_clock::now();	

	Score score = alpha_beta_rec(lg, AlphaBetaInfo{
		-INFINITE_SCORE,
		INFINITE_SCORE,
		0,
		depth
	});

	end = std::chrono::steady_clock::now();

	BSPRINTF(nbuff, "%lld", nodes);
	
	std::cout << "info time " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << " ";
	std::cout << "nodes " << nbuff << std::endl;

	std::cout << "bestmove (none)" << std::endl;
}
