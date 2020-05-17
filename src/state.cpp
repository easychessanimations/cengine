#include <string>
#include <iostream>
#include <stdio.h>

#include "state.hpp"

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
	return buff + "\n";
}

