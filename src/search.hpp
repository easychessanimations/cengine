#ifndef SEARCH_HPP

#define SEARCH_HPP

#include <cstdint>

#include "state.hpp"
#include "attack.hpp"
#include "uci.hpp"

struct AlphaBetaInfo{
	Score alpha;
	Score beta;
	Depth current_depth;
	Depth max_depth;
	bool null_move_done;
};

const int MAX_PV_MOVES = 8;

struct PvEntry{
	Depth depth;
	Move moves[MAX_PV_MOVES];
	Magic key;
	bool ok;
};

struct MoveSortEntry{
	Move move;
	uint8_t pv_index;
	Score capture;
	Score attack;
};

extern void search(LinearGame *lg, GoParams go_params);

extern void set_pv_entry(State *st, Move move, Depth depth);

extern bool search_stopped;

extern bool stop_on_mate;

#endif
