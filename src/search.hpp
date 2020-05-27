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

const int MAX_PV_MOVES = 9;
const int MAX_KILLER_MOVES = 3;

struct PvEntry{
	Depth depth;
	Move moves[MAX_PV_MOVES];
	Magic key;
	bool ok;
};

struct PosMoveEntry{
	Magic key;
	Move move;
	Depth depth;
	long long tree_size;	
	bool ok;
};

struct MoveSortEntry{
	Move move;
	uint8_t pv_index;
	Score capture;
	uint8_t killer_index;
	Score attack;
	Figure moved_figure;
	long long tree_size;
};

extern void search(LinearGame *lg, GoParams go_params);

extern void set_pv_entry(State *st, Move move, Depth depth);

extern bool search_stopped;

extern bool stop_on_mate;

#endif
