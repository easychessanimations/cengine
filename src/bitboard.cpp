#include <string>
#include <stdio.h>

#include "bitboard.hpp"
#include "square.hpp"

Bitboard rank_file_to_bitboard(Rank rank, File file) {
	return BITBOARD_ONE << (rank * NUM_FILES + file);
}

void init_bitboards() {	
	for (Rank rank = 0; rank < NUM_RANKS; rank++) {
		for (File file = 0; file < NUM_FILES; file++) {
			
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
				buff += ".";
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
