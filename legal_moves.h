#ifndef LEGALMOVES_H
#define LEGALMOVES_H

#include "types.h"
#include "min_max.h"

typedef struct {
	tp_vertex current_vertex;
	signed char current_move;
} tp_legal_move_status;

void initLegalMoveStatus(unsigned char level);
char legal_move(board board, tp_player player, char *tiles, unsigned char level, unsigned char move_count, movement *move);


#endif
