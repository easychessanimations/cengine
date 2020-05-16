#include <string>
#include <stdio.h>

#include "bitboard.hpp"
#include "square.hpp"

#ifndef WASM

#include <intrin.h>
#pragma intrinsic(_BitScanForward)
unsigned long index;
inline long lsb(Bitboard bb) {
	if (bb == 0) {
		return 0;
	}		
	if ((bb & 0xffffffff) != 0) {
		_BitScanForward(&index, (unsigned long)(bb & 0xffffffff));
		return index;
	}
	_BitScanForward(&index, (unsigned long)(bb>>32));
	return index + 32;
}

#else

inline long lsb(Bitboard bb) {
	if (bb == 0) {
		return 0;
	}
	if ((bb & 0xffffffff) != 0) {
		return __builtin_ctz((unsigned int)(bb & 0xffffffff));
	}
	return __builtin_ctz((unsigned int)(bb >> 32)) + 32;
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
