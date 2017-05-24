#ifndef HASH_H
#define HASH_H

#include "../types.h"

#define GET_STATS 0

typedef struct {
	unsigned char move_num;
	movement move_L1;
	movement move_L2;
	movement move_L3;
} L3_prune_entry;

#define TABLE_LOG2 14
#define TABLE_SIZE (1<<TABLE_LOG2)

void hash_clear();
void hash_put(int level, unsigned char move_count);
char hash_get(int level, unsigned char move_count, movement *move);
void printf_hash_stats();

#endif
