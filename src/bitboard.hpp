
#include "square.hpp"

#ifndef BITBOARD_HPP

#define BITBOARD_HPP

#include <cstdint>

typedef uint64_t Bitboard;

const unsigned long BB_SIZE_IN_BITS = 64;
const unsigned long HALF_BB_SIZE_IN_BITS = BB_SIZE_IN_BITS / 2;

const Bitboard BITBOARD_ONE  = 0x0000000000000001;
const Bitboard LOWER_HALF_BB = 0x00000000ffffffff;
const Bitboard RANK_1_BB     = 0x00000000000000ff;
const Bitboard RANK_8_BB     = 0xff00000000000000;
const Bitboard FILE_A_BB     = 0x8080808080808080;
const Bitboard FILE_H_BB     = 0x0101010101010101;
const Bitboard FULL_BB       = 0xffffffffffffffff;

extern std::string pretty_bitboard(Bitboard bb);

struct SquareBitboard{
	Square sq;
	Bitboard bb;
};

extern SquareBitboard SQUARE_BITBOARDS[BOARD_AREA];
extern void init_bitboards();

extern unsigned long lsb(Bitboard bb);

inline SquareBitboard pop_square_bitboard(Bitboard *bb){
	long i = lsb(*bb);	
	*bb &= ~(BITBOARD_ONE<<i);	
	return SQUARE_BITBOARDS[i];
}

#endif
