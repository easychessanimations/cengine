#include "attack.hpp"

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
