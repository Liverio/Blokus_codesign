#include "min_max.h"
#include "legal_moves.h"
#include "error.h"
#include "types.h"
#include "accessibility.h"
#include "tiles.c"
#include "overlapping.h"
#include "moves_memory/L1_L2_moves_mem.h"
#include "config.h"
#include "hash_memory/hash.h"
// HW
#include "xparameters.h"
#include "blokus_accelerator_stream.h"
#include "xaxidma.h"

#include "IO.h"

// Tree status
board boards[MAX_LEVEL+1];
int score[MAX_LEVEL+1];
movement last_move[MAX_LEVEL+1];
char available_tiles_hero[21];
char available_tiles_rival[21];
char pass[MAX_LEVEL];

// Best chain
movement chain[CHAIN_SIZE];	// chain[0] stores the best lvl2 movement, and so on
movement current_candidate_lvl3;

static unsigned char move_count = 2;	// two first moves are fixed
unsigned char current_max_level;

extern tp_legal_move_status legal_move_status[MAX_LEVEL];   // Last level does not process legal moves
extern char accessibility_map_hero[MAX_LEVEL+1][14][14];
extern char accessibility_map_rival[MAX_LEVEL+1][14][14];

// Overlapping
extern char expanded_node[MAX_LEVEL];
extern char overlapping_deactivated[MAX_LEVEL];

// DMA
extern XAxiDma AxiDma;
#define TRANSFER_SIZE 4*16

#define USE_HW_ACC 1
#define SHOW_HASH_STATS 0

void transfer_data_to_HW(unsigned char level){
	u32 row[14+2];
	unsigned char i, j;
	int status;

	// Remove forbidden info from board
	square new_board[14][14];
	for (i = 0; i < 14; i++){
		for (j = 0; j < 14; j++){
			new_board[i][j] = boards[level][i][j] <= SQUARE_HERO ? boards[level][i][j] : SQUARE_FREE;
		}
	}
	//printGameStatus(new_board, available_tiles_hero, available_tiles_rival);

	for (i = 0; i < 14; i++){
		row[i] = 0;
		for (j = 0; j < 14; j++){
			row[i] = row[i] | (new_board[i][j] << (2*j));
		}
	}

	// Tiles
	row[14] = 0;
	row[15] = 0;
	for (i = 0; i < 21; i++){
		row[14] = row[14] | (available_tiles_hero[20-i] << i);
		row[15] = row[15] | (available_tiles_rival[20-i] << i);
	}

	status = XAxiDma_SimpleTransfer(&AxiDma,  (u32) row, TRANSFER_SIZE, XAXIDMA_DMA_TO_DEVICE);
	if (status != XST_SUCCESS) {
		printf("Error: DMA transfer from CPU to ACC failed\n");
		return XST_FAILURE;
	}
	// Wait for transfer to be done
	while (XAxiDma_Busy(&AxiDma, XAXIDMA_DMA_TO_DEVICE))
		;
}




void init_minmax(){
	unsigned char level;

	for (level = 0; level < MAX_LEVEL+1; level++){
		// Last level does not process legal moves
		if (level < MAX_LEVEL){
			initLegalMoveStatus(level);
			init_overlapping(level);
			pass[level] = 0;
			expanded_node[level] = 0;
		}

		if (level % 2 == 0)
			score[level] = -BIG_SCORE*8;
		else
			score[level] = BIG_SCORE*8;
	}

	// Create overlapping map if overlapping is set
	if (check_overlapping(0, move_count)){
		create_overlapping_map(0, boards[0], available_tiles_rival);
	}
}

void propagate_score(unsigned char level, int newScore){
	if ((level % 2 == 0 && newScore > score[level]) ||	// Propagating to MAX level
		(level % 2 != 0 && newScore < score[level]))	// Propagating to MIN level
		score[level] = newScore;
}

