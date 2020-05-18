#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include "attack.hpp"
#include "square.hpp"
#include "bitboard.hpp"
#include "piece.hpp"

Bitboard BISHOP_ATTACK[BOARD_AREA];
Bitboard BISHOP_MAGIC_ATTACK[BOARD_AREA];
Bitboard ROOK_ATTACK[BOARD_AREA];
Bitboard ROOK_MAGIC_ATTACK[BOARD_AREA];
Bitboard QUEEN_ATTACK[BOARD_AREA];
Bitboard KNIGHT_ATTACK[BOARD_AREA];
Bitboard KING_ATTACK[BOARD_AREA];

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

CheckMagicAndShift check_magic_and_shift_cache[1 << MAX_MAGIC_SHIFT];

bool check_magic_and_shift(Square sq, Delta *deltas, Magic magic, int shift) {
	Bitboard mobility = magic_mobility(sq, sliding_attack(sq, deltas, EMPTY_BB));

	for (int i = 0; i < (1 << shift); i++) {
		check_magic_and_shift_cache[i] = CheckMagicAndShift{ false, EMPTY_BB };
	}
	PartialMask mask = 0;
	while (mask < variation_count(mobility)) {
		Bitboard partial_occup = mask_to_partial_occup(mask, mobility);
		Bitboard partial_mobility = magic_mobility(sq, sliding_attack(sq, deltas, partial_occup));
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
		Bitboard ma = magic_mobility(sq, sliding_attack(sq, deltas, EMPTY_BB));
		if (VERBOSE) std::cout << pretty_bitboard(ma) << std::endl;
		int min_shift = pop_cnt(ma);
		MagicAndShift ms = find_magic_and_shift(sq, deltas, MAX_MAGIC_SHIFT, min_shift + 4, 5);
		if (!ms.magic) {
			if (VERBOSE) std::cout << "finding magics for " << label << " failed" << std::endl;
			return false;
		}		
		total_space += (1 << ms.shift);
		if (VERBOSE) std::cout << "found magic with shift " << ms.shift << " against min shift " << min_shift << " total space " << total_space << std::endl;
		char puff[20]="";
		//sprintf(puff, "0x%016llx", ms.magic);
		if (VERBOSE) std::cout << "magic for " << label << " square " << uci_of_square(sq) << " magic " << puff << " shift " << ms.shift << std::endl;
		store[sq] = ms;
	}
	if (VERBOSE) std::cout << "\nfinding magics for " << label << " done" << std::endl;
	return true;
}

MagicAndShift BISHOP_MAGICS[BOARD_AREA];
MagicAndShift ROOK_MAGICS[BOARD_AREA];

void build_magics(MagicAndShift *magics, Delta *deltas) {
	for (Square sq = 0; sq < BOARD_AREA; sq++) {		
		Bitboard mag_mob = magic_mobility(sq, sliding_attack(sq, deltas, EMPTY_BB));		

		PartialMask mask = 0;
		MagicAndShift ms = magics[sq];
		int space = (1 << ms.shift);		
		magics[sq].lookup = (Bitboard*)malloc(space * sizeof(Bitboard));
		while (mask < variation_count(mag_mob)) {
			Bitboard partial_occup = mask_to_partial_occup(mask, mag_mob);
			Bitboard partial_mobility = sliding_attack(sq, deltas, partial_occup);
			int key = magic_key(ms.magic, ms.shift, partial_occup);			
			magics[sq].lookup[key] = partial_mobility;
			mask++;
		}
	}
}

PawnInfo PAWN_INFOS[2][BOARD_AREA];

inline Rank pawn_start_rank(Color col) {
	return col ? 1 : 6;
}

void init_pawn_infos() {
	for (Color col = BLACK;col <= WHITE;col++) {
		for (Square sq = 0;sq < BOARD_AREA;sq++) {
			PawnInfo pi = PawnInfo{};
			pi.num_pushes = 0;
			pi.num_captures = 0;
			Square curr_sq = sq;
			Rank rank_dir = (col == WHITE ? 1 : -1);
			if (add_delta(&curr_sq, Delta{ rank_dir,0 })) {
				Square push_one_sq = curr_sq;
				pi.pushes[pi.num_pushes++] = move_ft(sq, push_one_sq);
				for (File capt = -1;capt <= 1;capt += 2) {
					Square capt_sq = push_one_sq;
					if (add_delta(&capt_sq, Delta{ 0, capt })) {
						pi.captures[pi.num_captures++] = move_ft(sq, capt_sq);
					}
				}
				Rank rank = rank_of(sq);
				if (rank == pawn_start_rank(col)) {
					if (add_delta(&curr_sq, Delta{ rank_dir,0 })) {
						Square push_two_sq = curr_sq;
						pi.pushes[pi.num_pushes++] = move_ft(sq, push_two_sq);
					}
				}
			}
			PAWN_INFOS[col][sq] = pi;
		}
	}	
}

