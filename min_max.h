#ifndef MIN_MAX_H
#define MIN_MAX_H

#include "types.h"

#define MAX_LEVEL 4

#define BIG_SCORE 1000*1000*10
#define PRUNE current_max_level > 2 && level != 0 && ((level % 2 == 0 && score[level] >= score[level-1]) || (level % 2 != 0 && score[level] <= score[level-1]))
static int tiles_score[21] = {2, 4, 6, 6, 8, 8, 8, 8, 8, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10};


#define END_OF_GAME -10
#define PLAYER_CANNOT_MOVE -11

void swap_player();
signed char process_move(movement *best_move);

#endif
