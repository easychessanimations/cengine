
#ifndef BITBOARD_HPP

#define BITBOARD_HPP

#include <cstdint>

typedef uint64_t Bitboard;

const Bitboard RANK_1_BB = 0x00000000000000ff;
const Bitboard RANK_8_BB = 0xff00000000000000;
const Bitboard FILE_A_BB = 0x8080808080808080;
const Bitboard FILE_H_BB = 0x0101010101010101;

extern std::string pretty_bitboard(Bitboard bb);

#endif
