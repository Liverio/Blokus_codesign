#include "move_checkers.h"

tiles move_tile(char pos){
    if (pos <=   1) return tile_u;
    if (pos <=  15) return tile_t;
    if (pos <=  21) return tile_s;
    if (pos <=  28) return tile_r;
    if (pos <=  33) return tile_q;
    if (pos <=  39) return tile_p;
    if (pos <=  51) return tile_o;
    if (pos <=  57) return tile_n;
    if (pos <=  67) return tile_m;
    if (pos <=  79) return tile_l;
    if (pos <=  89) return tile_k;
    if (pos <=  91) return tile_j;
    if (pos <=  97) return tile_i;
    if (pos <=  98) return tile_h;
    if (pos <= 104) return tile_g;
    if (pos <= 114) return tile_f;
    if (pos <= 116) return tile_e;
    if (pos <= 121) return tile_d;
    if (pos <= 123) return tile_c;
    if (pos <= 125) return tile_b;
    return tile_a;
}

char check_size5(tp_player player, tp_vertex vertex, board board, char *tiles, char pos_to_check){
	signed char y_0 = vertex.y+offsets_size5[vertex.type][pos_to_check][0].y;
	signed char y_1 = vertex.y+offsets_size5[vertex.type][pos_to_check][1].y;
	signed char y_2 = vertex.y+offsets_size5[vertex.type][pos_to_check][2].y;
	signed char y_3 = vertex.y+offsets_size5[vertex.type][pos_to_check][3].y;
	signed char x_0 = vertex.x+offsets_size5[vertex.type][pos_to_check][0].x;
	signed char x_1 = vertex.x+offsets_size5[vertex.type][pos_to_check][1].x;
	signed char x_2 = vertex.x+offsets_size5[vertex.type][pos_to_check][2].x;
	signed char x_3 = vertex.x+offsets_size5[vertex.type][pos_to_check][3].x;

	// Tile not available or out of board
    if ((!tiles[move_tile(pos_to_check)])            ||
        (y_0 < 0 || y_0 > 13 || x_0 < 0 || x_0 > 13) ||
        (y_1 < 0 || y_1 > 13 || x_1 < 0 || x_1 > 13) ||
        (y_2 < 0 || y_2 > 13 || x_2 < 0 || x_2 > 13) ||
        (y_3 < 0 || y_3 > 13 || x_3 < 0 || x_3 > 13)
       )
       return 0;

    return ((board[y_0][x_0] == SQUARE_FREE) || ((player == HERO && board[y_0][x_0] == FORBIDDEN_RIVAL) || (player == RIVAL && board[y_0][x_0] == FORBIDDEN_HERO))) &&
		   ((board[y_1][x_1] == SQUARE_FREE) || ((player == HERO && board[y_1][x_1] == FORBIDDEN_RIVAL) || (player == RIVAL && board[y_1][x_1] == FORBIDDEN_HERO))) &&
		   ((board[y_2][x_2] == SQUARE_FREE) || ((player == HERO && board[y_2][x_2] == FORBIDDEN_RIVAL) || (player == RIVAL && board[y_2][x_2] == FORBIDDEN_HERO))) &&
		   ((board[y_3][x_3] == SQUARE_FREE) || ((player == HERO && board[y_3][x_3] == FORBIDDEN_RIVAL) || (player == RIVAL && board[y_3][x_3] == FORBIDDEN_HERO)));

}

char check_size4(tp_player player, tp_vertex vertex, board board, char *tiles, char pos_to_check){
	signed char y_0 = vertex.y+offsets_size4[vertex.type][pos_to_check-92][0].y;
	signed char y_1 = vertex.y+offsets_size4[vertex.type][pos_to_check-92][1].y;
	signed char y_2 = vertex.y+offsets_size4[vertex.type][pos_to_check-92][2].y;
	signed char x_0 = vertex.x+offsets_size4[vertex.type][pos_to_check-92][0].x;
	signed char x_1 = vertex.x+offsets_size4[vertex.type][pos_to_check-92][1].x;
	signed char x_2 = vertex.x+offsets_size4[vertex.type][pos_to_check-92][2].x;

    // Tile not available or out of board
    if ((!tiles[move_tile(pos_to_check)])            ||
        (y_0 < 0 || y_0 > 13 || x_0 < 0 || x_0 > 13) ||
        (y_1 < 0 || y_1 > 13 || x_1 < 0 || x_1 > 13) ||
        (y_2 < 0 || y_2 > 13 || x_2 < 0 || x_2 > 13)
       )
       return 0;

    return ((board[y_0][x_0] == SQUARE_FREE) || ((player == HERO && board[y_0][x_0] == FORBIDDEN_RIVAL) || (player == RIVAL && board[y_0][x_0] == FORBIDDEN_HERO))) &&
		   ((board[y_1][x_1] == SQUARE_FREE) || ((player == HERO && board[y_1][x_1] == FORBIDDEN_RIVAL) || (player == RIVAL && board[y_1][x_1] == FORBIDDEN_HERO))) &&
		   ((board[y_2][x_2] == SQUARE_FREE) || ((player == HERO && board[y_2][x_2] == FORBIDDEN_RIVAL) || (player == RIVAL && board[y_2][x_2] == FORBIDDEN_HERO)));

}

char check_size3(tp_player player, tp_vertex vertex, board board, char *tiles, char pos_to_check){
	signed char y_0 = vertex.y+offsets_size3[vertex.type][pos_to_check-117][0].y;
	signed char y_1 = vertex.y+offsets_size3[vertex.type][pos_to_check-117][1].y;
	signed char x_0 = vertex.x+offsets_size3[vertex.type][pos_to_check-117][0].x;
	signed char x_1 = vertex.x+offsets_size3[vertex.type][pos_to_check-117][1].x;

    // Tile not available or out of board
    if ((!tiles[move_tile(pos_to_check)])            ||
        (y_0 < 0 || y_0 > 13 || x_0 < 0 || x_0 > 13) ||
        (y_1 < 0 || y_1 > 13 || x_1 < 0 || x_1 > 13)
       )
       return 0;

    return ((board[y_0][x_0] == SQUARE_FREE) || ((player == HERO && board[y_0][x_0] == FORBIDDEN_RIVAL) || (player == RIVAL && board[y_0][x_0] == FORBIDDEN_HERO))) &&
		   ((board[y_1][x_1] == SQUARE_FREE) || ((player == HERO && board[y_1][x_1] == FORBIDDEN_RIVAL) || (player == RIVAL && board[y_1][x_1] == FORBIDDEN_HERO)));

}

char check_size2(tp_player player, tp_vertex vertex, board board, char *tiles, char pos_to_check){
	signed char y_0 = vertex.y+offsets_size2[vertex.type][pos_to_check-124][0].y;
	signed char x_0 = vertex.x+offsets_size2[vertex.type][pos_to_check-124][0].x;

    // Tile not available or out of board
    if ((!tiles[move_tile(pos_to_check)])            ||
        (y_0 < 0 || y_0 > 13 || x_0 < 0 || x_0 > 13)
       )
       return 0;

    return ((board[y_0][x_0] == SQUARE_FREE) || ((player == HERO && board[y_0][x_0] == FORBIDDEN_RIVAL) || (player == RIVAL && board[y_0][x_0] == FORBIDDEN_HERO)));

}
