
#include "square.hpp"

#ifndef BITBOARD_HPP

#define BITBOARD_HPP

#include <cstdint>

typedef uint64_t Bitboard;

const unsigned long BB_SIZE_IN_BITS = 64;
const unsigned long HALF_BB_SIZE_IN_BITS = BB_SIZE_IN_BITS / 2;

const Bitboard BITBOARD_ONE  = 0x0000000000000001;
const Bitboard FULL_BB       = 0xffffffffffffffff;
const Bitboard EMPTY_BB      = 0x0000000000000000;
const Bitboard UPPER_HALF_BB = 0xffffffff00000000;
const Bitboard LOWER_HALF_BB = 0x00000000ffffffff;
const Bitboard RANK_1_BB     = 0x00000000000000ff;
const Bitboard RANK_8_BB     = 0xff00000000000000;
const Bitboard FILE_A_BB     = 0x0101010101010101;
const Bitboard FILE_H_BB     = 0x8080808080808080;

extern std::string pretty_bitboard(Bitboard bb);

extern void init_bitboards();

inline Bitboard pop_bitboard(Bitboard *bb){
	// get the Bitboard with LSB set
	Bitboard pop = (*bb) & -(int64_t)(*bb);
	// remove from original bitboard
	*bb -= pop;
	return pop;
}

#ifndef WASM

#include <intrin.h>
#pragma intrinsic(_BitScanForward)
inline Square square_of(Bitboard bb) {	
	unsigned long index;
	if ((bb & LOWER_HALF_BB) != 0) {
		_BitScanForward(&index, (unsigned long)(bb & LOWER_HALF_BB));
		return (Square)index;
	}
	_BitScanForward(&index, (unsigned long)(bb>>HALF_BB_SIZE_IN_BITS));
	return Square(index + HALF_BB_SIZE_IN_BITS);
}

#else

inline Square square_of(Bitboard bb) {	
	if ((bb & LOWER_HALF_BB) != 0) {
		return Square(__builtin_ctz((unsigned int)(bb & LOWER_HALF_BB)));
	}
	return Square(__builtin_ctz((unsigned int)(bb >> HALF_BB_SIZE_IN_BITS)) + HALF_BB_SIZE_IN_BITS);
}

#endif

inline Square pop_square(Bitboard *bb){
	return square_of(pop_bitboard(bb));
}

#endif
