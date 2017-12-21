/**
 * @file bit.h
 *
 * Bitwise operations header file.
 *
 * @date 1998 - 2017
 * @author Richard Delorme
 * @version 4.4
 */

#ifndef EDAX_BIT_H
#define EDAX_BIT_H

#include <stdio.h>

struct Random;

/* declaration */
int bit_count(u64);
int bit_weighted_count(const u64);
int first_bit(u64);
int next_bit(u64*);
int last_bit(u64);
void bitboard_write(const u64, FILE*);
u64 transpose(u64);
u64 vertical_mirror(u64);
u64 horizontal_mirror(u64);
unsigned int bswap_int(unsigned int);
unsigned short bswap_short(unsigned short);
int get_rand_bit(u64, struct Random*);

/** Loop over each bit set. */
#define foreach_bit(i, b) for (i = first_bit(b); b; i = next_bit(&b))

extern const u64 X_TO_BIT[];
/** Return a bitboard with bit x set. */
#define x_to_bit(x) X_TO_BIT[x]

//#define x_to_bit(x) (1ULL << (x)) // 1% slower on Sandy Bridge

#endif

