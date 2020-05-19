#ifndef SEARCH_HPP

#define SEARCH_HPP

#include <cstdint>

#include "state.hpp"

struct AlphaBetaInfo{
	Score alpha;
	Score beta;
	Depth current_depth;
	Depth max_depth;
};

extern void search(LinearGame *lg, Depth depth);

#endif
