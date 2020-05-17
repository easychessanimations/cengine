#ifndef ATTACK_HPP

#define ATTACK_HPP

#include <cstdint>

#include "bitboard.hpp"

extern Bitboard mask_to_partial_occup(PartialMask mask, Bitboard full_occup);

struct Delta {
	int8_t d_rank;
	int8_t d_file;
};

const Delta ROOK_DELTAS[5] = { Delta{1,0} , Delta{-1,0}, Delta{0,1}, Delta{0,-1} , Delta{0,0} };
const Delta BISHOP_DELTAS[5] = { Delta{1,1} , Delta{-1,1}, Delta{-1,1}, Delta{-1,-1} , Delta{0,0} };
const Delta QUEEN_DELTAS[9] = { Delta{1,0} , Delta{1,1} , Delta{0,1} , Delta{-1,1} , Delta{-1,0} , Delta{-1,-1} , Delta{0,-1} , Delta{1,-1} , Delta{0,0} };
const Delta KNIGHT_DELTAS[9] = { Delta{2,1} , Delta{2,-1} , Delta{-2,1} , Delta{-2,-1} , Delta{1,2} , Delta{1,-2} , Delta{-1,2} , Delta{-1,-2} , Delta{0,0} };

extern bool add_delta(Square *sq, Delta delta);

extern Bitboard sliding_attack(Square sq, Delta* deltas, Bitboard occup);

extern Bitboard jump_attack(Square sq, Delta* deltas);

#endif