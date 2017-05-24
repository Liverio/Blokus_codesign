#ifndef OVERLAPPING_C
#define OVERLAPPING_C

#include "types.h"
#include "min_max.h"
#include "overlapping.h"
#include "tiles.h"
#include "rotations.h"
#include "xaxidma.h"
#include "IO.h"

char expanded_node[MAX_LEVEL];
char overlapping_deactivated[MAX_LEVEL];
static unsigned char threshold;
extern char available_tiles_hero[21];
extern char available_tiles_rival[21];
//unsigned char min_size_to_explore;

// DMA
extern XAxiDma AxiDma;
#define TRANSFER_SIZE_DMA_TO_DEVICE 4*16
#define TRANSFER_SIZE_DEVICE_TO_DMA 4*7
#define USE_HW_ACC 1

void init_overlapping(unsigned char level){
	expanded_node[level] = 0;
	overlapping_deactivated[level] = 0;
}

void deactive_overlapping(unsigned char level){
	overlapping_deactivated[level] = 1;
}

unsigned char set_threshold(unsigned char level, unsigned char move_count){
	if (move_count + level / 2 <= 4)
		return 4;
	else if (move_count + level / 2 <= 7)
		return 3;
	else if (move_count + level / 2 <= 10)
		return 1;
	else
		return 0;
}

char check_overlapping(unsigned char level, unsigned char move_count){
	threshold = set_threshold(level, move_count);

	if (threshold != 0 && !overlapping_deactivated[level])
		return 1;
	return 0;
}
void create_overlapping_map(unsigned char level, board board, char *tiles){
	tp_player player;

	#if !USE_HW_ACC
		init_accessibility_map(overlapping_map[level]);

		player = level % 2 == 0 ? RIVAL : HERO;
		create_accessibility_map(board,  player, tiles, overlapping_map[level]);

		// Mark also forbidden_rival squares
		square forbidden_rival = level % 2 == 0 ? FORBIDDEN_RIVAL : FORBIDDEN_HERO;
		unsigned char i, j;
		for (i = 0; i < 14; i++){
			for (j = 0; j < 14; j++){
				if (board[i][j] == forbidden_rival)
					overlapping_map[level][i][j] = 1;
			}
		}
	#endif

	#if USE_HW_ACC
		u32 row[14+2];
		unsigned char i, j;
		int status;

		// Remove forbidden info from board
		square new_board[14][14];
		for (i = 0; i < 14; i++){
			for (j = 0; j < 14; j++){
				new_board[i][j] = board[i][j] <= SQUARE_HERO ? board[i][j] : SQUARE_FREE;
			}
		}

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

		// Overlapping mode
		row[15] = row[15] | (1 << 21);

		// Rival is '1' in HW
		row[15] = level % 2 == 0 ? row[15] : row[15] | (1 << 22);

		// Data from HW (init here the request to be ready when send_map signal arrives)
		u32 map_from_HW[7];
		status = XAxiDma_SimpleTransfer(&AxiDma,  (u32) map_from_HW, TRANSFER_SIZE_DEVICE_TO_DMA, XAXIDMA_DEVICE_TO_DMA);
		if (status != XST_SUCCESS) {
			printf("Error: DMA transfer from ACC to CPU failed\n");
			return XST_FAILURE;
		}

		// Data to HW
		status = XAxiDma_SimpleTransfer(&AxiDma,  (u32) row, TRANSFER_SIZE_DMA_TO_DEVICE, XAXIDMA_DMA_TO_DEVICE);
		if (status != XST_SUCCESS) {
			printf("Error: DMA transfer from CPU to ACC failed\n");
			return XST_FAILURE;
		}

		// Wait for transfer to be done
		while (XAxiDma_Busy(&AxiDma, XAXIDMA_DEVICE_TO_DMA))
			;

		// Data formatting
		int num_bit;
		i = 0;
		j = 0;
		unsigned char num_row = 0, col = 0;

		for (num_bit = 0; num_bit < 14*14; num_bit++){
			overlapping_map[level][num_row][col] = (map_from_HW[i] >> j) & 1;
			j++;

			if (j == 32){
				i++;
				j = 0;
			}

			col++;
			if (col == 14){
			//if (col % 14 == 0){
				col = 0;
				num_row++;
			}
		}
	#endif

}

char is_overlapped(unsigned char level, movement move){
	unsigned char i, j;

	// Check how many tile squares are overlapped
	unsigned char overlapping = 0;
	for (i=0; i<5; i++){
		for (j=0; j<5; j++){
			if ((tile[ move.tile][0][(rotations[move.rotation][i][j])]) && overlapping_map[level][move.y+i-2][move.x+j-2])
				overlapping++;
		}
	}

	if (overlapping >= threshold)
		return 1;
	return 0;
}

char get_overlapped_move(board board, tp_player player, char *tiles, unsigned char level, unsigned char move_count, movement *move){
	while(legal_move(board, player, tiles, level, move_count, move)){
		if (is_overlapped(level, *move)){
			return 1;
		}
	}
	return 0;
}

#endif
