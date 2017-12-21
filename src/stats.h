/**
 * @file stats.h
 *
 * @brief Statistics header.
 *
 * @date 1998 - 2017
 * @author Richard Delorme
 * @version 4.4
 */

#ifndef EDAX_STATS_H
#define EDAX_STATS_H

#include "const.h"
#include "util.h"

#include <stdio.h>

/* To turn on a statistics, add an x to the end of the line starting with #define .*/
/** YBWC statistics on/off */
#define YBWC_STATS(x)
/** Hash statistics on/off */
#define HASH_STATS(x)
/** Hash collision on/off */
#define HASH_COLLISIONS(x)
/** Search statistics on/off */
#define SEARCH_STATS(x)
/** Square type statistics on/off */
#define SQUARE_STATS(x)
/** Cutoff statistics on/off */
#define CUTOFF_STATS(x)
/** ProbCut statistics on/off */
#define PROBCUT_STATS(x)

/** how to count nodes... */
#define COUNT_NODES 7

#if COUNT_NODES & 1
	/** node counter for internal nodes */
	#define SEARCH_UPDATE_INTERNAL_NODES() (++search->n_nodes)
#else
	/** no node counter for internal nodes */
	#define SEARCH_UPDATE_INTERNAL_NODES()
#endif
#if COUNT_NODES & 2
	/** node counter for pattern changes */
	#define SEARCH_UPDATE_EVAL_NODES() (++search->n_nodes)
#else
	/** no node counter for pattern changes */
	#define SEARCH_UPDATE_EVAL_NODES()
#endif
#if COUNT_NODES & 4
	/** more general node counter */
	#define SEARCH_UPDATE_ALL_NODES() (++search->n_nodes)
#else
	/** no general node counter */
	#define SEARCH_UPDATE_ALL_NODES()
#endif

/** \struct Statistics */
typedef struct Statistics {
	u64 n_nodes;
	u64 n_task_nodes[MAX_THREADS];
	u64 n_task[MAX_THREADS];
	u64 n_parallel_nodes;

	u64 n_hash_update;
	u64 n_hash_upgrade;
	u64 n_hash_new;
	u64 n_hash_remove;
	u64 n_hash_search;
	u64 n_hash_found;
	u64 n_hash_collision;
	u64 n_hash_n;

	u64 n_PVS_root;
	u64 n_PVS_midgame;
	u64 n_NWS_midgame;
	u64 n_NWS_endgame;
	u64 n_PVS_shallow;
	u64 n_NWS_shallow;
	u64 n_search_solve;
	u64 n_search_solve_0;
	u64 n_board_solve_2;
	u64 n_search_solve_3;
	u64 n_search_solve_4;
	u64 n_search_eval_0;
	u64 n_search_eval_1;
	u64 n_search_eval_2;
	u64 n_cut_at_move_number[MAX_MOVE];
	u64 n_nocut_at_move_number[MAX_MOVE];
	u64 n_best_at_move_number[MAX_MOVE];
	u64 n_move_number[MAX_MOVE];

	u64 n_split_try;
	u64 n_split_success;
	u64 n_master_helper;
	u64 n_waited_slave;
	u64 n_stopped_slave;
	u64 n_stopped_master;
	u64 n_wake_up;

	u64 n_hash_try, n_hash_low_cutoff, n_hash_high_cutoff;
	u64 n_stability_try, n_stability_low_cutoff;
	u64 n_probcut_try;
	u64 n_probcut_low_try, n_probcut_low_cutoff;
	u64 n_probcut_high_try, n_probcut_high_cutoff;
	u64 n_etc_try, n_etc_high_cutoff, n_esc_high_cutoff;

	u64 n_played_square[BOARD_SIZE][10];
	u64 n_good_square[BOARD_SIZE][10];

	u64 n_NWS_candidate;
	u64 n_NWS_bad_candidate;

} Statistics;

extern Statistics statistics;
struct Search;

void statistics_init(void);
void statistics_sum_nodes(struct Search*);
void statistics_print(FILE*);

#endif

