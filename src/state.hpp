#ifndef STATE_HPP

#define STATE_HPP

#include <string>

#include "piece.hpp"
#include "square.hpp"
#include "bitboard.hpp"
#include "attack.hpp"

extern int split(std::string str, std::string delim, std::string *buff);

struct State {
	bool state_ok;
	Piece rep[BOARD_AREA];
	Color turn;
	Bitboard by_color[2];
	Bitboard by_figure[FIGURE_ARRAY_SIZE];
};

extern State state_from_fen(std::string fen);

extern Piece fen_symbol_to_piece(std::string fen_symbol);

const int MAX_MOVES = 500;

extern Move sorted_move_buff[MAX_MOVES];
extern Move* sorted_moves(State *st);

extern std::string pretty_state(State *st);

extern Move* generate_pseudo_legal(State *st, Move* move_buff);

extern void make_move(State *st, Move move);

const int MAX_STATES = 100;

struct LinearGame {
	State states[MAX_STATES];
	int state_ptr;
};

extern void push_state(LinearGame *lg);

extern void perft(LinearGame* lg, int depth);

#endif