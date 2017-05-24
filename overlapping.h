#ifndef OVERLAPPING_H
#define OVERLAPPING_H

typedef char tp_overlapping_map[14][14];

static tp_overlapping_map overlapping_map[MAX_LEVEL];

void mark_expanded_node(unsigned char level);
void init_overlapping(unsigned char level);
void deactive_overlapping(unsigned char level);
char check_overlapping(unsigned char level, unsigned char move_count);
void create_overlapping_map(unsigned char level, board board, char *tiles);
char get_overlapped_move(board board, tp_player player, char *tiles, unsigned char level, unsigned char move_count, movement *move);

#endif
