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

std::string to_lower(std::string data){
	std::transform(data.begin(), data.end(), data.begin(), [](unsigned char c){ return std::tolower(c); });
	return data;
}

Piece fen_symbol_to_piece(std::string fen_symbol) {
	for (Piece p = 0; p < PIECE_ARRAY_SIZE; p++) {
		if(fen_symbol_of(p) == fen_symbol){
			return p;
		}
	}
	return NO_PIECE;
}

Piece piece_at_square(State *st, Square sq) {
	return st->rep[sq];
}

void remove_piece_from_square(State *st, Square sq) {
	Piece p = piece_at_square(st, sq);
	if (p == NO_PIECE) {
		return;
	}
	Bitboard bb = bitboard_of(sq);
	Color col = color_of(p);
	Figure fig = figure_of(p);
	st->by_color[col] &= (~bb);
	st->by_figure[fig] &= (~bb);
	st->rep[sq] = NO_PIECE;
	st->hash_key ^= (~COLOR_FIGURE_KEYS[col][sq][fig]);
}

void put_piece_at_square(State* st, Piece p, Square sq) {
	if(p==NO_PIECE){
		return;
	}
	remove_piece_from_square(st, sq);	
	Bitboard bb = bitboard_of(sq);
	Color col = color_of(p);
	Figure fig = figure_of(p);
	st->by_color[col] |= bb;
	st->by_figure[fig] |= bb;
	st->rep[sq] = p;
	st->hash_key ^= COLOR_FIGURE_KEYS[col][sq][fig];
}

State state_from_fen(std::string fen) {
	State st = State{};

	memset(&st, 0, sizeof(State));

	if (fen == "") {
		fen = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";		
	}

	std::string parts[7];
	int num_parts = split(fen, " ", parts);

	std::string placement = parts[0];

	Rank rank = LAST_RANK;
	File file = 0;

	for (int i = 0; i < (int)placement.length(); i++) {
		std::string c = placement.substr(i, 1);

		Square sq = rank_file(rank, file);

		if ((c >= "1") && (c <= "8")) {
			for (int j = 0; j < (int)(c[0] - '0'); j++) {
				put_piece_at_square(&st, NO_PIECE, sq);
				file++;
				Square sq = rank_file(rank, file);
			}
		} else if (c == "/") {
			rank--;
			file = 0;
		} else {
			put_piece_at_square(&st, fen_symbol_to_piece(c), sq);
			file++;
		}
	}

	set_turn(&st, WHITE);

	if (num_parts > 1) {
		if (parts[1] == "b") {
			st.turn = BLACK;
		}
	}

	return st;
}

std::string move_to_san(State *st, Move move){
	Square from_sq = from_sq_of(move);
	Square to_sq = to_sq_of(move);
	Piece from_p = piece_at_square(st, from_sq);
	Piece to_p = piece_at_square(st, to_sq);
	std::string letter = "";
	if(figure_of(from_p)!=PAWN){
		letter = san_letter_of(from_p);
	}
	bool is_capture = to_p != NO_PIECE;
	std::string from_spec = figure_of(from_p) == PAWN ? ( is_capture ? uci_of_square(from_sq).substr(0,1) : "" ) : "";
	std::string takes = is_capture ? "x" : "";
	std::string to_spec = uci_of_square(to_sq);
	std::string check = "";
	State test_st = *st;
	make_move(&test_st, move);
	if(is_in_check(&test_st)){
		check = "+";
		Move test_buff[MAX_MOVES];
		Move* last_legal = generate_legal(&test_st, test_buff);
		if(last_legal == test_buff){
			check = "#";
		}
	}
	return letter + from_spec + takes + to_spec + check;
}

State *sorted_state;

int comp_moves(const void *m1, const void *m2){
	std::string san1 = to_lower(move_to_san(sorted_state, *((Move*)m1)));
	std::string san2 = to_lower(move_to_san(sorted_state, *((Move*)m2)));
	return san1 > san2 ? 1 : -1;
}

