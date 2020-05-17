
#include "square.hpp"

#ifndef BITBOARD_HPP

#define BITBOARD_HPP

#include <cstdint>

typedef uint64_t Bitboard;

const unsigned long BB_SIZE_IN_BITS = 64;
const unsigned long HALF_BB_SIZE_IN_BITS = BB_SIZE_IN_BITS / 2;

const Bitboard BITBOARD_ONE     = 0x0000000000000001;
const Bitboard FULL_BB          = 0xffffffffffffffff;
const Bitboard EMPTY_BB         = 0x0000000000000000;
const Bitboard UPPER_HALF_BB    = 0xffffffff00000000;
const Bitboard LOWER_HALF_BB    = 0x00000000ffffffff;
const Bitboard RANK_1_BB        = 0x00000000000000ff;
const Bitboard RANK_8_BB        = 0xff00000000000000;
const Bitboard FILE_A_BB        = 0x0101010101010101;
const Bitboard FILE_H_BB        = 0x8080808080808080;
const Bitboard RANK_1_MIDDLE_BB = 0x000000000000007E;
const Bitboard RANK_8_MIDDLE_BB = 0x7E00000000000000;
const Bitboard FILE_A_MIDDLE_BB = 0x0080808080808000;
const Bitboard FILE_H_MIDDLE_BB = 0x0001010101010100;
const Bitboard MIDDLE_BB        = (~FILE_A_BB) & (~FILE_H_BB) & (~RANK_1_BB) & (~RANK_8_BB);

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
	_BitScanForward(&index, (unsigned long)(bb >> HALF_BB_SIZE_IN_BITS));
	return Square(index + HALF_BB_SIZE_IN_BITS);
}

inline uint8_t pop_cnt(Bitboard bb){
	return __popcnt(bb & LOWER_HALF_BB) + __popcnt(bb >> HALF_BB_SIZE_IN_BITS);	
}

#else

inline Square square_of(Bitboard bb) {	
	return Square(__builtin_ctzll(bb));
}

inline uint8_t pop_cnt(Bitboard bb){
	return __builtin_popcountll(bb);
}

#endif

inline Square pop_square(Bitboard *bb){
	return square_of(pop_bitboard(bb));
}

inline Bitboard bitboard_of(Square sq){
	return BITBOARD_ONE << sq;
}

typedef uint16_t PartialMask;

inline PartialMask variation_count(Bitboard bb){
	return 1 << pop_cnt(bb);
}

#endif
