#include <string>

#include "bitboard.hpp"
#include "square.hpp"

std::string pretty_bitboard(Bitboard bb) {
	std::string buff = "";

	Bitboard one = 1;

	for (Rank rank = 0; rank < NUM_RANKS; rank++) {
		for (File file = 0; file < NUM_FILES; file++) {
			if ((bb & (one << ((LAST_RANK-rank) * NUM_FILES + (LAST_FILE - file)))) == 0) {
				buff += "0";
			} else {
				buff += "1";
			}
		}
		buff += "\n";
	}
	return buff;
}