Move sorted_move_buff[MAX_MOVES];

Move *sorted_moves(State *st){
	Move* last_move = generate_legal(st, sorted_move_buff);

	sorted_state = st;
	qsort(sorted_move_buff, last_move - sorted_move_buff, sizeof(Move), comp_moves);

	return last_move;
}

std::string pretty_state(State *st) {
	std::string buff = "";
	for (Rank rank = LAST_RANK; rank >= 0; rank--) {		
		for (File file = 0; file < NUM_FILES; file++) {
			Square sq = rank_file(rank, file);
			if (file == 0) {
				buff += uci_of_square(sq).substr(1, 1) + " ";
			}
			buff += fen_symbol_of(piece_at_square(st, sq));
		}
		buff += "\n";
	}
	buff += "\n  abcdefgh\n";
	buff += "\nturn ";
	if (st->turn == WHITE) {
		buff += "w";
	}
	else {
		buff += "b";
	}	
	BSPRINTF(ebuff, "%d", (int)eval_state(st));
	buff += " ";
	buff += ebuff;
	buff += "\n";

	Move *last_move = sorted_moves(st);

	Move* ptr = sorted_move_buff;

	while (ptr < last_move) {
		if((ptr-sorted_move_buff) % 6 == 0) buff+="\n";
		BSPRINTF(ibuff, "%2d. ", (int)(ptr-sorted_move_buff+1))
		BSPRINTF(mbuff, "%-12s ", move_to_san(st, *ptr++).c_str())
		buff += ibuff;
		buff += mbuff;		
	}
	buff += "\n";

	return buff + "\n";
}

Bitboard mobility_for_piece_at_square(State *st, Piece p, Square sq, bool violent, bool quiet) {
	Color col = color_of(p);
	Figure fig = figure_of(p);
	Bitboard occup_us = st->by_color[col];
	Bitboard occup_them = st->by_color[1-col];
	switch (fig) {
	case BISHOP:
		return bishop_mobility(sq, occup_us, occup_them, violent, quiet);
	case ROOK:
		return rook_mobility(sq, occup_us, occup_them, violent, quiet);
	case QUEEN:
		return queen_mobility(sq, occup_us, occup_them, violent, quiet);
	case KNIGHT:
		return knight_mobility(sq, occup_us, occup_them, violent, quiet);
	case KING:
		return king_mobility(sq, occup_us, occup_them, violent, quiet);
	default:
		return EMPTY_BB;
	}	
}

Move* pseudo_legal_moves_for_piece_at_square(State *st, Piece p, Square sq, Move* move_buff, bool violent, bool quiet) {
	//std::cout << uci_of_square(sq) << " " << fen_symbol_of(p) << " " << std::endl;
	Figure fig = figure_of(p);
	Color col = color_of(p);
	if (fig == PAWN) {
		PawnInfo pi = PAWN_INFOS[col][sq];		
		if(quiet && (pi.num_pushes > 0) && (piece_at_square(st, to_sq_of(pi.pushes[0])) == NO_PIECE)) {
			*(move_buff++) = pi.pushes[0];
			if (pi.num_pushes > 1) {
				if (piece_at_square(st, to_sq_of(pi.pushes[1])) == NO_PIECE) {
					*(move_buff++) = pi.pushes[1];
				}
			}
		}
		if (violent) {
			for (int i = 0;i < pi.num_captures;i++) {
				Piece cp = piece_at_square(st, to_sq_of(pi.captures[i]));
				if( (cp != NO_PIECE) && (color_of(cp) == (1-col)) ) {
					*(move_buff++) = pi.captures[i];
				}
			}
		}
	} else {
		Bitboard mobility = mobility_for_piece_at_square(st, p, sq, violent, quiet);
		while (mobility) {
			Square to_sq = pop_square(&mobility);
			*(move_buff++) = move_ft(sq, to_sq);
		}
	}	
	return move_buff;
}

