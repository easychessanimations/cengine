
#ifndef SQUARE_HPP

#define SQUARE_HPP

#include <cstdint>

typedef uint8_t Rank;
typedef uint8_t File;

const int NUM_RANKS = 8;
const int LAST_RANK = NUM_RANKS - 1;
const int NUM_FILES = 8;
const int LAST_FILE = NUM_FILES - 1;

const std::string RANK_NAMES[NUM_RANKS] = { "1" , "2" , "3" , "4" , "5" , "6" , "7" , "8" };
const std::string FILE_NAMES[NUM_FILES] = { "a" , "b" , "c" , "d" , "e" , "f" , "g" , "h" };

typedef uint8_t Square;

const Square SQUARE_A1 = 0;
const Square SQUARE_B1 = 1;
const Square SQUARE_C1 = 2;
const Square SQUARE_D1 = 3;
const Square SQUARE_E1 = 4;
const Square SQUARE_F1 = 5;
const Square SQUARE_G1 = 6;
const Square SQUARE_H1 = 7;
const Square SQUARE_A2 = 8;
const Square SQUARE_B2 = 9;
const Square SQUARE_C2 = 10;
const Square SQUARE_D2 = 11;
const Square SQUARE_E2 = 12;
const Square SQUARE_F2 = 13;
const Square SQUARE_G2 = 14;
const Square SQUARE_H2 = 15;
const Square SQUARE_A3 = 16;
const Square SQUARE_B3 = 17;
const Square SQUARE_C3 = 18;
const Square SQUARE_D3 = 19;
const Square SQUARE_E3 = 20;
const Square SQUARE_F3 = 21;
const Square SQUARE_G3 = 22;
const Square SQUARE_H3 = 23;
const Square SQUARE_A4 = 24;
const Square SQUARE_B4 = 25;
const Square SQUARE_C4 = 26;
const Square SQUARE_D4 = 27;
const Square SQUARE_E4 = 28;
const Square SQUARE_F4 = 29;
const Square SQUARE_G4 = 30;
const Square SQUARE_H4 = 31;
const Square SQUARE_A5 = 32;
const Square SQUARE_B5 = 33;
const Square SQUARE_C5 = 34;
const Square SQUARE_D5 = 35;
const Square SQUARE_E5 = 36;
const Square SQUARE_F5 = 37;
const Square SQUARE_G5 = 38;
const Square SQUARE_H5 = 39;
const Square SQUARE_A6 = 40;
const Square SQUARE_B6 = 41;
const Square SQUARE_C6 = 42;
const Square SQUARE_D6 = 43;
const Square SQUARE_E6 = 44;
const Square SQUARE_F6 = 45;
const Square SQUARE_G6 = 46;
const Square SQUARE_H6 = 47;
const Square SQUARE_A7 = 48;
const Square SQUARE_B7 = 49;
const Square SQUARE_C7 = 50;
const Square SQUARE_D7 = 51;
const Square SQUARE_E7 = 52;
const Square SQUARE_F7 = 53;
const Square SQUARE_G7 = 54;
const Square SQUARE_H7 = 55;
const Square SQUARE_A8 = 56;
const Square SQUARE_B8 = 57;
const Square SQUARE_C8 = 58;
const Square SQUARE_D8 = 59;
const Square SQUARE_E8 = 60;
const Square SQUARE_F8 = 61;
const Square SQUARE_G8 = 62;
const Square SQUARE_H8 = 63;

const uint8_t FILE_SIZE_IN_BITS = 3;
const uint8_t FILE_MASK = (1 << FILE_SIZE_IN_BITS) - 1;

const uint8_t RANK_SIZE_IN_BITS = 3;
const uint8_t RANK_MASK = (1 << RANK_SIZE_IN_BITS) - 1;
const uint8_t RANK_SHIFT = FILE_SIZE_IN_BITS;

inline Rank rank_of(Square sq){
	return (sq >> RANK_SHIFT) & RANK_MASK;
}

inline Rank file_of(Square sq){
	return sq & FILE_MASK;
}

extern std::string uci_of_square(Square sq);

#endif
