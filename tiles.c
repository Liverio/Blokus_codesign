#ifndef TILES_C
#define TILES_C

#include "types.h"
#include "tiles.h"
#include "rotations.h"
#include "error.h"
#include "min_max.h"

extern board boards[MAX_LEVEL+1];
extern char available_tiles_hero[21];
extern char available_tiles_rival[21];

// (x,y) specifies where to place the 'center' of the tile (i.e. pos(2,2) of its matrix)
static signed char placeTile(board board, tp_player player, tiles num_tile, char x, char y, char rotation){
    unsigned char i, j;

    // Place the tile if possible
    for (i=0; i<5; i++){
       for (j=0; j<5; j++){
          if (tile[num_tile][0][(rotations[rotation][i][j])]){
            if ((y+i-2) < 0 || (y+i-2) > 13 || (x+j-2) < 0 || (x+j-2) > 13)
              return TILE_OUT_OF_BOARD;
            if (board[y+i-2][x+j-2] == SQUARE_HERO || board[y+i-2][x+j-2] == SQUARE_RIVAL)
              return TILE_ON_OCCUPIED_SQUARE;
            if ((board[y+i-2][x+j-2] == FORBIDDEN_BOTH) || (player == HERO && board[y+i-2][x+j-2] == FORBIDDEN_HERO) || (player == RIVAL && board[y+i-2][x+j-2] == FORBIDDEN_RIVAL))
              return BORDER_TO_BORDER_CONTACT;

            // Place piece of tile
            board[y+i-2][x+j-2] = player == HERO ? SQUARE_HERO: SQUARE_RIVAL;
          }
       }
    }

    // Mark as forbidden the empty squares where the player cannot place anymore because of border-to-border contact
    for (i=0; i<5; i++){
       for (j=0; j<5; j++){
          if (tile[num_tile][0][(rotations[rotation][i][j])]){
            // Left
            if ((x+j-2)-1 >= 0){
              if (board[y+i-2][(x+j-2)-1] == SQUARE_FREE)
                board[y+i-2][(x+j-2)-1] = player == HERO ? FORBIDDEN_HERO : FORBIDDEN_RIVAL;
              else if ((player == HERO && board[y+i-2][(x+j-2)-1] == FORBIDDEN_RIVAL) || (player == RIVAL && board[y+i-2][(x+j-2)-1] == FORBIDDEN_HERO))
                board[y+i-2][(x+j-2)-1] = FORBIDDEN_BOTH;
            }
            // Right
            if ((x+j-2)+1 <= 13){
              if (board[y+i-2][(x+j-2)+1] == SQUARE_FREE)
                board[y+i-2][(x+j-2)+1] = player == HERO ? FORBIDDEN_HERO : FORBIDDEN_RIVAL;
              else if ((player == HERO && board[y+i-2][(x+j-2)+1] == FORBIDDEN_RIVAL) || (player == RIVAL && board[y+i-2][(x+j-2)+1] == FORBIDDEN_HERO))
                board[y+i-2][(x+j-2)+1] = FORBIDDEN_BOTH;
            }
            // Up
            if ((y+i-2)-1 >= 0){
              if (board[(y+i-2)-1][x+j-2] == SQUARE_FREE)
                board[(y+i-2)-1][x+j-2] = player == HERO ? FORBIDDEN_HERO : FORBIDDEN_RIVAL;
              else if ((player == HERO && board[(y+i-2)-1][x+j-2] == FORBIDDEN_RIVAL) || (player == RIVAL && board[(y+i-2)-1][x+j-2] == FORBIDDEN_HERO))
                board[(y+i-2)-1][x+j-2] = FORBIDDEN_BOTH;
            }
            // Down
            if ((y+i-2)+1 <= 13){
              if (board[(y+i-2)+1][x+j-2] == SQUARE_FREE)
                board[(y+i-2)+1][x+j-2] = player == HERO ? FORBIDDEN_HERO : FORBIDDEN_RIVAL;
              else if ((player == HERO && board[(y+i-2)+1][x+j-2] == FORBIDDEN_RIVAL) || (player == RIVAL && board[(y+i-2)+1][x+j-2] == FORBIDDEN_HERO))
                board[(y+i-2)+1][x+j-2] = FORBIDDEN_BOTH;
            }
          }
       }
    }

    // Remove tile from available tiles
    if (player == HERO)
      available_tiles_hero[num_tile] = 0;
    else
      available_tiles_rival[num_tile] = 0;

    return SUCCESS;
}

#endif
