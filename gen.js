const fs = require('fs')

const FIGURE_INFO =[
	[".", "no_figure"],
	["p", "pawn"],
	["n", "knight"],
	["b", "bishop"],
	["r", "rook"],
	["q", "queen"],
	["k", "king"],
	["l", "lancer"],
	["ln", "lancer_n"],
	["lne", "lancer_ne"],
	["le", "lancer_e"],
	["lse", "lancer_se"],
	["ls", "lancer_s"],
	["lsw", "lancer_sw"],
	["lw", "lancer_w"],
	["lnw", "lancer_nw"],
	["s", "sentry"],
	["j", "jailer"],
]

let piece_hpp = `
#ifndef PIECE_HPP

#define PIECE_HPP

#include <cstdint>

typedef uint8_t Figure;

${FIGURE_INFO.map((fi,i)=>`const Figure ${fi[1].toUpperCase()} = ${i};`).join("\n")}

const int FIGURE_ARRAY_SIZE = ${FIGURE_INFO.length};

const std::string FIGURE_SYMBOLS[FIGURE_ARRAY_SIZE] = { ${FIGURE_INFO.map(fi => '"' + fi[0] + '"').join(" , ")} };

extern std::string figure_symbol(Figure fig);

typedef uint8_t Color;

const Color BLACK = 0;
const Color WHITE = 1;

typedef uint8_t Piece;

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
`

fs.writeFileSync("src/piece.hpp", piece_hpp)

const RANK_NAMES = ["1","2","3","4","5","6","7","8"]
const FILE_NAMES = ["a","b","c","d","e","f","g","h"]

let squares = []

for(let rank=0;rank<RANK_NAMES.length;rank++){
	for(let file=0;file<FILE_NAMES.length;file++){
		squares.push(`const Square SQUARE_${FILE_NAMES[file].toUpperCase()}${RANK_NAMES[rank]} = ${rank*FILE_NAMES.length+file};`)
	}
}

let square_hpp = `
#ifndef SQUARE_HPP

#define SQUARE_HPP

#include <cstdint>

typedef int8_t Rank;
typedef int8_t File;

const uint8_t NUM_RANKS = ${RANK_NAMES.length};
const Rank LAST_RANK = NUM_RANKS - 1;
const uint8_t NUM_FILES = ${FILE_NAMES.length};
const File LAST_FILE = NUM_FILES - 1;
const uint8_t BOARD_AREA = NUM_RANKS * NUM_FILES;

const std::string RANK_NAMES[NUM_RANKS] = { ${RANK_NAMES.map(rn => '"' + rn + '"').join(" , ")} };
const std::string FILE_NAMES[NUM_FILES] = { ${FILE_NAMES.map(fn => '"' + fn + '"').join(" , ")} };

typedef uint8_t Square;

${squares.join("\n")}

const uint8_t FILE_SIZE_IN_BITS = 3;
const uint8_t FILE_MASK = (1 << FILE_SIZE_IN_BITS) - 1;

const uint8_t RANK_SIZE_IN_BITS = 3;
const uint8_t RANK_MASK = (1 << RANK_SIZE_IN_BITS) - 1;
const uint8_t RANK_SHIFT = FILE_SIZE_IN_BITS;

inline Rank rank_of(Square sq){
	return (sq >> RANK_SHIFT) & RANK_MASK;
}

inline Rank file_of(Square sq){
	return sq & FILE_MASK;
}

inline Square rank_file(Rank rank, File file){
	return rank * NUM_FILES + file;
}

extern std::string uci_of_square(Square sq);

#endif
`

fs.writeFileSync("src/square.hpp", square_hpp)

let bitboard_hpp = `
#include "square.hpp"

#ifndef BITBOARD_HPP

#define BITBOARD_HPP

#include <cstdint>

typedef uint64_t Bitboard;

const Bitboard BITBOARD_ONE = 0x0000000000000001;
const Bitboard RANK_1_BB    = 0x00000000000000ff;
const Bitboard RANK_8_BB    = 0xff00000000000000;
const Bitboard FILE_A_BB    = 0x8080808080808080;
const Bitboard FILE_H_BB    = 0x0101010101010101;
const Bitboard FULL_BB      = 0xffffffffffffffff;

extern std::string pretty_bitboard(Bitboard bb);

struct SquareBitboard{
	Square sq;
	Bitboard bb;
};

extern SquareBitboard SQUARE_BITBOARDS[BOARD_AREA];
extern void init_bitboards();

extern long lsb(Bitboard bb);

inline SquareBitboard pop_square_bitboard(Bitboard *bb){
	long i = lsb(*bb);	
	*bb &= ~(BITBOARD_ONE<<i);	
	return SQUARE_BITBOARDS[i];
}

#endif
`

fs.writeFileSync("src/bitboard.hpp", bitboard_hpp)
