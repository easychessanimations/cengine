#ifndef STATE_HPP

#define STATE_HPP

#include <string>

#include "piece.hpp"
#include "square.hpp"
#include "bitboard.hpp"

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

extern std::string pretty_state(State st);

#endif