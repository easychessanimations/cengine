#ifndef SEARCH_HPP

#define SEARCH_HPP

#include <cstdint>

#include "state.hpp"
#include "attack.hpp"

struct AlphaBetaInfo{
	Score alpha;
	Score beta;
	Depth current_depth;
	Depth max_depth;
};

struct PvEntry{
	Depth depth;
	Move move;
	Magic key;
	bool ok;
};

extern void search(LinearGame *lg, Depth depth);

extern void set_pv_entry(State *st, Move move, Depth depth);

#endif