bool init_attacks() {
	std::cout << "info string initializing attacks" << std::endl;
	for (Square sq = 0;sq < BOARD_AREA;sq++) {
		BISHOP_ATTACK[sq] = sliding_attack(sq, (Delta*)BISHOP_DELTAS, EMPTY_BB);
		BISHOP_MAGIC_ATTACK[sq] = magic_mobility(sq, BISHOP_ATTACK[sq]);
		ROOK_ATTACK[sq] = sliding_attack(sq, (Delta*)ROOK_DELTAS, EMPTY_BB);
		ROOK_MAGIC_ATTACK[sq] = magic_mobility(sq, ROOK_ATTACK[sq]);
		QUEEN_ATTACK[sq] = sliding_attack(sq, (Delta*)QUEEN_DELTAS, EMPTY_BB);
		KNIGHT_ATTACK[sq] = jump_attack(sq, (Delta*)KNIGHT_DELTAS);
		KING_ATTACK[sq] = jump_attack(sq, (Delta*)QUEEN_DELTAS);
	}
	total_space = 0;
	if (!find_magics("bishop", (Delta*)BISHOP_DELTAS, BISHOP_MAGICS)) {
		std::cout << "init attacks failed" << std::endl;
		return false;
	}
	if (!find_magics("rook", (Delta*)ROOK_DELTAS, ROOK_MAGICS)) {
		std::cout << "init attacks failed" << std::endl;
		return false;
	}
	std::cout << "info string init attacks done total space " << total_space << std::endl;
	std::cout << "info string initializing magics" << std::endl;
	build_magics(BISHOP_MAGICS, (Delta*)BISHOP_DELTAS);
	build_magics(ROOK_MAGICS, (Delta*)ROOK_DELTAS);
	std::cout << "info string initializing magics done" << std::endl;
	std::cout << "info string initializing pawn infos" << std::endl;
	init_pawn_infos();
	std::cout << "info string initializing pawn infos done" << std::endl;
	return true;
}

Bitboard sliding_mobility(Square sq, Bitboard magic_attack, MagicAndShift *magics, Bitboard occup_us, Bitboard occup_them, bool violent, bool quiet, bool jump_over_own_piece) {	
	MagicAndShift ms = magics[sq];
	Bitboard occup = jump_over_own_piece ? occup_them : (occup_us | occup_them);
	int key = magic_key(ms.magic, ms.shift, occup & magic_attack);	
	Bitboard mobility = ms.lookup[key];	
	Bitboard final_mobility = EMPTY_BB;
	if (violent) final_mobility |= (mobility & occup_them);
	if (quiet) final_mobility |= (mobility & (~occup_them));		
	return final_mobility & (~occup_us);
}

Bitboard jump_mobility(Square sq, Bitboard attack, Bitboard occup_us, Bitboard occup_them, bool violent, bool quiet) {				
	Bitboard final_mobility = EMPTY_BB;
	if (violent) final_mobility |= (attack & occup_them);
	if (quiet) final_mobility |= (attack & (~occup_them));
	return final_mobility & (~occup_us);
}

Bitboard bishop_mobility(Square sq, Bitboard occup_us, Bitboard occup_them, bool violent, bool quiet) {
	return sliding_mobility(sq, BISHOP_MAGIC_ATTACK[sq], BISHOP_MAGICS, occup_us, occup_them, violent, quiet, false);
}
Bitboard rook_mobility(Square sq, Bitboard occup_us, Bitboard occup_them, bool violent, bool quiet) {
	return sliding_mobility(sq, ROOK_MAGIC_ATTACK[sq], ROOK_MAGICS, occup_us, occup_them, violent, quiet, false);
}
extern Bitboard queen_mobility(Square sq, Bitboard occup_us, Bitboard occup_them, bool violent, bool quiet) {
	return bishop_mobility(sq, occup_us, occup_them, violent, quiet) | rook_mobility(sq, occup_us, occup_them, violent, quiet);
}
extern Bitboard knight_mobility(Square sq, Bitboard occup_us, Bitboard occup_them, bool violent, bool quiet) {
	return jump_mobility(sq, KNIGHT_ATTACK[sq], occup_us, occup_them, violent, quiet);
}
extern Bitboard king_mobility(Square sq, Bitboard occup_us, Bitboard occup_them, bool violent, bool quiet) {
	return jump_mobility(sq, KING_ATTACK[sq], occup_us, occup_them, violent, quiet);
}
