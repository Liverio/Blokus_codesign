#ifndef VERTICES_H
#define VERTICES_H

#include "types.h"

static tp_vertex vertex_square(tp_vertex vertex);
// Returns 0 if next vertex exists
static unsigned char find_vertex(board board, tp_player player, tp_vertex *last_vertex, tp_vertex *vertex);

#endif