Move* pseudo_legal_moves_for_color(State *st, Move* move_buff, Color col, bool violent, bool quiet) {
	Bitboard us = st->by_color[col];
	Move* ptr = move_buff;
	while (us) {
		Square sq = pop_square(&us);
		Piece p = piece_at_square(st, sq);
		ptr = pseudo_legal_moves_for_piece_at_square(st, p, sq, ptr, violent, quiet);
	}
	return ptr;
}

Score mobility_and_attack(State *st, Score mobility_weight, Score attack_weight) {
	Score mob = 0;
	Score att = 0;
	for(Color col = BLACK; col <= WHITE; col++){
		Score dir = col ? 1 : -1;
		Bitboard us = st->by_color[col] & (~st->by_figure[PAWN]);		
		Bitboard king_them = st->by_color[1-col] & st->by_figure[KING];
		Bitboard king_sq_bb = king_them;
		Square king_sq = pop_square(&king_sq_bb);
		Bitboard king_attack_them = KING_ATTACK[king_sq];
		while (us) {
			Square sq = pop_square(&us);
			Figure fig = figure_of(piece_at_square(st, sq));
			Bitboard mob_bb = mobility_for_piece_at_square(st, color_figure(1-col, fig), sq, true, true);
			mob += dir * pop_cnt(mob_bb) * mobility_weight;			
			att += dir * pop_cnt(mob_bb && king_them) * attack_weight * 3;
			att += dir * pop_cnt(mob_bb && king_attack_them) * attack_weight;
		}
	}	
	return mob + att;
}

Move* pseudo_legal_moves_for_turn(State *st, Move* move_buff, bool violent, bool quiet) {
	return pseudo_legal_moves_for_color(st, move_buff, st->turn, violent, quiet);
}

Move* generate_pseudo_legal(State *st, Move* move_buff) {
	return pseudo_legal_moves_for_turn(st, move_buff, true, true);
}

void set_turn(State *st, Color col){
	st->hash_key ^= (~TURN_KEYS[st->turn]);
	st->hash_key ^= TURN_KEYS[col];
	st->turn = col;
}

void make_move(State* st, Move move) {
	Square from_sq = from_sq_of(move);
	Square to_sq = to_sq_of(move);
	Piece from_p = piece_at_square(st, from_sq);
	Piece to_p = piece_at_square(st, to_sq);
	remove_piece_from_square(st, from_sq);
	put_piece_at_square(st, from_p, to_sq);
	if(st->atomic){
		if(to_p != NO_PIECE){
			remove_piece_from_square(st, to_sq);
			Bitboard exp_bb = KING_ATTACK[to_sq];
			while(exp_bb){
				Square exp_sq = pop_square(&exp_bb);
				if(figure_of(piece_at_square(st, exp_sq)) != PAWN){
					remove_piece_from_square(st, exp_sq);
				}
			}
		}
	}
	set_turn(st, 1 - st->turn);
}

long long int nodes;

void push_state(LinearGame* lg) {
	lg->states[lg->state_ptr + 1] = lg->states[lg->state_ptr];
	lg->state_ptr++;
}

void pop_state(LinearGame* lg) {	
	lg->state_ptr--;
}

void perft_rec(LinearGame* lg, int current_depth, int max_depth) {		
	//std::cout << pretty_state(&lg->states[lg->state_ptr]);		
	if (current_depth == max_depth) {
		nodes++;
		return;
	}
	Move move_buff[200];
	State *curr = &lg->states[lg->state_ptr];
	Move* last = generate_legal(curr, move_buff);
	Move* ptr = move_buff;
	while (ptr < last) {
		push_state(lg);				
		make_move(&lg->states[lg->state_ptr], *ptr++); 
		long long int nodes_start = nodes;
		perft_rec(lg, current_depth + 1, max_depth);
		if(current_depth == 0) std::cout << uci_of_move(*(ptr-1)) << ": " << nodes - nodes_start << std::endl;
		pop_state(lg);
	}
}

