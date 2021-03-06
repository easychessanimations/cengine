#ifndef STATE_HPP

#define STATE_HPP

#include <string>

#include "piece.hpp"
#include "square.hpp"
#include "bitboard.hpp"
#include "attack.hpp"

typedef int16_t Score;

typedef int8_t Depth;

extern int split(std::string str, std::string delim, std::string *buff);

struct CastlingRight{
	bool can_castle;
	Square rook_orig_square;
	Piece rook_orig_piece;
	Bitboard check_empty;
	Bitboard check_attack;
};

struct State {
	bool state_ok;
	Piece rep[BOARD_AREA];
	Color turn;
	Bitboard by_color[2];
	Bitboard by_figure[FIGURE_ARRAY_SIZE];
	Magic hash_key;
	bool atomic;
	CastlingRight castling_rights[4];
	Square ep_square;
	uint16_t halfmove_clock;
	uint16_t fullmove_number;
};

extern State state_from_fen(std::string fen);

extern Piece fen_symbol_to_piece(std::string fen_symbol);

const int MAX_MOVES = 500;

extern Move sorted_move_buff[MAX_MOVES];
extern Move* sorted_moves(State *st);

extern std::string pretty_state(State *st);

extern Move* generate_pseudo_legal(State *st, Move* move_buff);

extern Move* generate_legal(State *st, Move* move_buff);

extern void make_move(State *st, Move move);

const int MAX_STATES = 100;

const int MAX_MULTIPV = 20;

struct MultipvInfoItem{
	int8_t index;
	Depth depth;
	int time;
	long long int nodes;
	int nps;
	Score score;
	std::string pv;
};

struct MultipvInfo{
	MultipvInfoItem items[MAX_MULTIPV];
	int8_t num_items;
	bool has_bestmove;
	Move bestmove;
	bool has_ponder;
	Move ponder;
};

struct LinearGame {
	State states[MAX_STATES];
	int state_ptr;
	Move ignored_root_moves[MAX_MULTIPV];
	Move* last_ignored_root_move;
	int8_t multipv;
	int8_t eff_multipv;
	MultipvInfo current_multipv;
	MultipvInfo last_good_multipv;
};

extern void push_state(LinearGame *lg);
extern void pop_state(LinearGame *lg);

extern void perft(LinearGame* lg, int depth);

extern Figure least_attacker_on_square_of_color(State *st, Square sq, Color col);

extern bool is_in_check_color(State *st, Color col);

extern bool is_in_check(State *st);

extern std::string move_to_san(State *st, Move move);

extern long long nodes;

const Score INFINITE_SCORE = 20000;
const Score MATE_SCORE = 10000;
const Score WIN_SCORE = 9000;

const Score RANDOM_BONUS = 5;

extern Score eval_state(State *st);

extern void set_turn(State *st, Color col);

extern Score mobility_and_attack(State *st, Score mobility_weight, Score attack_weight);

extern bool kings_adjacent(State *st);

extern Piece piece_at_square(State *st, Square sq);

extern Bitboard mobility_for_piece_at_square(State *st, Piece p, Square sq, bool violent, bool quiet);

extern void make_uci_move(LinearGame* lg, std::string move_uci);

extern Score phase(State *st);

#endif
