#ifndef L1_L2_MOVES_MEMORY_C
#define L1_L2_MOVES_MEMORY_C

#include "L1_L2_moves_mem.h"

extern unsigned char current_max_level;

// L1
L1_move_entry database_L1[2][DB_L1_SIZE];
static int entries_L1;
static int last_read_L1;
static int last_write_L1;
int index;	// Only used for data generation
static int current_index;

// L2
L2_mem database_L2[DB_L1_SIZE];
static int last_read_L2;

#define DEBUG 0

void clear_moves_memories(){
	int i;

	entries_L1 = 0;
	for (i = 0; i < DB_L1_SIZE; i++)
		database_L2[i].num_moves = 0;

	index = 0;
	last_read_L1 = 0;
	last_read_L2 = 0;
	last_write_L1 = 0;
}


// **********************
// ********* L1 *********
// **********************

// Data created when current_max_level == 2. Indices are created here. Deeper searches use that indices
void add_L1(movement move_L1, int score, movement* chain){
	int pos, i;
	char sorted;

	char mem_num = current_max_level % 2;

	#if DEBUG
		printf("Adding L1 (%d)(%d): %c%c%c%d\n", mem_num, last_write_L1, move_L1.x < 9 ? move_L1.x+48+1 : move_L1.x+88, move_L1.y < 9 ? move_L1.y+48+1 : move_L1.y+88, move_L1.tile+97, move_L1.rotation);
	#endif
	// Add in an empty position
	database_L1[mem_num][last_write_L1].move = move_L1;
	database_L1[mem_num][last_write_L1].score = score;
	memcpy(database_L1[mem_num][last_write_L1].chain, chain, CHAIN_SIZE*sizeof(movement));

	// Bubble ordering
	pos = last_write_L1;
	sorted = 0;
	while (pos > 0 && !sorted){
		// Interchange
		if (database_L1[mem_num][pos].score > database_L1[mem_num][pos-1].score){
			// Move movement in pos-1 to pos
			memcpy(&(database_L1[mem_num][pos]), &(database_L1[mem_num][pos-1]), sizeof(L1_move_entry));
			// Store in pos-1 the new movement
			database_L1[mem_num][pos-1].move = move_L1;
			database_L1[mem_num][pos-1].score = score;
			memcpy(database_L1[mem_num][pos-1].chain, chain, CHAIN_SIZE*sizeof(movement));
			
			pos--;
		}
		else{
			sorted = 1;
		}
	}

	// Assign index in the first search (not necessary while sorting)
	if (current_max_level == 2){
		database_L1[mem_num][pos].index = index;
		index++;
	}
	else{
		database_L1[mem_num][pos].index = current_index;
	}

	// Number of L1 nodes is constant along the searches
	if (current_max_level == 2){
		entries_L1++;
		if (entries_L1 == DB_L1_SIZE){
			printf("L1 memory overflow\n");
			exit(0);
		}
	}

	last_write_L1++;
}

char get_L1_move(movement *move){
	char mem_num = (current_max_level-1) % 2;

	// First L1 read, reset write pointer
	if (last_write_L1 == entries_L1)
		last_write_L1 = 0;

	if (last_read_L1 < entries_L1){
		memcpy(move, &(database_L1[mem_num][last_read_L1].move), sizeof(movement));
		current_index = database_L1[mem_num][last_read_L1].index;
		#if DEBUG
			printf("\n(%d) Reading L1: %c%c%c%d\n", database_L1[mem_num][last_read_L1].index, move->x < 9 ? move->x+48+1 : move->x+88, move->y < 9 ? move->y+48+1 : move->y+88, move->tile+97, move->rotation);
		#endif
		last_read_L1++;
		// Reset L2 read pointer
		last_read_L2 = 0;
		return 1;
	}
	// Reset read and write pointers
	last_read_L1 = 0;
	last_write_L1 = 0;

	return 0;
}

void get_best_chain(unsigned char level, movement *move){
	char mem_num = (current_max_level-1) % 2;

	memcpy(move, &(database_L1[mem_num][last_read_L1-1].chain[level-1]), sizeof(movement));
	return ;
}


// **********************
// ********* L2 *********
// **********************

// Data created when deep is 2
void add_L2(movement move_L2, int score){
	int pos;
	char sorted;

	// Add if enough space, and override if the new move is better than the current worst one
	if (database_L2[index].num_moves < DB_L2_SIZE || score < database_L2[index].move[DB_L2_SIZE-1].score){
		pos = database_L2[index].num_moves < DB_L2_SIZE ? database_L2[index].num_moves : DB_L2_SIZE-1;
		// Add in an empty position
		database_L2[index].move[pos].move = move_L2;
		database_L2[index].move[pos].score = score;
		if (database_L2[index].num_moves < DB_L2_SIZE)
			database_L2[index].num_moves++;

		// Bubble ordering
		sorted = 0;
		while (pos > 0 && !sorted){
			// Interchange
			if (database_L2[index].move[pos].score < database_L2[index].move[pos-1].score){
				memcpy(&database_L2[index].move[pos], &database_L2[index].move[pos-1], sizeof(L2_move_entry));
				database_L2[index].move[pos-1].move = move_L2;
				database_L2[index].move[pos-1].score = score;
				pos--;
			}
			else{
				sorted = 1;
			}
		}
	}
}

char get_L2_move(movement *move){
	char mem_num = (current_max_level-1) % 2;

	int index = database_L1[mem_num][last_read_L1-1].index;
	int entries_L2 = database_L2[index].num_moves;
	if (last_read_L2 < entries_L2){
		memcpy(move, &(database_L2[index].move[last_read_L2].move), sizeof(movement));
		last_read_L2++;
		return 1;
	}
	return 0;
}

#endif