void perft(LinearGame* lg, int depth) {
	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();	
	nodes = 0;
	lg->state_ptr = 0;

	perft_rec(lg, 0, depth);

	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	std::cout << std::endl << "time " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << " ms" << std::endl;
	BSPRINTF(nbuff, "%lld", nodes);
	std::cout << "nodes " << nbuff << std::endl;
}

Figure least_attacker_on_square_of_color(State *st, Square sq, Color col){
	PawnInfo pi = PAWN_INFOS[1-col][sq];
	for(int i=0;i<pi.num_captures;i++){
		Piece p = piece_at_square(st, to_sq_of(pi.captures[i]));
		if((figure_of(p)==PAWN) && (color_of(p) == col)) return PAWN;
	}
	for(Figure fig = KNIGHT; fig <= KING; fig++){
		Bitboard mob = mobility_for_piece_at_square(st, color_figure(1-col, fig), sq, true, false);
		Square test_sq;
		Piece test_p = color_figure(col, fig);
		while(mob){
			test_sq = pop_square(&mob);
			if(piece_at_square(st, test_sq) == test_p){
				return fig;
			}
		}
	}
	return NO_FIGURE;
}

bool is_in_check_color(State *st, Color col){
	if(st->atomic){
		if(kings_adjacent(st)){
			return false;
		}
	}

	Bitboard king_bb = st->by_color[col] & st->by_figure[KING];

	if(!king_bb){
		return true;
	}

	Square king_sq = pop_square(&king_bb);

	if(st->atomic){
		Bitboard king_them_bb = st->by_color[1-col] & st->by_figure[KING];
		if(!king_them_bb){
			return false;
		}
	}

	Figure least_attacker = least_attacker_on_square_of_color(st, king_sq, 1-col);

	return least_attacker != NO_FIGURE;
}

bool is_in_check(State *st){
	return is_in_check_color(st, st->turn);
}

Move pseudo_buff[MAX_MOVES];

Move* generate_legal(State *st, Move* move_buff){
	Move *last_move = generate_pseudo_legal(st, pseudo_buff);
	Move *lptr = move_buff;
	for(Move *ptr = pseudo_buff; ptr < last_move; ptr++){
		State test_st = *st;
		make_move(&test_st, *ptr);
		if(!is_in_check_color(&test_st, st->turn)){
			*lptr++ = *ptr;
		}
	}
	return lptr;
}

Score eval_state(State *st){
	Score mat = 0;

	for(Color col = BLACK; col <= WHITE; col++){
		Score dir = 2 * col - 1;

		Bitboard pawns = st->by_figure[PAWN] & st->by_color[col];
		mat += dir * 100 * pop_cnt(pawns);

		mat += dir * 25 * pop_cnt(pawns & CENTER_BB);

		Bitboard knights = st->by_figure[KNIGHT] & st->by_color[col];
		mat += dir * 300 * pop_cnt(knights);		

		Bitboard bishops = st->by_figure[BISHOP] & st->by_color[col];
		mat += dir * 300 * pop_cnt(bishops);

		Bitboard rooks = st->by_figure[ROOK] & st->by_color[col];
		mat += dir * 500 * pop_cnt(rooks);

		Bitboard queens = st->by_figure[QUEEN] & st->by_color[col];
		mat += dir * 900 * pop_cnt(queens);
	}

	mat += mobility_and_attack(st, 10, 25);

	mat += RANDOM_BONUS - 2 * ( ( RANDOM_BONUS * (Score)(gen_magic() & 0xff) ) / 0xff );

	return st->turn ? mat : -mat;
}

bool kings_adjacent(State *st){
	Bitboard wk_bb = st->by_figure[KING] & st->by_color[WHITE];	
	if(!wk_bb) return false;
	Bitboard bk_bb = st->by_figure[KING] & st->by_color[WHITE];
	if(!bk_bb) return false;
	Square wk_sq = pop_square(&wk_bb);
	Bitboard wk_attack = KING_ATTACK[wk_sq];
	return wk_attack & bk_bb;
}
