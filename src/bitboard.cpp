#include <string>
#include <stdio.h>

#include "bitboard.hpp"
#include "square.hpp"

std::string pretty_bitboard(Bitboard bb) {
	char puff[50];
	sprintf(puff, "bitboard 0x%016llx\n", bb);
	std::string buff = puff;

	Bitboard one = 1;

	for (Rank rank = 0; rank < NUM_RANKS; rank++) {
		for (File file = 0; file < NUM_FILES; file++) {
			if (file == 0) {
				buff += RANK_NAMES[LAST_RANK - rank] + " ";
			}
			if ((bb & (one << ((LAST_RANK-rank) * NUM_FILES + (LAST_FILE - file)))) == 0) {
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
