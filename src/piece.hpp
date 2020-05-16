
#ifndef PIECE_HPP

#define PIECE_HPP

const int FIGURE_ARRAY_SIZE = 18;

const char NO_FIGURE = 0;
const char PAWN = 1;
const char KNIGHT = 2;
const char BISHOP = 3;
const char ROOK = 4;
const char QUEEN = 5;
const char KING = 6;
const char LANCER = 7;
const char LANCER_N = 8;
const char LANCER_NE = 9;
const char LANCER_E = 10;
const char LANCER_SE = 11;
const char LANCER_S = 12;
const char LANCER_SW = 13;
const char LANCER_W = 14;
const char LANCER_NW = 15;
const char SENTRY = 16;
const char JAILER = 17;

const std::string FIGURE_SYMBOLS[18] = { "." , "p" , "n" , "b" , "r" , "q" , "k" , "l" , "ln" , "lne" , "le" , "lse" , "ls" , "lsw" , "lw" , "lnw" , "s" , "j" };

extern inline std::string figure_symbol(char fig);

#endif
