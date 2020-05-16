#include <string>

#include "square.hpp"

std::string uci_of_square(Square sq) {
	return FILE_NAMES[file_of(sq)] + RANK_NAMES[rank_of(sq)];
}