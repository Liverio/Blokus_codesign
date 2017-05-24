#ifndef TYPES_H
#define TYPES_H

#include "tiles.h"

// Board
typedef enum {SQUARE_FREE,
              SQUARE_RIVAL,
              SQUARE_HERO,
			  FORBIDDEN_RIVAL,
			  FORBIDDEN_HERO,
			  FORBIDDEN_BOTH
} square;

typedef square board[14][14];

//Player
typedef enum {RIVAL = SQUARE_RIVAL, HERO} tp_player;

typedef struct {
	signed char x;
	signed char y;
	unsigned char type;
} tp_vertex;

typedef struct {
      tiles tile;
      char x;
      char y;
      char rotation;
} movement;

#endif
