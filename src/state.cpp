#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <chrono>
#include <algorithm>
#include <cctype>
#include <string>

#ifdef GCCBUILD
#include <cstring>
#endif

#include "main.hpp"
#include "state.hpp"
#include "attack.hpp"

std::string to_lower(std::string data){
	std::transform(data.begin(), data.end(), data.begin(), [](unsigned char c){ return std::tolower(c); });
	return data;
}

Piece fen_symbol_to_piece(std::string fen_symbol) {
	for (Piece p = 0; p < PIECE_ARRAY_SIZE; p++) {
		if(fen_symbol_of(p) == fen_symbol){
			return p;
		}
	}
	return NO_PIECE;
}

Piece piece_at_square(State *st, Square sq) {
	return st->rep[sq];
}

void remove_piece_from_square(State *st, Square sq) {
	Piece p = piece_at_square(st, sq);
	if (p == NO_PIECE) {
		return;
	}
	Bitboard bb = bitboard_of(sq);
	Color col = color_of(p);
	Figure fig = figure_of(p);
	st->by_color[col] &= (~bb);
	st->by_figure[fig] &= (~bb);
	st->rep[sq] = NO_PIECE;
	st->hash_key ^= (~COLOR_FIGURE_KEYS[col][sq][fig]);
}

void put_piece_at_square(State* st, Piece p, Square sq) {
	if(p==NO_PIECE){
		return;
	}
	remove_piece_from_square(st, sq);	
	Bitboard bb = bitboard_of(sq);
	Color col = color_of(p);
	Figure fig = figure_of(p);
	st->by_color[col] |= bb;
	st->by_figure[fig] |= bb;
	st->rep[sq] = p;
	st->hash_key ^= COLOR_FIGURE_KEYS[col][sq][fig];
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
			for (int j = 0; j < (int)(c[0] - '0'); j++) {
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

	set_turn(&st, WHITE);

	if (num_parts > 1) {
		if (parts[1] == "b") {
			st.turn = BLACK;
		}
	}

	st.castling_rights[0] = CastlingRight{
		false,
		SQUARE_H1,
		color_figure(WHITE, ROOK),
		bitboard_of(SQUARE_F1)|bitboard_of(SQUARE_G1),
		bitboard_of(SQUARE_E1)|bitboard_of(SQUARE_F1)
	};

	st.castling_rights[1] = CastlingRight{
		false,
		SQUARE_A1,
		color_figure(WHITE, ROOK),
		bitboard_of(SQUARE_D1)|bitboard_of(SQUARE_C1)|bitboard_of(SQUARE_B1),
		bitboard_of(SQUARE_E1)|bitboard_of(SQUARE_D1)
	};

	st.castling_rights[2] = CastlingRight{
		false,
		SQUARE_H8,
		color_figure(BLACK, ROOK),
		bitboard_of(SQUARE_F8)|bitboard_of(SQUARE_G8),
		bitboard_of(SQUARE_E8)|bitboard_of(SQUARE_F8)
	};

	st.castling_rights[3] = CastlingRight{
		false,
		SQUARE_A8,
		color_figure(BLACK, ROOK),
		bitboard_of(SQUARE_D8)|bitboard_of(SQUARE_C8)|bitboard_of(SQUARE_B8),
		bitboard_of(SQUARE_E8)|bitboard_of(SQUARE_D8)
	};

	if (num_parts > 2) {
		for(int i=0;i<parts[2].length();i++){
			switch(parts[2][i]){
				case 'K':
					st.castling_rights[0].can_castle=true;
					break;
				case 'Q':
					st.castling_rights[1].can_castle=true;
					break;
				case 'k':
					st.castling_rights[2].can_castle=true;
					break;
				case 'q':
					st.castling_rights[3].can_castle=true;
					break;
			}
		}
	}

	st.halfmove_clock = 0;

	if(num_parts>4){
		ToIntResult tir = to_int(parts[4].c_str());
		if(tir.ok){
			st.halfmove_clock = (uint16_t)tir.value;
		}
	}

	st.fullmove_number = 1;

	if(num_parts>5){
		ToIntResult tir = to_int(parts[5].c_str());
		if(tir.ok){
			st.fullmove_number = (uint16_t)tir.value;
		}
	}

	return st;
}

std::string move_to_san(State *st, Move move){
	Square from_sq = from_sq_of(move);
	Square from_file = file_of(from_sq);
	Square to_sq = to_sq_of(move);
	Square to_file = file_of(to_sq);
	Piece from_p = piece_at_square(st, from_sq);
	Figure from_fig = figure_of(from_p);
	Piece to_p = piece_at_square(st, to_sq);
	if(from_fig==KING){
		if(to_file-from_file==2){
			return "O-O";
		}
		if(from_file-to_file==2){
			return "O-O-O";
		}
	}
	std::string letter = "";
	if(from_fig!=PAWN){
		letter = san_letter_of(from_p);
	}
	bool is_capture = ( to_p != NO_PIECE ) || ( (from_fig == PAWN) && (to_sq == st->ep_square) );
	std::string from_spec = from_fig == PAWN ? ( is_capture ? uci_of_square(from_sq).substr(0,1) : "" ) : "";
	Move san_move_buff[MAX_MOVES];
	Move *last_legal = generate_legal(st, san_move_buff);
	bool same_file = false;
	bool same_rank = false;
	bool has_many = false;
	if(from_fig != PAWN){
		for(Move *tptr=san_move_buff;tptr<last_legal;tptr++){
			Move tmove = *tptr;
			Square tfrom = from_sq_of(tmove);
			Square tto = to_sq_of(tmove);
			if((tto == to_sq)&&(tfrom != from_sq)){								
				Piece tpiece = piece_at_square(st, tfrom);
				if(tpiece == from_p){					
					has_many = true;
					if(rank_of(tfrom) == rank_of(from_sq)) same_rank=true;
					if(file_of(tfrom) == file_of(from_sq)) same_file=true;
				}
			}			
		}
	}
	if(has_many){
		if(same_file && same_rank){
			from_spec = uci_of_square(from_sq);
		}else if(same_file){
			from_spec = uci_of_square(from_sq).substr(1,1);
		}else{
			from_spec = uci_of_square(from_sq).substr(0,1);
		}
	}
	std::string takes = is_capture ? "x" : "";
	std::string to_spec = uci_of_square(to_sq);
	std::string check = "";
	State test_st = *st;
	make_move(&test_st, move);
	if(is_in_check(&test_st)){
		check = "+";
		Move test_buff[MAX_MOVES];
		Move* last_legal = generate_legal(&test_st, test_buff);
		if(last_legal == test_buff){
			check = "#";
		}
	}
	std::string prom = "";
	if(type_of_move(move) == PROMOTION_MOVE){
		prom = "=" + san_symbol_of(promotion_piece_of_move(move));
	}
	return letter + from_spec + takes + to_spec + check + prom;
}

State *sorted_state;

int comp_moves(const void *m1, const void *m2){
	std::string san1 = to_lower(move_to_san(sorted_state, *((Move*)m1)));
	std::string san2 = to_lower(move_to_san(sorted_state, *((Move*)m2)));
	return san1 > san2 ? 1 : -1;
}

Move sorted_move_buff[MAX_MOVES];

Move *sorted_moves(State *st){
	Move* last_move = generate_legal(st, sorted_move_buff);

	sorted_state = st;
	qsort(sorted_move_buff, last_move - sorted_move_buff, sizeof(Move), comp_moves);

	return last_move;
}

std::string report_fen(State *st){
	std::string placement_fen = "";
	int acc = 0;
	for(Rank rank = LAST_RANK;rank>=0;rank--){
		for(File file = 0;file<NUM_FILES;file++){
			Piece p = piece_at_square(st, rank_file(rank, file));
			if(p==NO_PIECE){
				acc++;
			}else{
				if(acc){
					placement_fen+='0'+acc;
					acc=0;
				}
				placement_fen+=fen_symbol_of(p);
			}
		}
		if(acc){
			placement_fen+='0'+acc;
			acc=0;
		}
		if(rank>0) placement_fen+="/";
	}
	std::string turn_fen = st->turn == WHITE ? "w" : "b";
	std::string castle_fen = "";
	if(st->castling_rights[0].can_castle) castle_fen+="K";
	if(st->castling_rights[1].can_castle) castle_fen+="Q";
	if(st->castling_rights[2].can_castle) castle_fen+="k";
	if(st->castling_rights[3].can_castle) castle_fen+="q";
	if(castle_fen == "") castle_fen = "-";
	std::string ep_fen = "-";
	if(st->ep_square != SQUARE_A1){
		ep_fen = uci_of_square(st->ep_square);
	}
	BSPRINTF(hbuff, "%d", (int)st->halfmove_clock);
	BSPRINTF(fbuff, "%d", (int)st->fullmove_number);
	return placement_fen + " " + turn_fen + " " + castle_fen + " " + ep_fen + " " + hbuff + " " + fbuff;
}

std::string pretty_state(State *st) {
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
	buff += "\n";
	buff += "fen : " + report_fen(st);
	BSPRINTF(ebuff, " , score : %d", (int)eval_state(st));
	buff += " ";
	buff += ebuff;
	buff += "\n";

	Move *last_move = sorted_moves(st);

	Move* ptr = sorted_move_buff;

	while (ptr < last_move) {
		if((ptr-sorted_move_buff) % 4 == 0) buff+="\n";
		Move move = *ptr;
		BSPRINTF(ibuff, "%2d. ", (int)(ptr-sorted_move_buff+1))
		BSPRINTF(mbuff, "%-12s ", move_to_san(st, move).c_str())
		BSPRINTF(ubuff, "%-8s ", uci_of_move(move).c_str())
		buff += ibuff;
		buff += mbuff;		
		buff += ubuff;	
		ptr++;	
	}
	buff += "\n";

	return buff + "\n";
}

Bitboard mobility_for_piece_at_square(State *st, Piece p, Square sq, bool violent, bool quiet) {
	Color col = color_of(p);
	Figure fig = figure_of(p);
	Bitboard occup_us = st->by_color[col];
	Bitboard occup_them = st->by_color[1-col];
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

Move* add_promotion_moves(State *st, Move *move_buff, Move move, Color prom_col){	
	for(Figure fig = KNIGHT;fig<=QUEEN;fig++){
		*(move_buff++) = decorate_move_with_promotion_piece(decorate_move_with_type(move, PROMOTION_MOVE), color_figure(prom_col, fig));
	}
	return move_buff;
}

Move* pseudo_legal_moves_for_piece_at_square(State *st, Piece p, Square sq, Move* move_buff, bool violent, bool quiet) {
	Move *orig = move_buff;
	//if(st->turn == WHITE) std::cout << uci_of_square(sq) << " " << fen_symbol_of(p) << " " << std::endl;
	Figure fig = figure_of(p);
	Color col = color_of(p);
	if (fig == PAWN) {
		bool is_promotion = (rank_of(sq) == (col ? 6 : 1));		
		PawnInfo pi = PAWN_INFOS[col][sq];		
		if(quiet && (pi.num_pushes > 0) && (piece_at_square(st, to_sq_of(pi.pushes[0])) == NO_PIECE)) {
			if(is_promotion){
				move_buff = add_promotion_moves(st, move_buff, pi.pushes[0], col);
			}else *(move_buff++) = pi.pushes[0];			
			if (pi.num_pushes > 1) {
				if (piece_at_square(st, to_sq_of(pi.pushes[1])) == NO_PIECE) {
					*(move_buff++) = pi.pushes[1];
				}
			}
		}
		if (violent) {
			for (int i = 0;i < pi.num_captures;i++) {
				Square capt_sq = to_sq_of(pi.captures[i]);
				Piece cp = piece_at_square(st, capt_sq);
				if( ( (cp != NO_PIECE) && (color_of(cp) == (1-col)) ) || ( st->ep_square == capt_sq ) ){
					if(is_promotion){
						move_buff = add_promotion_moves(st, move_buff, pi.captures[i], col);
					}else *(move_buff++) = pi.captures[i];
				}
			}
		}
	} else {
		Bitboard mobility = mobility_for_piece_at_square(st, p, sq, violent, quiet);
		while (mobility) {
			Square to_sq = pop_square(&mobility);
			*(move_buff++) = move_ft(sq, to_sq);
		}
		if(fig==KING){
			for(int i=0;i<2;i++){
				CastlingRight cr = st->castling_rights[(1-col)*2+i];
				if(cr.can_castle){
					if((cr.check_empty & (st->by_color[BLACK]|st->by_color[WHITE]))==0){						
						bool ok = true;
						Bitboard check_attack = cr.check_attack;
						while(check_attack){
							Square check_attack_sq = pop_square(&check_attack);
							if(least_attacker_on_square_of_color(st, check_attack_sq, 1-st->turn)!=NO_FIGURE){
								ok = false;
								break;
							}
						}
						if(ok) *(move_buff++) = move_ft(sq, rank_file(rank_of(sq), file_of(sq) + 2 - (4 * i)));
					}
				}
			}
		}
	}	
	//if(st->turn == WHITE) for(Move* ptr=orig;ptr<move_buff;ptr++)std::cout<<"--> "<<uci_of_move(*ptr)<<std::endl;
	return move_buff;
}

Move* pseudo_legal_moves_for_color(State *st, Move* move_buff, Color col, bool violent, bool quiet) {
	Bitboard us = st->by_color[col];
	Move* ptr = move_buff;
	while (us) {
		Square sq = pop_square(&us);
		Piece p = piece_at_square(st, sq);
		ptr = pseudo_legal_moves_for_piece_at_square(st, p, sq, ptr, violent, quiet);
	}
	return ptr;
}

Score mobility_and_attack(State *st, Score mobility_weight, Score attack_weight) {
	Score mob = 0;
	Score att = 0;
	for(Color col = BLACK; col <= WHITE; col++){
		Score dir = col ? 1 : -1;
		Bitboard us = st->by_color[col] & (~st->by_figure[PAWN]);		
		Bitboard king_them = st->by_color[1-col] & st->by_figure[KING];
		Bitboard king_sq_bb = king_them;
		Square king_sq = pop_square(&king_sq_bb);
		Bitboard king_attack_them = KING_ATTACK[king_sq];
		while (us) {
			Square sq = pop_square(&us);
			Figure fig = figure_of(piece_at_square(st, sq));
			Bitboard mob_bb = mobility_for_piece_at_square(st, color_figure(1-col, fig), sq, true, true);
			mob += dir * pop_cnt(mob_bb) * mobility_weight;			
			att += dir * pop_cnt(mob_bb && king_them) * attack_weight * 3;
			att += dir * pop_cnt(mob_bb && king_attack_them) * attack_weight;
		}
	}	
	return mob + att;
}

Move* pseudo_legal_moves_for_turn(State *st, Move* move_buff, bool violent, bool quiet) {
	return pseudo_legal_moves_for_color(st, move_buff, st->turn, violent, quiet);
}

Move* generate_pseudo_legal(State *st, Move* move_buff) {
	return pseudo_legal_moves_for_turn(st, move_buff, true, true);
}

void set_turn(State *st, Color col){
	st->hash_key ^= (~TURN_KEYS[st->turn]);
	st->hash_key ^= TURN_KEYS[col];
	st->turn = col;
}

void make_move(State* st, Move move) {	
	Square from_sq = from_sq_of(move);	
	Rank from_rank = rank_of(from_sq);
	File from_file = file_of(from_sq);
	Square to_sq = to_sq_of(move);
	Rank to_rank = rank_of(to_sq);
	File to_file = file_of(to_sq);
	Piece from_p = piece_at_square(st, from_sq);
	Figure from_fig = figure_of(from_p);
	Piece to_p = piece_at_square(st, to_sq);
	bool is_ep_capture = (from_fig == PAWN) && (to_sq == st->ep_square);
	bool is_capture = is_ep_capture || ( to_p != NO_PIECE );
	st->ep_square = SQUARE_A1;
	remove_piece_from_square(st, from_sq);
	put_piece_at_square(st, from_p, to_sq);
	if(type_of_move(move) == PROMOTION_MOVE){
		put_piece_at_square(st, promotion_piece_of_move(move), to_sq);
	}
	if(is_ep_capture){
		remove_piece_from_square(st, rank_file(to_rank - (st->turn ? 1:-1), to_file));
	}
	if(from_fig==KING){
		if((to_file-from_file==2)||(from_file-to_file==2)){
			CastlingRight cr=st->castling_rights[(1-st->turn)*2+(to_file<from_file?1:0)];
			remove_piece_from_square(st, cr.rook_orig_square);
			put_piece_at_square(st, cr.rook_orig_piece, rank_file(from_rank, to_file+(to_file<from_file?1:-1)));
		}
	}
	if(st->atomic){
		if(is_capture){
			remove_piece_from_square(st, to_sq);
			Bitboard exp_bb = KING_ATTACK[to_sq];
			while(exp_bb){
				Square exp_sq = pop_square(&exp_bb);
				if(figure_of(piece_at_square(st, exp_sq)) != PAWN){
					remove_piece_from_square(st, exp_sq);
				}
			}
		}
	}	
	if(from_fig==PAWN){
		if((from_rank==1)&&(to_rank==3)){
			st->ep_square = rank_file(2, from_file);
		}
		if((from_rank==6)&&(to_rank==4)){
			st->ep_square = rank_file(5, from_file);
		}
	}
	if(st->ep_square!=SQUARE_A1){
		bool ep_ok = false;
		PawnInfo pi = PAWN_INFOS[st->turn][st->ep_square];
		for(int i=0;i<pi.num_captures;i++){
			Piece test_p = piece_at_square(st, to_sq_of(pi.captures[i]));
			if(test_p!=NO_PIECE){
				if(figure_of(test_p)==PAWN){
					if(color_of(test_p)==(1-st->turn)){
						ep_ok = true;
						break;
					}
				}
			}
		}
		if(!ep_ok) st->ep_square=SQUARE_A1;
	}	
	if(from_fig==KING){
		st->castling_rights[(1-st->turn)*2].can_castle=false;
		st->castling_rights[(1-st->turn)*2+1].can_castle=false;
	}	
	for(Color col=BLACK;col<=WHITE;col++){
		for(int i=0;i<2;i++){
			if(st->castling_rights[col*2+i].can_castle){
				CastlingRight cr = st->castling_rights[col*2+i];
				if(piece_at_square(st, cr.rook_orig_square) != cr.rook_orig_piece){
					st->castling_rights[col*2+i].can_castle=false;
				}
			}	
		}
	}	
	if(is_capture||(from_fig==PAWN)){
		st->halfmove_clock=0;
	}else{
		st->halfmove_clock++;
	}	
	set_turn(st, 1 - st->turn);
	if(st->turn==WHITE) st->fullmove_number++;
}

long long int nodes;

void push_state(LinearGame* lg) {
	lg->states[lg->state_ptr + 1] = lg->states[lg->state_ptr];
	lg->state_ptr++;
}

void pop_state(LinearGame* lg) {	
	lg->state_ptr--;
}

void perft_rec(LinearGame* lg, int current_depth, int max_depth) {		
	//std::cout << pretty_state(&lg->states[lg->state_ptr]);		
	if (current_depth == max_depth) {
		nodes++;
		return;
	}
	Move move_buff[200];
	State *curr = &lg->states[lg->state_ptr];
	Move* last = generate_legal(curr, move_buff);
	Move* ptr = move_buff;
	while (ptr < last) {
		push_state(lg);				
		make_move(&lg->states[lg->state_ptr], *ptr++); 
		long long int nodes_start = nodes;
		perft_rec(lg, current_depth + 1, max_depth);
		if(current_depth == 0) std::cout << uci_of_move(*(ptr-1)) << ": " << nodes - nodes_start << std::endl;
		pop_state(lg);
	}
}

void perft(LinearGame* lg, int depth) {
	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();	
	nodes = 0;
	lg->state_ptr = 0;

	perft_rec(lg, 0, depth);

	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	std::cout << std::endl << "time " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << " ms" << std::endl;
	BSPRINTF(nbuff, "%lld", nodes);
	std::cout << "nodes " << nbuff << std::endl;
}

Figure least_attacker_on_square_of_color(State *st, Square sq, Color col){
	PawnInfo pi = PAWN_INFOS[1-col][sq];
	for(int i=0;i<pi.num_captures;i++){
		Piece p = piece_at_square(st, to_sq_of(pi.captures[i]));
		if((figure_of(p)==PAWN) && (color_of(p) == col)) return PAWN;
	}
	for(Figure fig = KNIGHT; fig <= KING; fig++){
		Bitboard mob = mobility_for_piece_at_square(st, color_figure(1-col, fig), sq, true, false);
		Square test_sq;
		Piece test_p = color_figure(col, fig);
		while(mob){
			test_sq = pop_square(&mob);
			if(piece_at_square(st, test_sq) == test_p){
				return fig;
			}
		}
	}
	return NO_FIGURE;
}

bool is_in_check_color(State *st, Color col){
	if(st->atomic){
		if(kings_adjacent(st)){
			return false;
		}
	}

	Bitboard king_bb = st->by_color[col] & st->by_figure[KING];

	if(!king_bb){
		return true;
	}

	Square king_sq = pop_square(&king_bb);

	if(st->atomic){
		Bitboard king_them_bb = st->by_color[1-col] & st->by_figure[KING];
		if(!king_them_bb){
			return false;
		}
	}

	Figure least_attacker = least_attacker_on_square_of_color(st, king_sq, 1-col);

	return least_attacker != NO_FIGURE;
}

bool is_in_check(State *st){
	return is_in_check_color(st, st->turn);
}

Move pseudo_buff[MAX_MOVES];

Move* generate_legal(State *st, Move* move_buff){
	Move *last_move = generate_pseudo_legal(st, pseudo_buff);
	Move *lptr = move_buff;
	for(Move *ptr = pseudo_buff; ptr < last_move; ptr++){
		State test_st = *st;
		make_move(&test_st, *ptr);
		if(!is_in_check_color(&test_st, st->turn)){
			*lptr++ = *ptr;
		}
	}
	return lptr;
}

Score eval_state(State *st){
	Score mat = 0;

	for(Color col = BLACK; col <= WHITE; col++){
		Score dir = 2 * col - 1;

		Bitboard pawns = st->by_figure[PAWN] & st->by_color[col];
		mat += dir * 100 * pop_cnt(pawns);

		mat += dir * 25 * pop_cnt(pawns & CENTER_BB);

		Bitboard knights = st->by_figure[KNIGHT] & st->by_color[col];
		mat += dir * 300 * pop_cnt(knights);		

		Bitboard bishops = st->by_figure[BISHOP] & st->by_color[col];
		mat += dir * 300 * pop_cnt(bishops);

		Bitboard rooks = st->by_figure[ROOK] & st->by_color[col];
		mat += dir * 500 * pop_cnt(rooks);

		Bitboard queens = st->by_figure[QUEEN] & st->by_color[col];
		mat += dir * 900 * pop_cnt(queens);
	}

	mat += mobility_and_attack(st, 10, 25);

	mat += RANDOM_BONUS - 2 * ( ( RANDOM_BONUS * (Score)(gen_magic() & 0xff) ) / 0xff );

	return st->turn ? mat : -mat;
}

bool kings_adjacent(State *st){
	Bitboard wk_bb = st->by_figure[KING] & st->by_color[WHITE];	
	if(!wk_bb) return false;
	Bitboard bk_bb = st->by_figure[KING] & st->by_color[WHITE];
	if(!bk_bb) return false;
	Square wk_sq = pop_square(&wk_bb);
	Bitboard wk_attack = KING_ATTACK[wk_sq];
	return wk_attack & bk_bb;
}
