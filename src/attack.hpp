#ifndef ATTACK_HPP

#define ATTACK_HPP

#include <cstdint>

#include "bitboard.hpp"
#include "square.hpp"

extern Bitboard mask_to_partial_occup(PartialMask mask, Bitboard full_occup);

struct Delta {
	int8_t d_rank;
	int8_t d_file;
};

const Delta ROOK_DELTAS[5] = { Delta{1,0} , Delta{-1,0}, Delta{0,1}, Delta{0,-1} , Delta{0,0} };
const Delta BISHOP_DELTAS[5] = { Delta{1,1} , Delta{-1,1}, Delta{1,-1}, Delta{-1,-1} , Delta{0,0} };
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

extern bool check_magic_and_shift(Square sq, Delta *deltas, Magic magic, int shift);

extern Magic gen_magic();

extern Magic find_magic_for_shift(Square sq, Delta* deltas, int shift, int max_tries);

struct MagicAndShift {
	Magic magic;
	int shift;
	Bitboard* lookup;
};

extern MagicAndShift find_magic_and_shift(Square sq, Delta* deltas, int max_shift, int min_shift, int max_tries);

extern MagicAndShift BISHOP_MAGICS[BOARD_AREA];
extern MagicAndShift ROOK_MAGICS[BOARD_AREA];

extern bool find_magics(std::string label, Delta* deltas, MagicAndShift *store);

extern bool init_attacks();

typedef uint32_t Move;

const uint8_t SQUARE_STORAGE_SIZE_IN_BITS = 6;
const Move SQUARE_MASK = (1 << SQUARE_STORAGE_SIZE_IN_BITS) - 1;
const uint8_t TO_SQUARE_SHIFT = SQUARE_STORAGE_SIZE_IN_BITS;

inline Move move_ft(Square from_sq, Square to_sq) {
	return Move(from_sq) + ( Move(to_sq) << TO_SQUARE_SHIFT );
}

inline Square from_sq_of(Move move) {
	return move & SQUARE_MASK;
}

inline Square to_sq_of(Move move) {
	return (move >> TO_SQUARE_SHIFT) & SQUARE_MASK;
}

struct PawnInfo {
	Move pushes[2];
	int num_pushes;
	Move captures[2];
	int num_captures;
};

extern PawnInfo PAWN_INFOS[2][BOARD_AREA];

extern Bitboard BISHOP_ATTACK[BOARD_AREA];
extern Bitboard BISHOP_MAGIC_ATTACK[BOARD_AREA];
extern Bitboard ROOK_ATTACK[BOARD_AREA];
extern Bitboard ROOK_MAGIC_ATTACK[BOARD_AREA];
extern Bitboard QUEEN_ATTACK[BOARD_AREA];
extern Bitboard KNIGHT_ATTACK[BOARD_AREA];
extern Bitboard KING_ATTACK[BOARD_AREA];

extern Bitboard bishop_mobility(Square sq, Bitboard occup_us, Bitboard occup_them, bool violent, bool quiet);
extern Bitboard rook_mobility(Square sq, Bitboard occup_us, Bitboard occup_them, bool violent, bool quiet);
extern Bitboard queen_mobility(Square sq, Bitboard occup_us, Bitboard occup_them, bool violent, bool quiet);
extern Bitboard knight_mobility(Square sq, Bitboard occup_us, Bitboard occup_them, bool violent, bool quiet);
extern Bitboard king_mobility(Square sq, Bitboard occup_us, Bitboard occup_them, bool violent, bool quiet);

#endif
