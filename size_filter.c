#ifndef SIZE_C
#define SIZE_C

#include "move_checkers.h"

static unsigned char max_size_checker(tp_vertex vertex, board board, tp_player player, char *tiles){
	unsigned char i;

	for (i = 0; i <= 91; i++){
		if (check_size5(player, vertex, board, tiles, i))
			return 5;
	}
	for (i = 92; i <= 116; i++){
		if (check_size4(player, vertex, board, tiles, i))
			return 4;
	}
	return 0;
}

// Returns the last position to explore of the moves vector
static unsigned char size_filter(tp_vertex vertex, board board, tp_player player, char *tiles, unsigned char move_count, unsigned char level){
	//unsigned char min_size_to_explore;
	unsigned char size_suggested;

	if (move_count + level / 2 <= 4)
		size_suggested = 5;
	else if (move_count + level / 2 <= 7)
		size_suggested = 4;
	else
		size_suggested = 1;

	unsigned char max_size = max_size_checker(vertex, board, player, tiles);

	if (size_suggested == 5 && max_size == 5)
		return 91;
		/* To be added later min_size_to_explore = 5; */
	else if (size_suggested == 4 && max_size >= 4)
		return 116;
		/* To be added later min_size_to_explore = 4; */
	else
		return 126;
		/* To be added later min_size_to_explore = 1; */
}

#endif
