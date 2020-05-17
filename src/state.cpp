#include <string>
#include <iostream>
#include <stdio.h>

#include "state.hpp"
#include "attack.hpp"

int split(std::string str, std::string delim, std::string *buff) {
	int index = int(str.find(delim));
	int cnt = 0;
	if (index < 0) {
		buff[cnt] = str;
		return cnt;
	}
	while (index >= 0) {
		buff[cnt++] = str.substr(0, index);		
		str = str.substr(index + delim.length());
		index = int(str.find(delim));
	}
	return cnt;
}

Piece fen_symbol_to_piece(std::string fen_symbol) {
	for (Piece p = 0; p < PIECE_ARRAY_SIZE; p++) {
		if(fen_symbol_of(p) == fen_symbol){
			return p;
		}
	}
	return NO_PIECE;
}

Piece piece_at_square(State st, Square sq) {
	return st.rep[sq];
}

void remove_piece_from_square(State *st, Square sq) {
	Piece p = piece_at_square(*st, sq);
	if (p == NO_PIECE) {
		return;
	}
	Bitboard bb = bitboard_of(sq);
	st->by_color[color_of(p)] &= (~bb);
	st->by_figure[figure_of(p)] &= (~bb);
	st->rep[sq] = NO_PIECE;
}

void put_piece_at_square(State* st, Piece p, Square sq) {
	remove_piece_from_square(st, sq);
	Bitboard bb = bitboard_of(sq);
	st->by_color[color_of(p)] |= bb;
	st->by_figure[figure_of(p)] |= bb;
	st->rep[sq] = p;
}

State state_from_fen(std::string fen) {
	State st = State{};

	memset(&st, 0, sizeof(State));

	if (fen == "") {
		fen = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
	}

	std::string parts[7];
	int num_parts = split(fen, " ", parts);

	std::string placement = parts[0];

	Rank rank = LAST_RANK;
	File file = 0;

	for (int i = 0; i < (int)placement.length(); i++) {
		std::string c = placement.substr(i, 1);

		Square sq = rank_file(rank, file);

		if ((c >= "1") && (c <= "8")) {
			for (int j = 0; j < (int)(c[0] - '1'); j++) {
				put_piece_at_square(&st, NO_PIECE, sq);
				file++;
				Square sq = rank_file(rank, file);
			}
		} else if (c == "/") {
			rank--;
			file = 0;
		} else {
			put_piece_at_square(&st, fen_symbol_to_piece(c), sq);
			file++;
		}
	}

	st.turn = WHITE;

	if (num_parts > 1) {
		if (parts[1] == "b") {
			st.turn = BLACK;
		}
	}

	return st;
}

std::string pretty_state(State st) {
	std::string buff = "";
	for (Rank rank = LAST_RANK; rank >= 0; rank--) {		
		for (File file = 0; file < NUM_FILES; file++) {
			Square sq = rank_file(rank, file);
			if (file == 0) {
				buff += uci_of_square(sq).substr(1, 1) + " ";
			}
			buff += fen_symbol_of(piece_at_square(st, sq));
		}
		buff += "\n";
	}
	buff += "\n  abcdefgh\n";
	buff += "\nturn ";
	if (st.turn == WHITE) {
		buff += "w";
	}
	else {
		buff += "b";
	}
	buff += "\n";

	Move move_buff[500];

	Move* last_move = generate_pseudo_legal(st, move_buff);

	Move* ptr = move_buff;

	buff += "moves : ";

	while (ptr < last_move) {
		buff += uci_of_move(*ptr++) + " ";
	}
	buff += "\n";

	return buff + "\n";
}

Bitboard mobility_for_piece_at_square(State st, Piece p, Square sq, bool violent, bool quiet) {
	Color col = color_of(p);
	Figure fig = figure_of(p);
	Bitboard occup_us = st.by_color[col];
	Bitboard occup_them = st.by_color[1-col];
	switch (fig) {
	case BISHOP:
		return bishop_mobility(sq, occup_us, occup_them, violent, quiet);
	case ROOK:
		return rook_mobility(sq, occup_us, occup_them, violent, quiet);
	case QUEEN:
		return queen_mobility(sq, occup_us, occup_them, violent, quiet);
	case KNIGHT:
		return knight_mobility(sq, occup_us, occup_them, violent, quiet);
	case KING:
		return king_mobility(sq, occup_us, occup_them, violent, quiet);
	default:
		return EMPTY_BB;
	}	
}

Move* pseudo_legal_moves_for_piece_at_square(State st, Piece p, Square sq, Move* move_buff, bool violent, bool quiet) {
	//std::cout << uci_of_square(sq) << " " << fen_symbol_of(p) << " " << std::endl;
	Figure fig = figure_of(p);
	Color col = color_of(p);
	if (fig == PAWN) {
		PawnInfo pi = PAWN_INFOS[col][sq];		
		if(quiet && (pi.num_pushes > 0) && (piece_at_square(st, to_sq_of(pi.pushes[0])) == NO_PIECE)) {
			*(move_buff++) = pi.pushes[0];
			if (pi.num_pushes > 1) {
				if (piece_at_square(st, to_sq_of(pi.pushes[1])) == NO_PIECE) {
					*(move_buff++) = pi.pushes[1];
				}
			}
		}
		if (violent) {
			for (int i = 0;i < pi.num_captures;i++) {
				Piece cp = piece_at_square(st, to_sq_of(pi.captures[i]));
				if( (cp != NO_PIECE) && (color_of(cp) == (1-col)) ) {
					*(move_buff++) = pi.captures[i];
				}
			}
		}
	} else {
		Bitboard mobility = mobility_for_piece_at_square(st, p, sq, violent, quiet);
		while (mobility) {
			Square to_sq = pop_square(&mobility);
			*(move_buff++) = move_ft(sq, to_sq);
		}
	}	
	return move_buff;
}

Move* pseudo_legal_moves_for_color(State st, Move* move_buff, Color col, bool violent, bool quiet) {
	Bitboard us = st.by_color[col];
	Move* ptr = move_buff;
	while (us) {
		Square sq = pop_square(&us);
		Piece p = piece_at_square(st, sq);
		ptr = pseudo_legal_moves_for_piece_at_square(st, p, sq, ptr, violent, quiet);
	}
	return ptr;
}

Move* pseudo_legal_moves_for_turn(State st, Move* move_buff, bool violent, bool quiet) {
	return pseudo_legal_moves_for_color(st, move_buff, st.turn, violent, quiet);
}

Move* generate_pseudo_legal(State st, Move* move_buff) {
	return pseudo_legal_moves_for_turn(st, move_buff, true, true);
}

void make_move(State* st, Move move) {
	Square from_sq = from_sq_of(move);
	Square to_sq = to_sq_of(move);
	Piece from_p = piece_at_square(*st, from_sq);
	Piece to_p = piece_at_square(*st, to_sq);
	remove_piece_from_square(st, from_sq);
	put_piece_at_square(st, from_p, to_sq);
	st->turn = 1 - st->turn;
}
