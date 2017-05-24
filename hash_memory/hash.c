#include "../config.h"
#include "../min_max.h"
#include "hash.h"

static int hash_gets = 0;
static int hash_hits = 0;
static int hash_puts = 0;
static int hash_colls = 0;

L3_prune_entry prune_table[TABLE_SIZE];
extern movement last_move[MAX_LEVEL+1];

extern movement current_candidate_lvl3;

int compare_moves(movement *move1, movement *move2);

void hash_clear() {
    memset(prune_table, 0, sizeof prune_table);
	#if GET_STATS
		hash_gets = 0;
		hash_hits = 0;
		hash_puts = 0;
		hash_colls = 0;
	#endif
}

int hash(int level) {
    int hash = 0;
    int move_L1, move_L2;

    move_L1 = (last_move[0].x << 12) + (last_move[0].y << 8) + ((20-last_move[0].tile) << 3) + (last_move[0].rotation);
    move_L2 = (last_move[1].x << 12) + (last_move[1].y << 8) + ((20-last_move[1].tile) << 3) + (last_move[1].rotation);

    hash = (31*move_L1) ^ move_L2;

    return hash & (TABLE_SIZE-1);
}

void hash_put(int level, unsigned char move_count) {
	int pos = hash(level);

	#if GET_STATS
		hash_puts++;
		// Collision
		if (prune_table[pos].move_num == move_count && !(compare_moves(&prune_table[pos].move_L1, &last_move[0]) && compare_moves(&prune_table[pos].move_L2, &last_move[1])))
			hash_colls++;
	#endif
	prune_table[pos].move_num = move_count;
	prune_table[pos].move_L1 = last_move[0];
	prune_table[pos].move_L2 = last_move[1];
	//prune_table[pos].move_L3 = last_move[2];
	prune_table[pos].move_L3 = current_candidate_lvl3;
	return;
}


char hash_get(int level, unsigned char move_count, movement *move) {
    int pos = hash(level);

	#if GET_STATS
    	hash_gets++;
	#endif

    // Hit
    if ((prune_table[pos].move_num == move_count) 				  &&
    	(compare_moves(&prune_table[pos].move_L1, &last_move[0])) &&
    	(compare_moves(&prune_table[pos].move_L2, &last_move[1]))){
		#if GET_STATS
			hash_hits++;
		#endif
    	*move = prune_table[pos].move_L3;
		return 1;
    }
    return 0;
}

int compare_moves(movement *move1, movement *move2) {
    return move1->tile == move2->tile		  &&
    	   move1->rotation == move2->rotation &&
           move1->x == move2->x				  &&
           move1->y == move2->y;
}

void printf_hash_stats(){
	printf("Hash gets: %d\n", hash_gets);
	printf("Hash hits: %d (%.1f%% of Hash gets)\n", hash_hits, 100*(float)(hash_hits)/(float)(hash_gets));
	printf("Hash puts: %d\n", hash_puts);
	printf("Hash collisions: %d (%.1f%% of Hash puts)\n", hash_colls, 100*(float)(hash_colls)/(float)(hash_puts));
}
