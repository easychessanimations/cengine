#include <string>
#include <stdio.h>

#include "bitboard.hpp"
#include "square.hpp"

#ifndef WASM

#include <intrin.h>
#pragma intrinsic(_BitScanForward)
unsigned long index;
inline unsigned long lsb(Bitboard bb) {	
	if ((bb & LOWER_HALF_BB) != 0) {
		_BitScanForward(&index, (unsigned long)(bb & LOWER_HALF_BB));
		return index;
	}
	_BitScanForward(&index, (unsigned long)(bb>>HALF_BB_SIZE_IN_BITS));
	return index + HALF_BB_SIZE_IN_BITS;
}

#else

inline unsigned long lsb(Bitboard bb) {	
	if ((bb & LOWER_HALF_BB) != 0) {
		return __builtin_ctz((unsigned int)(bb & LOWER_HALF_BB));
	}
	return __builtin_ctz((unsigned int)(bb >> HALF_BB_SIZE_IN_BITS)) + HALF_BB_SIZE_IN_BITS;
}

#endif

SquareBitboard SQUARE_BITBOARDS[BOARD_AREA];

Bitboard rank_file_to_bitboard(Rank rank, File file) {
	return BITBOARD_ONE << (rank * NUM_FILES + (LAST_FILE - file));
}

void init_bitboards() {	
	for (Rank rank = 0; rank < NUM_RANKS; rank++) {
		for (File file = 0; file < NUM_FILES; file++) {
			Bitboard bb = rank_file_to_bitboard(rank, file);
			SQUARE_BITBOARDS[lsb(bb)] = SquareBitboard{ rank_file(rank, file), bb };
		}
	}
}

std::string pretty_bitboard(Bitboard bb) {
	char puff[50];
	sprintf(puff, "bitboard 0x%016llx\n", bb);
	std::string buff = puff;

	for (Rank rank = LAST_RANK; rank >= 0; rank--) {
		for (File file = 0; file < NUM_FILES; file++) {
			if (file == 0) {
				buff += RANK_NAMES[LAST_RANK - rank] + " ";
			}
			if ((bb & rank_file_to_bitboard(rank, file)) == 0) {
				buff += "0";
			} else {
				buff += "1";
			}
			if (file == LAST_FILE) {
				buff += " "  + RANK_NAMES[LAST_RANK - rank];
			}
		}
		buff += "\n";
	}
	buff += "  abcdefgh\n";
	return buff;
}
