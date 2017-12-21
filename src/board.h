/**
 * @file board.h
 *
 * Board management header file.
 *
 * @date 1998 - 2017
 * @author Richard Delorme
 * @version 4.4
 */

#ifndef EDAX_BOARD_H
#define EDAX_BOARD_H

#include "const.h"

#include <stdio.h>
#include <stdbool.h>

/** Board : board representation */
typedef struct Board {
	u64 player, opponent;     /**< bitboard representation */
} Board;

struct Move;
struct Random;

/* function declarations */
void board_init(Board*);
int board_set(Board*, const char*);
int board_from_FEN(Board*, const char*);
int board_compare(const Board*, const Board*);
bool board_equal(const Board*, const Board*);
void board_symetry(const Board*, const int, Board*);
int board_unique(const Board*, Board*);
void board_check(const Board*);
void board_rand(Board*, int, struct Random*);

int board_count_last_flips(const Board*, const int);
u64 board_get_move(const Board*, const int, struct Move*);
bool board_check_move(const Board*, struct Move*);
void board_swap_players(Board*);
void board_update(Board*, const struct Move*);
void board_restore(Board*, const struct Move*);
void board_pass(Board*);
u64 board_next(const Board*, const int, Board*);
u64 board_pass_next(const Board*, const int, Board*);
u64 board_get_hash_code(const Board*);
int board_get_square_color(const Board*, const int);
bool board_is_occupied(const Board*, const int);
void board_print(const Board*, const int, FILE*);
char* board_to_string(const Board*, const int, char *);
void board_print_FEN(const Board*, const int, FILE*);
char* board_to_FEN(const Board*, const int, char*);
bool board_is_pass(const Board*);
bool board_is_game_over(const Board*);
int board_count_empties(const Board *board);

int count_last_flip(const int, const u64);
extern u64 (*flip[BOARD_SIZE + 2])(const u64, const u64);
u64 get_moves(const u64, const u64);
bool can_move(const u64, const u64);
u64 get_moves_6x6(const u64, const u64);
bool can_move_6x6(const u64, const u64);
int get_mobility(const u64, const u64);
int get_weighted_mobility(const u64, const u64);
int get_potential_mobility(const u64, const u64);
void edge_stability_init(void);
int get_stability(const u64, const u64);
int get_edge_stability(const u64, const u64);
int get_corner_stability(const u64);

#endif

