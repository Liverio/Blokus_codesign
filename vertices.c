#include <stdio.h>
#include "vertices.h"

// Returns the board square corresponding to a vertex
static tp_vertex vertex_square(tp_vertex vertex){
	tp_vertex translation;
          
	translation.type = vertex.type;
          
	if (vertex.type == 0)
		return vertex;
	if (vertex.type == 1){
		translation.x = vertex.x + 1;
		translation.y = vertex.y;
		translation.type = vertex.type;
		return translation;
	}
	if (vertex.type == 2){
		translation.x = vertex.x + 1;
		translation.y = vertex.y + 1;
		translation.type = vertex.type;
		return translation;
	}
	// Type 3
	translation.x = vertex.x;
	translation.y = vertex.y + 1;
	translation.type = vertex.type;
	return translation;
}

// Returns 1 if next vertex exists, 0 otherwise
static unsigned char find_vertex(board board, tp_player player, tp_vertex *last_vertex, tp_vertex *vertex){
	unsigned char x, y;
	square forbiddenRival;
	tp_vertex next_vertex;

	#define DEBUG 0

	if (player == HERO)
		forbiddenRival = FORBIDDEN_RIVAL;
	else
		forbiddenRival = FORBIDDEN_HERO;

	if (last_vertex->x == -1){
       next_vertex.x = 0;
	   next_vertex.y = 0;
    }
    else{
       next_vertex.x = last_vertex->x < 12 ? last_vertex->x+1 : 0;
	   next_vertex.y = last_vertex->x < 12 ? last_vertex->y   : last_vertex->y+1;
    }
    for (y = next_vertex.y; y < 13; y++){
		for (x = next_vertex.y == y ? next_vertex.x : 0; x < 13; x++){
            // Type 0
			if ((board[y+1][x+1] == player) &&
				(board[y][x] == SQUARE_FREE || board[y][x] == forbiddenRival)){
				vertex->x = x;
				vertex->y = y;
				vertex->type = 0;
				last_vertex->x = x;
				last_vertex->y = y;
				#if DEBUG
					printf("Found vertex {%d %d} type 0\n", y, x);
				#endif				
				return 1;
			}
			// Type 1
			if ((board[y+1][x] == player) &&
				(board[y][x+1] == SQUARE_FREE || board[y][x+1] == forbiddenRival)){
				// DEBUG
				vertex->x = x;
				vertex->y = y;
				vertex->type = 1;
				last_vertex->x = x;
				last_vertex->y = y;
				#if DEBUG
					printf("Found vertex {%d %d} type 1\n", y, x);
				#endif
				return 1;
			}
			// Type 2
			if ((board[y][x] == player) &&
				(board[y+1][x+1] == SQUARE_FREE || board[y+1][x+1] == forbiddenRival)){
				vertex->x = x;
				vertex->y = y;
				vertex->type = 2;
				last_vertex->x = x;
				last_vertex->y = y;
				#if DEBUG
					printf("Found vertex {%d %d} type 2\n", y, x);
				#endif
				return 1;
			}
			// Type 3
			if ((board[y][x+1] == player) &&
				(board[y+1][x] == SQUARE_FREE || board[y+1][x] == forbiddenRival)){
				vertex->x = x;
				vertex->y = y;
				vertex->type = 3;
				last_vertex->x = x;
				last_vertex->y = y;
				#if DEBUG
					printf("Found vertex {%d %d} type 3\n", y, x);
				#endif
				return 1;
			}
		}
	}

    return 0;
}
