#ifndef ATTACK_HPP

#define ATTACK_HPP

#include <cstdint>

#include "bitboard.hpp"

typedef uint16_t PartialMask;

extern Bitboard mask_to_partial_occup(PartialMask mask, Bitboard full_occup);

#endif