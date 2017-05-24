//#include "accessibility.h"
#include "legal_moves.h"
#include "move_checkers.h"
#include "move_translation.h"
#include "vertices.c"
#include "size_filter.c"

tp_legal_move_status legal_move_status[MAX_LEVEL];   // Last level does not process legal moves

void initLegalMoveStatus(unsigned char level){
    legal_move_status[level].current_vertex.x = -1;
    legal_move_status[level].current_move = -1;
}

// Returns the next legal move within a vertex
char next_move(signed char last_pos, tp_vertex vertex, board board, tp_player player, char *tiles, unsigned char level, unsigned char move_count, unsigned char *move_num){
     unsigned char i;
     unsigned char last_pos_to_explore;

     last_pos_to_explore = size_filter(vertex, board, player, tiles, move_count, level);
     //last_pos_to_explore = 126;

     for (i = last_pos+1; i <= last_pos_to_explore; i++)
         if ((i <= 91  && 			  check_size5(player, vertex, board, tiles, i)) ||
             (i >  91  && i <= 116 && check_size4(player, vertex, board, tiles, i)) ||
             (i > 116  && i <= 123 && check_size3(player, vertex, board, tiles, i)) ||
             (i > 123  && i <= 125 && check_size2(player, vertex, board, tiles, i)) ||
             (i == 126 && tiles[tile_a])
            ){
            *move_num = i;
            return 1;
         }
     return 0;
}

// Returns 1 when a legal move is found. 0 Otherwise
char legal_move(board board, tp_player player, char *tiles, unsigned char level, unsigned char move_count, movement *move){
       unsigned char move_num;
       unsigned char first_request = 0;

       // First legal move request for this node
       if (legal_move_status[level].current_vertex.x == -1){
    	  first_request = 1;
    	  // Board without vertices for this player
          if (!find_vertex(board, player, &legal_move_status[level].current_vertex, &(legal_move_status[level].current_vertex))){
        	  if (first_request)
        		  legal_move_status[level].current_vertex.x = -1;
        	  return 0;
          }          
       }

       // Look for the next move in the current vertex
       if (next_move(legal_move_status[level].current_move, vertex_square(legal_move_status[level].current_vertex), board, player, tiles, level, move_count, &move_num)){
          // Update legal_move_status with the move found
          legal_move_status[level].current_move = move_num;

          // Return the move found
          move->x        = vertex_square(legal_move_status[level].current_vertex).x+move_translations[legal_move_status[level].current_vertex.type][move_num].offset_x;
          move->y        = vertex_square(legal_move_status[level].current_vertex).y+move_translations[legal_move_status[level].current_vertex.type][move_num].offset_y;
          move->tile     = move_translations[legal_move_status[level].current_vertex.type][move_num].tile;
          move->rotation = move_translations[legal_move_status[level].current_vertex.type][move_num].rotation;
          return 1;
       }

       // Check remaining vertices
       while (find_vertex(board, player, &legal_move_status[level].current_vertex, &legal_move_status[level].current_vertex)){
             // Reset move num to explore a new vertex
             legal_move_status[level].current_move = -1;

             if (next_move(legal_move_status[level].current_move, vertex_square(legal_move_status[level].current_vertex), board, player, tiles, level, move_count, &move_num)){
                legal_move_status[level].current_move = move_num;
                // Return the move found
                move->x        = vertex_square(legal_move_status[level].current_vertex).x+move_translations[legal_move_status[level].current_vertex.type][move_num].offset_x;
                move->y        = vertex_square(legal_move_status[level].current_vertex).y+move_translations[legal_move_status[level].current_vertex.type][move_num].offset_y;
			  	move->tile     = move_translations[legal_move_status[level].current_vertex.type][move_num].tile;
			  	move->rotation = move_translations[legal_move_status[level].current_vertex.type][move_num].rotation;
                return 1;
             }
       }
       if (first_request)
    	   legal_move_status[level].current_vertex.x = -1;
       return 0;
}
