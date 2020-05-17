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

typedef uint64_t Magic;

const int MAX_MAGIC_SHIFT = 17;

extern int magic_key(Magic magic, int shift, Bitboard occup);

struct CheckMagicAndShift {
	bool used;
	Bitboard mobility;
};

extern Bitboard magic_mobility(Square sq, Bitboard mobility);

extern Bitboard magic_attack(Square sq, Delta* deltas, Bitboard occup);

extern bool check_magic_and_shift(Square sq, Delta *deltas, Magic magic, int shift);

extern Magic gen_magic();

extern Magic find_magic_for_shift(Square sq, Delta* deltas, int shift, int max_tries);

struct MagicAndShift {
	Magic magic;
	int shift;
};

extern MagicAndShift find_magic_and_shift(Square sq, Delta* deltas, int max_shift, int min_shift, int max_tries);

extern MagicAndShift BISHOP_MAGICS[BOARD_AREA];
extern MagicAndShift ROOK_MAGICS[BOARD_AREA];

extern bool find_magics(std::string label, Delta* deltas, MagicAndShift *store);

extern bool init_attacks();
#endif
