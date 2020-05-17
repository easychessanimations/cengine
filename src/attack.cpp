#include "attack.hpp"
#include "square.hpp"
#include "bitboard.hpp"

Bitboard mask_to_partial_occup(PartialMask mask, Bitboard full_occup) {
	Bitboard bb = EMPTY_BB;

	while (mask && full_occup) {
		Bitboard occup_bit = pop_bitboard(&full_occup);

		if(mask & 1){
			bb |= occup_bit;
		}		

		mask >>= 1;
	}

	return bb;
}

bool add_delta(Square *sq, Delta delta) {
	Rank new_rank = rank_of(*sq) + delta.d_rank;
	File new_file = file_of(*sq) + delta.d_file;
	if ((new_rank >= 0) && (new_rank < NUM_RANKS) && (new_file >= 0) && (new_file < NUM_FILES)) {
		*sq = rank_file(new_rank, new_file);
		return true;
	}
	return false;
}

Bitboard sliding_attack(Square sq, Delta* deltas, Bitboard occup) {
	Bitboard bb = EMPTY_BB;

	while (deltas->d_rank | deltas->d_file) {
		Square current_sq = sq;
		bool ok = true;
		while (ok && add_delta(&current_sq, *deltas)) {
			bb |= bitboard_of(current_sq);
			ok = !(occup & bitboard_of(current_sq));
		}
		deltas++;
	}

	return bb;
}