void close_level(unsigned char *level, movement *best_move){
	do{
		// Update best move
		if (*level == 1 && score[1] > score[0]){
			memcpy(best_move, &last_move[0], sizeof(movement));
		}
		#if USE_MEM_L1
			// Add the move to the moves memory
			if (*level == 1)
				add_L1(last_move[0], score[1], chain);
		#endif

		#if USE_MEM_L2
			if (current_max_level == 2 && *level == 2)
				add_L2(last_move[1], score[2]);
		#endif

		#if USE_BEST_CHAIN
			// Level 2
			if (*level == 2 && score[2] < score[1])
				memcpy(&chain[0], &last_move[1], sizeof(movement));

			// Level 3
			if (*level == 3 && score[3] > score[2])
				memcpy(&current_candidate_lvl3, &last_move[2], sizeof(movement));
			if (*level == 2 && score[2] < score[1])
				memcpy(&chain[1], &current_candidate_lvl3, sizeof(movement));
		#endif

		#if USE_HASH
			if (current_max_level >= 3 && *level == 2)
				hash_put(*level, move_count);
		#endif

		if (*level < MAX_LEVEL){
			initLegalMoveStatus(*level);
			init_overlapping(*level);
			pass[*level] = 0;
			expanded_node[*level] = 0;
		}

		// Propagate current score to the upper level and then restore initial value in the level closed level
		propagate_score(*level-1, score[*level]);
		score[*level] = *level % 2 == 0 ? -BIG_SCORE : BIG_SCORE;

		// Restore the used tile if not passed
		if (*level > 0 && !pass[*level-1]){
			if (*level % 2 == 0)
				available_tiles_rival[last_move[*level-1].tile] = 1;
			else
				available_tiles_hero[last_move[*level-1].tile] = 1;
		}
		(*level)--;
	} while (pass[*level]);
}

void create_new_node(movement move, tp_player player, unsigned char *level){
	signed char status;

	// Copy current level board to next level
	memcpy(boards[*level+1], boards[*level], sizeof(board));

	// Place tile to generate a new node
	if ((status = placeTile(boards[*level+1], player, move.tile, move.x, move.y, move.rotation)) != SUCCESS){
		error(status);
		printGameStatus(boards[*level], available_tiles_hero, available_tiles_rival);
		printf ("Level %d (%c%c%c%d): ERROR CREATING A NEW NODE: Invalid move. Aborting game... :(\n", *level, move.x < 9 ? move.x+48+1 : move.x+88, move.y < 9 ? move.y+48+1 : move.y+88, move.tile+97, move.rotation);
		exit(1);
	}

	// Update last_move in 'level'
	last_move[*level].tile     = move.tile;
	last_move[*level].x		   = move.x;
	last_move[*level].y        = move.y;
	last_move[*level].rotation = move.rotation;

	expanded_node[*level] = 1;
	(*level)++;
}

int evaluate_node(unsigned char level, char end_of_game){
	int score_hero = 0, score_rival = 0;
	int acc_hero = 0, acc_rival = 0;
	unsigned char i, j;
	u32 evaluation;

	if (end_of_game){
		for (i = 0; i < 21; i++){
			if (!available_tiles_hero[i])  score_hero  += tiles_score[i];
			if (!available_tiles_rival[i]) score_rival += tiles_score[i];
		}
		if (score_hero > score_rival)
			//return BIG_SCORE + score_hero - score_rival;
			return 900 + score_hero / 2 - score_rival / 2;
		if (score_hero == score_rival)
			return 400;
		//return -BIG_SCORE;
		return 50 + score_hero / 2 - score_rival / 2;

	}
	else{
		#if !USE_HW_ACC
			create_accessibility_map(boards[level], HERO,  available_tiles_hero,  accessibility_map_hero[level]);
			create_accessibility_map(boards[level], RIVAL, available_tiles_rival, accessibility_map_rival[level]);

			// Accessibility score
			for (i = 0; i < 14; i++){
				for (j = 0; j < 14; j++){
					acc_hero  = accessibility_map_hero[level][i][j] != 0 ? acc_hero + 1 : acc_hero;
					acc_rival = accessibility_map_rival[level][i][j] != 0 ? acc_rival + 1 : acc_rival;
				}
			}
		#endif

		#if USE_HW_ACC
			transfer_data_to_HW(level);
			// Wait until computation is done
			do
				evaluation = BLOKUS_ACCELERATOR_STREAM_mReadReg(XPAR_BLOKUS_ACCELERATOR_STREAM_0_S00_AXI_BASEADDR, BLOKUS_ACCELERATOR_STREAM_S00_AXI_SLV_REG1_OFFSET);
			while (!(evaluation & 0x00000001));

			// Read result
			acc_hero  = (evaluation >> 1) & 0x0000007F;
			acc_rival = (evaluation >> 8) & 0x0000007F;
		#endif

		// Tiles score
		for (i = 0; i < 21; i++){
			if (!available_tiles_hero[i])  score_hero  += tiles_score[i];
			if (!available_tiles_rival[i]) score_rival += tiles_score[i];
		}
	}

	// End-game
	if (acc_hero == 0 && acc_rival == 0){
		if (score_hero > score_rival)
			return 900 + score_hero / 2 - score_rival / 2;
		if (score_hero == score_rival)
			return 400;
		//return -BIG_SCORE;
		return 50 + score_hero / 2 - score_rival / 2;
	}
	score_hero += acc_hero;
	score_rival += acc_rival;
	return 400 + score_hero - score_rival;
}

