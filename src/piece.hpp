
#ifndef PIECE_HPP

#define PIECE_HPP

#include <cstdint>

typedef uint8_t Figure;

const Figure NO_FIGURE = 0;
const Figure PAWN = 1;
const Figure KNIGHT = 2;
const Figure BISHOP = 3;
const Figure ROOK = 4;
const Figure QUEEN = 5;
const Figure KING = 6;
const Figure LANCER = 7;
const Figure LANCER_N = 8;
const Figure LANCER_NE = 9;
const Figure LANCER_E = 10;
const Figure LANCER_SE = 11;
const Figure LANCER_S = 12;
const Figure LANCER_SW = 13;
const Figure LANCER_W = 14;
const Figure LANCER_NW = 15;
const Figure SENTRY = 16;
const Figure JAILER = 17;

const int FIGURE_ARRAY_SIZE = 18;

const int PIECE_ARRAY_SIZE = 2 * FIGURE_ARRAY_SIZE;

const std::string FIGURE_SYMBOLS[FIGURE_ARRAY_SIZE] = { "." , "p" , "n" , "b" , "r" , "q" , "k" , "l" , "ln" , "lne" , "le" , "lse" , "ls" , "lsw" , "lw" , "lnw" , "s" , "j" };

extern std::string figure_symbol(Figure fig);

typedef uint8_t Color;

const Color BLACK = 0;
const Color WHITE = 1;

typedef uint8_t Piece;

const Piece NO_PIECE = 0;

inline Piece color_figure(Color col, Figure fig){
	return (fig << 1) + col;
}

inline Color color_of(Piece p) {
	return p & 1;
}

inline Color figure_of(Piece p) {
	return p >> 1;
}

extern std::string fen_symbol_of(Piece p);

extern std::string san_symbol_of(Piece p);

extern std::string uci_symbol_of(Piece p);

extern std::string san_letter_of(Piece p);

#endif
