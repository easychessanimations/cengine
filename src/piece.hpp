
#ifndef PIECE_HPP

#define PIECE_HPP

typedef unsigned char Figure;

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

const std::string FIGURE_SYMBOLS[FIGURE_ARRAY_SIZE] = { "." , "p" , "n" , "b" , "r" , "q" , "k" , "l" , "ln" , "lne" , "le" , "lse" , "ls" , "lsw" , "lw" , "lnw" , "s" , "j" };

extern std::string figure_symbol(Figure fig);

#endif