void swap_player(){
	unsigned char i, j;
	char temp_tiles[21];

	for (i=0; i<14; i++){
		for (j=0; j<14; j++){
			if (boards[0][i][j] == SQUARE_RIVAL)		boards[0][i][j] = SQUARE_HERO;
			else if (boards[0][i][j] == SQUARE_HERO)	boards[0][i][j] = SQUARE_RIVAL;
			else if (boards[0][i][j] == FORBIDDEN_RIVAL)boards[0][i][j] = FORBIDDEN_HERO;
			else if (boards[0][i][j] == FORBIDDEN_HERO)	boards[0][i][j] = FORBIDDEN_RIVAL;
		}
	}

	// Temp save hero tiles
	memcpy(temp_tiles, available_tiles_hero, 21*sizeof(char));
	// Swap
	memcpy(available_tiles_hero, available_tiles_rival, 21*sizeof(char));
	memcpy(available_tiles_rival, temp_tiles, 21*sizeof(char));
}

char check_end_game(unsigned char level){
	tp_player player_check_end_game = level % 2 == 0 ? HERO : RIVAL;
	char *tiles = level % 2 == 0 ? available_tiles_hero : available_tiles_rival;
	movement move;

	if (!legal_move(boards[level], player_check_end_game, tiles, level, move_count, &move)){
		initLegalMoveStatus(level);
		return 1;
	}
	initLegalMoveStatus(level);
	return 0;
}


char GET_MOVE(unsigned char current_max_level, unsigned char level, tp_player player, movement *move){
	static char read_best_chain = 0;
	static char read_from_hash = 0;

	#if USE_MEM_L1
		if (current_max_level > 2 && level == 0){
			read_best_chain = 1;
			return get_L1_move(move);
		}
	#endif

	#if USE_BEST_CHAIN
		if ((current_max_level > 2 && level == 1 && read_best_chain) ||
			(current_max_level > 3 && level == 2 && read_best_chain)){
			if (check_end_game(level)){
				read_best_chain = 0;
				read_from_hash = 0;
				return 0;
			}
			read_from_hash = 1;
			get_best_chain(level, move);
			if (level == current_max_level-2)
				read_best_chain = 0;
			
			return 1;
		}
	#endif

	#if USE_MEM_L2
		if (current_max_level > 2 && level == 1){
			#if !USE_BEST_CHAIN
				if (!expanded_node[1]){
					if (check_end_game(level)){
						read_best_chain = 0;
						read_from_hash = 0;
						return 0;
					}
				}
			#endif
			read_from_hash = 1;
			return get_L2_move(move);
		}
	#endif

	#if USE_HASH
		if (current_max_level > 3 && level == 2 && read_from_hash){
			if (check_end_game(level)){
				read_from_hash = 0;
				return 0;
			}
			read_from_hash = 0;
			if (hash_get(level, move_count, move))
				return 1;
		}
	#endif

	if (check_overlapping(level, move_count))
		return get_overlapped_move(boards[level], player, level % 2 == 0 ? available_tiles_hero : available_tiles_rival, level, move_count, move);

	return legal_move(boards[level], player, level % 2 == 0 ? available_tiles_hero : available_tiles_rival, level, move_count, move);
}

char GET_WAITING_MOVE(unsigned char level, tp_player player, movement *move){
	return legal_move(boards[level], player, level % 2 == 0 ? available_tiles_rival : available_tiles_hero, level, move_count, move);
}


