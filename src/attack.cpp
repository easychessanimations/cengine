#include <stdlib.h>
#include <iostream>
#include <stdio.h>

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

Bitboard jump_attack(Square sq, Delta* deltas) {
	Bitboard bb = EMPTY_BB;

	while (deltas->d_rank | deltas->d_file) {
		Square current_sq = sq;		
		if (add_delta(&current_sq, *deltas)) {
			bb |= bitboard_of(current_sq);			
		}
		deltas++;
	}

	return bb;
}

int magic_key(Magic magic, int shift, Bitboard occup) {
	return (int)((magic * occup) >> (BB_SIZE_IN_BITS - shift));
}

Bitboard magic_mobility(Square sq, Bitboard mobility) {
	Rank rank = rank_of(sq);
	File file = file_of(sq);

	Bitboard mask = MIDDLE_BB;

	if(rank == 0) {
		mask |= RANK_1_MIDDLE_BB;
	}
	if(rank == LAST_RANK){
		mask |= RANK_8_MIDDLE_BB;
	}
	if(file == 0) {
		mask |= FILE_A_MIDDLE_BB;
	}
	if(file == LAST_FILE){
		mask |= FILE_H_MIDDLE_BB;
	}

	return mobility & mask;
}

Bitboard magic_attack(Square sq, Delta* deltas, Bitboard occup) {
	return magic_mobility(sq, sliding_attack(sq, deltas, occup));
}

CheckMagicAndShift check_magic_and_shift_cache[1 << MAX_MAGIC_SHIFT];

bool check_magic_and_shift(Square sq, Delta *deltas, Magic magic, int shift) {
	Bitboard mobility = magic_attack(sq, deltas, EMPTY_BB);

	for (int i = 0; i < (1 << shift); i++) {
		check_magic_and_shift_cache[i] = CheckMagicAndShift{ false, EMPTY_BB };
	}
	PartialMask mask = 0;
	while (mask < variation_count(mobility)) {
		Bitboard partial_occup = mask_to_partial_occup(mask, mobility);
		Bitboard partial_mobility = magic_attack(sq, deltas, partial_occup);
		int key = magic_key(magic, shift, partial_occup);
		CheckMagicAndShift item = check_magic_and_shift_cache[key];
		if (item.used) {
			if (item.mobility != partial_mobility) {
				return false;
			}
		} else {
			check_magic_and_shift_cache[key] = CheckMagicAndShift{ true, partial_mobility };
		}
		mask++;
	}
	return true;
}

Magic gen_magic() {
	Magic m = 0;
	for (int i = 0; i < 8; i++) {
		m |= (((Magic)rand() & 0xff) << (i*8));
	}
	return m;
}

Magic find_magic_for_shift(Square sq, Delta* deltas, int shift, int max_tries) {
	while (max_tries) {
		Magic magic = gen_magic();		
		if (check_magic_and_shift(sq, deltas, magic, shift)) {
			return magic;
		}
		max_tries--;
	}
	return 0;
}

MagicAndShift find_magic_and_shift(Square sq, Delta* deltas, int max_shift, int min_shift, int max_tries) {
	MagicAndShift last_good_magic_and_shift = MagicAndShift{ 0,0 };
	for (int shift = max_shift; shift >= min_shift; shift--) {
		Magic m = find_magic_for_shift(sq, deltas, shift, max_tries);
		if (m) {
			last_good_magic_and_shift = MagicAndShift{ m, shift };
		}
	}
	return last_good_magic_and_shift;
}

int total_space;

bool VERBOSE = false;

bool find_magics(std::string label, Delta* deltas, MagicAndShift *store) {
	if(VERBOSE) std::cout << "finding magics for " << label << std::endl;	
	for (Square sq = 0; sq < BOARD_AREA; sq++) {
		if (VERBOSE) std::cout << "\nfinding magics for square " << uci_of_square(sq) << std::endl;
		Bitboard ma = magic_attack(sq, deltas, EMPTY_BB);
		if (VERBOSE) std::cout << pretty_bitboard(ma) << std::endl;
		int min_shift = pop_cnt(ma);
		MagicAndShift ms = find_magic_and_shift(sq, deltas, MAX_MAGIC_SHIFT, min_shift + 4, 5);
		if (!ms.magic) {
			if (VERBOSE) std::cout << "finding magics for " << label << " failed" << std::endl;
			return false;
		}		
		total_space += (1 << ms.shift);
		if (VERBOSE) std::cout << "found magic with shift " << ms.shift << " against min shift " << min_shift << " total space " << total_space << std::endl;
		char puff[20];
		sprintf(puff, "0x%016llx", ms.magic);
		if (VERBOSE) std::cout << "magic for " << label << " square " << uci_of_square(sq) << " magic " << puff << " shift " << ms.shift << std::endl;
		store[sq] = ms;
	}
	if (VERBOSE) std::cout << "\nfinding magics for " << label << " done" << std::endl;
	return true;
}

MagicAndShift BISHOP_MAGICS[BOARD_AREA];
MagicAndShift ROOK_MAGICS[BOARD_AREA];

bool init_attacks() {
	total_space = 0;
	if (!find_magics("bishop", (Delta*)BISHOP_DELTAS, BISHOP_MAGICS)) {
		std::cout << "init attacks failed" << std::endl;
		return false;
	}
	if (!find_magics("rook", (Delta*)ROOK_DELTAS, ROOK_MAGICS)) {
		std::cout << "init attacks failed" << std::endl;
		return false;
	}
	std::cout << "\ninit attacks done total space " << total_space << std::endl;
	return true;
}
