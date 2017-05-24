#ifndef ACCESIBILITY_H
#define ACCESIBILITY_H

#include "types.h"

void init_accessibility_map(char map[][14]);
void create_accessibility_map(board board, tp_player player, char *tiles, char map[][14]);
// REMOVE
void search_dead_vertices(board board, tp_player player, char *tiles, unsigned char *dead_vertices, unsigned char *total_vertices);


#endif