signed char process_move(movement *best_move){
	movement move;
	char hero_move_found, rival_move_found;
	unsigned char level = 0;
	tp_player moving_player, waiting_player;

	char stop_searching = 0;
	current_max_level = 2;

	move_count++;

	init_minmax();
	// Check end of game
	hero_move_found = legal_move(boards[0], HERO, available_tiles_hero, 0, move_count, &move);
	init_minmax();
	rival_move_found = legal_move(boards[0], RIVAL, available_tiles_rival, 0, move_count, &move);
	if (!hero_move_found && !rival_move_found)
		return END_OF_GAME;

	// Check if player can move
	if (!hero_move_found)
		return PLAYER_CANNOT_MOVE;

	// To restore legal move status
	init_minmax();

	#define DEBUG 0

	int processed_boards = 0;

	// Clear moves memories
	clear_moves_memories();

	// Clear hash
	hash_clear();

unsigned char dead_vertices_hero, total_vertices_hero, dead_vertices_rival, total_vertices_rival;
search_dead_vertices(boards[0], HERO,  available_tiles_hero,  &dead_vertices_hero,  &total_vertices_hero);
search_dead_vertices(boards[0], RIVAL, available_tiles_rival, &dead_vertices_rival, &total_vertices_rival);

/*
printf("Total vertices hero : %d\n", total_vertices_hero);
printf("Dead vertices hero  : %d (%.1f%%)\n", dead_vertices_hero, (float)(dead_vertices_hero) / (float)(total_vertices_hero));
printf("Total vertices rival: %d\n", total_vertices_rival);
printf("Dead vertices rival : %d (%.1f%%)\n", dead_vertices_rival, (float)(dead_vertices_rival) / (float)(total_vertices_rival));
*/
printf("%.2f\t", (float)(100*(dead_vertices_hero + dead_vertices_rival)) / (float)(total_vertices_hero + total_vertices_rival));


	while (!stop_searching){
		moving_player  = level % 2 == 0 ? HERO  : RIVAL;
		waiting_player = level % 2 == 0 ? RIVAL : HERO;

		// Check if terminal node
		if (level == current_max_level){
			score[level] = evaluate_node(level, 0);
			close_level(&level, best_move);
		}
		else{
			if (PRUNE){
				close_level(&level, best_move);
			}
			else{
				if (GET_MOVE(current_max_level, level, moving_player, &move)){
					create_new_node(move, moving_player, &level);
					processed_boards++;

					// Create overlapping map
					if (level < MAX_LEVEL && check_overlapping(level, move_count))
						create_overlapping_map(level, boards[level], level % 2 == 0 ? available_tiles_rival : available_tiles_hero);
				}
				else{
					// Overlapped move not found
					if (check_overlapping(level, move_count)){
						//  Node was not expanded before: disable overlapping
						if (!expanded_node[level]){
							deactive_overlapping(level);
							initLegalMoveStatus(level);
						}
						// Node was expanded before: all successors created
						else{
							if (level != 0)
								close_level(&level, best_move);
							// Current max_depth tree explored
							else if (level == 0 && current_max_level < MAX_LEVEL){
								current_max_level++;
								init_minmax();
							}
							// MAX_DEPTH tree explored
							else if (level == 0 && current_max_level == MAX_LEVEL){
								stop_searching = 1;
							}
						}
					}
					// Could not make a move
					else{
						pass[level] = !expanded_node[level];
						// End-game
						if (pass[level] && !GET_WAITING_MOVE(level, waiting_player, &move)){
							score[level] = evaluate_node(level, 1);
							close_level(&level, best_move);
						}
						// Node without moves but not end-game: pass
						else if(pass[level]){
							legal_move_status[level].current_vertex.x = -1;
							memcpy(boards[level+1], boards[level], sizeof(board));
							level++;
							processed_boards++;
						}
						// All successors created
						else{
							if (level != 0)
								close_level(&level, best_move);
							// Current max_depth tree explored
							else if (level == 0 && current_max_level < MAX_LEVEL){
								current_max_level++;
								init_minmax();
							}
							// MAX_DEPTH tree explored
							else if (level == 0 && current_max_level == MAX_LEVEL){
								stop_searching = 1;
							}
						}
					}
				}
			}
		}
	}
	#if SHOW_HASH_STATS
		printf_hash_stats();
	#endif
	printf("%d", processed_boards);
}
