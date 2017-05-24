#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <unistd.h>
#include <fcntl.h>
#include <limits.h>
#include "error.h"
//#include "util.h"
#include "types.h"
#include "tiles.h"
#include "rotations.h"
#include "offsets.h"
#include "legal_moves.h"
#include "IO.h"
#include "accessibility.h"
#include "min_max.h"
#include "tiles.c"

// HW
#include "xbasic_types.h"
#include "xparameters.h"
#include "xaxidma.h"
#include "blokus_accelerator_stream.h"

extern board boards[MAX_LEVEL+1];
extern char available_tiles_hero[21];
extern char available_tiles_rival[21];

// AXI DMA Instance
XAxiDma AxiDma;

int init_DMA(){
	XAxiDma_Config *CfgPtr;
	int status;

	CfgPtr = XAxiDma_LookupConfig(XPAR_AXI_DMA_0_DEVICE_ID);
	if (!CfgPtr){
		print("Error looking for AXI DMA config\n\r");
		return XST_FAILURE;
	}

	status = XAxiDma_CfgInitialize(&AxiDma, CfgPtr);
	if (status != XST_SUCCESS){
		printf("Error initializing DMA\n\r");
		return XST_FAILURE;
	}

	// Disable interrupts, we use polling mode
	XAxiDma_IntrDisable(&AxiDma, XAXIDMA_IRQ_ALL_MASK, XAXIDMA_DMA_TO_DEVICE);
	XAxiDma_IntrDisable(&AxiDma, XAXIDMA_IRQ_ALL_MASK, XAXIDMA_DEVICE_TO_DMA);

	return XST_SUCCESS;
}

void get_time(){
	#define FREQ 100000000
	u32 time_1, time_2;

	time_1 = BLOKUS_ACCELERATOR_STREAM_mReadReg(XPAR_BLOKUS_ACCELERATOR_STREAM_0_S00_AXI_BASEADDR, BLOKUS_ACCELERATOR_STREAM_S00_AXI_SLV_REG2_OFFSET);
	time_2 = BLOKUS_ACCELERATOR_STREAM_mReadReg(XPAR_BLOKUS_ACCELERATOR_STREAM_0_S00_AXI_BASEADDR, BLOKUS_ACCELERATOR_STREAM_S00_AXI_SLV_REG3_OFFSET);

	float time_in_seconds = ((float)(time_2) * 42.95) + ((float)(time_1) / (float)(FREQ));

	printf("Game took: %.1f seconds\n\r", time_in_seconds);

	return ;
}


int main(int argc, char* argv[]){
	int i, j, k;
	signed char process_result;
	movement best_move;

	if (init_DMA() != XST_SUCCESS){
		printf("Error: DMA init failed\n");
		return XST_FAILURE;
	}

	printf("DMA init done\n");

	// Boards initialization
	for (i=0; i<MAX_LEVEL+1; i++)
	   for (j=0; j<14; j++)
		  for (k=0; k<14; k++)
			 boards[i][j][k] = SQUARE_FREE;

	// Tiles initialization
	for (i = 0; i < 21; i++){
	   available_tiles_hero[i] = 1;
	   available_tiles_rival[i] = 1;
	}

	// Place initial tiles
	placeTile(boards[0], HERO, tile_u, 5, 4, 0);
	placeTile(boards[0], RIVAL, tile_u, 8, 9, 0);

	printGameStatus(boards[0], available_tiles_hero, available_tiles_rival);

	// Set new_game flag to start time measuring
	BLOKUS_ACCELERATOR_STREAM_mWriteReg(XPAR_BLOKUS_ACCELERATOR_STREAM_0_S00_AXI_BASEADDR, BLOKUS_ACCELERATOR_STREAM_S00_AXI_SLV_REG0_OFFSET, 1);

	while(1){
		process_result = process_move(&best_move);
		if (process_result == PLAYER_CANNOT_MOVE){
			printf("0\tPass\n");
			swap_player();
		}
		else if (process_result == END_OF_GAME){
			printf("\n\nGAME OVER!\n");
			// Reset new_game flag to stop time measuring
			BLOKUS_ACCELERATOR_STREAM_mWriteReg(XPAR_BLOKUS_ACCELERATOR_STREAM_0_S00_AXI_BASEADDR, BLOKUS_ACCELERATOR_STREAM_S00_AXI_SLV_REG0_OFFSET, 0);
			// Get time from FPGA
			get_time();
			return 0;
		}
		else{
			printf("\t%c%c%c%d\n", best_move.x < 9 ? best_move.x+48+1 : best_move.x+88, best_move.y < 9 ? best_move.y+48+1 : best_move.y+88, best_move.tile+97, best_move.rotation);
			placeTile(boards[0], HERO, best_move.tile, best_move.x, best_move.y, best_move.rotation);
			swap_player();
		}
	}
}


#ifdef _MSC_VER
#define slocal static __forceinline
#else
#define slocal static
#endif
