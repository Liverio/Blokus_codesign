#ifndef L1_L2_MOVES_MEMORY_H
#define L1_L2_MOVES_MEMORY_H

#include "../types.h"
#include "../min_max.h"

#define DB_L1_SIZE 512
#define DB_L2_SIZE 128
#define CHAIN_SIZE (MAX_LEVEL-1)

typedef struct {
	movement move;
	int score;
	int index;		// Static index assigned to its L2 successors
	// Best chain
	movement chain[CHAIN_SIZE];
} L1_move_entry;

typedef struct {
	movement move;
	int score;
} L2_move_entry;

typedef struct {
	L2_move_entry move[DB_L2_SIZE];
	int num_moves;
} L2_mem;



void clear_moves_memories();
void add_L1(movement move_L1, int score, movement* chain);
char get_L1_move(movement *move);
void get_best_chain(unsigned char level, movement *move);

#endif
