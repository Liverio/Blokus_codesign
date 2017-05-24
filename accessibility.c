#include "min_max.h"
#include "accessibility.h"
#include "vertices.c"
#include "vertex_squares.c"
#include "distance_2.c"
#include "distance_3.c"
#include "distance_4.c"
#include "distance_5.c"

char accessibility_map_hero[MAX_LEVEL+1][14][14];
char accessibility_map_rival[MAX_LEVEL+1][14][14];

// Prototypes
void vertex_processor(board board,
                      tp_player player,
                      char *tiles,
                      tp_vertex vertex,
                      char *acc_a1,
                      char *acc_a2, char *acc_b2,
                      char *acc_a3, char *acc_b3, char *acc_c3, char *acc_d3, char *acc_e3,
                      char *acc_a4, char *acc_b4, char *acc_c4, char *acc_d4, char *acc_e4, char *acc_f4, char *acc_g4, char *acc_h4,
                      char *acc_a5, char *acc_b5, char *acc_c5, char *acc_d5, char *acc_e5, char *acc_f5, char *acc_g5, char *acc_h5, char *acc_i5, char *acc_j5, char *acc_k5, char *acc_l5, char *acc_m5);

void update_map(char map[][14],
                tp_vertex vertex,
                char acc_a1,
                char acc_a2, char acc_b2,
                char acc_a3, char acc_b3, char acc_c3, char acc_d3, char acc_e3,
                char acc_a4, char acc_b4, char acc_c4, char acc_d4, char acc_e4, char acc_f4, char acc_g4, char acc_h4,
                char acc_a5, char acc_b5, char acc_c5, char acc_d5, char acc_e5, char acc_f5, char acc_g5, char acc_h5, char acc_i5, char acc_j5, char acc_k5, char acc_l5, char acc_m5);



void init_accessibility_map(char map[][14]){
	unsigned char i, j;

	for (i=0; i<14; i++)
		for (j=0; j<14; j++)
			map[i][j] = 0;
}

void create_accessibility_map(board board, tp_player player, char *tiles, char map[][14]){
    char acc_a1;
    char acc_a2, acc_b2;
    char acc_a3, acc_b3, acc_c3, acc_d3, acc_e3;
    char acc_a4, acc_b4, acc_c4, acc_d4, acc_e4, acc_f4, acc_g4, acc_h4;
    char acc_a5, acc_b5, acc_c5, acc_d5, acc_e5, acc_f5, acc_g5, acc_h5, acc_i5, acc_j5, acc_k5, acc_l5, acc_m5;

    tp_vertex current_vertex, next_vertex;

    init_accessibility_map(map);

    current_vertex.x = -1;
    // Find accessibility in each vertex
    while (find_vertex(board, player, &current_vertex, &next_vertex)){
    	 vertex_processor(board,
                          player,
                          tiles,
                          vertex_square(next_vertex),
                          &acc_a1,
                          &acc_a2, &acc_b2,
                          &acc_a3, &acc_b3, &acc_c3, &acc_d3, &acc_e3,
                          &acc_a4, &acc_b4, &acc_c4, &acc_d4, &acc_e4, &acc_f4, &acc_g4, &acc_h4,
                          &acc_a5, &acc_b5, &acc_c5, &acc_d5, &acc_e5, &acc_f5, &acc_g5, &acc_h5, &acc_i5, &acc_j5, &acc_k5, &acc_l5, &acc_m5);

         update_map(map, vertex_square(next_vertex),
                    acc_a1,
                    acc_a2, acc_b2,
                    acc_a3, acc_b3, acc_c3, acc_d3, acc_e3,
                    acc_a4, acc_b4, acc_c4, acc_d4, acc_e4, acc_f4, acc_g4, acc_h4,
                    acc_a5, acc_b5, acc_c5, acc_d5, acc_e5, acc_f5, acc_g5, acc_h5, acc_i5, acc_j5, acc_k5, acc_l5, acc_m5);
    }
}

void vertex_processor(board board,
                      tp_player player,
                      char *tiles,
                      tp_vertex vertex,
                      char *acc_a1,
                      char *acc_a2, char *acc_b2,
                      char *acc_a3, char *acc_b3, char *acc_c3, char *acc_d3, char *acc_e3,
                      char *acc_a4, char *acc_b4, char *acc_c4, char *acc_d4, char *acc_e4, char *acc_f4, char *acc_g4, char *acc_h4,
                      char *acc_a5, char *acc_b5, char *acc_c5, char *acc_d5, char *acc_e5, char *acc_f5, char *acc_g5, char *acc_h5, char *acc_i5, char *acc_j5, char *acc_k5, char *acc_l5, char *acc_m5){

     // Free or forbidden_rival
     char a2, b2;
     char a3, b3, c3, d3, e3;
     char a4, b4, c4, d4, e4, f4, g4, h4;
     char a5, b5, c5, d5, e5, f5, g5, h5, i5, j5, k5, l5, m5;

     char ac_a2, ac_b2;

     #define t_A tiles[0]
     #define t_B tiles[1]
     #define t_C tiles[2]
     #define t_D tiles[3]
     #define t_E tiles[4]
     #define t_F tiles[5]
     #define t_G tiles[6]
     #define t_H tiles[7]
     #define t_I tiles[8]
     #define t_J tiles[9]
     #define t_K tiles[10]
     #define t_L tiles[11]
     #define t_M tiles[12]
     #define t_N tiles[13]
     #define t_O tiles[14]
     #define t_P tiles[15]
     #define t_Q tiles[16]
     #define t_R tiles[17]
     #define t_S tiles[18]
     #define t_T tiles[19]
     #define t_U tiles[20]

     switch (vertex.type){
            case 0: acc_vertex_0(board,
                                 player,
                                 vertex,
                                 &a2, &b2,
                                 &a3, &b3, &c3, &d3, &e3,
                                 &a4, &b4, &c4, &d4, &e4, &f4, &g4, &h4,
                                 &a5, &b5, &c5, &d5, &e5, &f5, &g5, &h5, &i5, &j5, &k5, &l5, &m5);
                    break;
            case 1: acc_vertex_1(board,
                                 player,
                                 vertex,
                                 &a2, &b2,
                                 &a3, &b3, &c3, &d3, &e3,
                                 &a4, &b4, &c4, &d4, &e4, &f4, &g4, &h4,
                                 &a5, &b5, &c5, &d5, &e5, &f5, &g5, &h5, &i5, &j5, &k5, &l5, &m5);
                    break;
            case 2: acc_vertex_2(board,
                                 player,
                                 vertex,
                                 &a2, &b2,
                                 &a3, &b3, &c3, &d3, &e3,
                                 &a4, &b4, &c4, &d4, &e4, &f4, &g4, &h4,
                                 &a5, &b5, &c5, &d5, &e5, &f5, &g5, &h5, &i5, &j5, &k5, &l5, &m5);
                    break;
            case 3: acc_vertex_3(board,
                                 player,
                                 vertex,
                                 &a2, &b2,
                                 &a3, &b3, &c3, &d3, &e3,
                                 &a4, &b4, &c4, &d4, &e4, &f4, &g4, &h4,
                                 &a5, &b5, &c5, &d5, &e5, &f5, &g5, &h5, &i5, &j5, &k5, &l5, &m5);
     }


     distance_2(t_B, t_C, t_D, t_E, t_F, t_G, t_H, t_I, t_J, t_K, t_L, t_M, t_N, t_O, t_P, t_Q, t_R, t_S, t_T, t_U,
                a2, b2,
                a3, b3, c3, d3, e3,
                a4, b4, c4, d4, e4, f4, g4, h4,
                a5, b5, c5, d5, e5, f5, g5, h5, i5, j5, k5, l5, m5,
                &ac_a2, &ac_b2);

     distance_3(t_C, t_D, t_E, t_F, t_G, t_H, t_I, t_J, t_K, t_L, t_M, t_N, t_O, t_P, t_Q, t_R, t_S, t_T, t_U,
                a2, b2,
                a3, b3, c3, d3, e3,
                a4, b4, c4, d4, e4, f4, g4, h4,
                a5, b5, c5, d5, e5, f5, g5, h5, i5, j5, k5, l5, m5,
                acc_a3, acc_b3, acc_c3, acc_d3, acc_e3);

     distance_4(t_E, t_F, t_I, t_J, t_K, t_L, t_M, t_N, t_O, t_P, t_Q, t_R, t_S, t_T,
                a2, b2,
                a3, b3, c3, d3, e3,
                a4, b4, c4, d4, e4, f4, g4, h4,
                a5, b5, c5, d5, e5, f5, g5, h5, i5, j5, k5, l5, m5,
                acc_a4, acc_b4, acc_c4, acc_d4, acc_e4, acc_f4, acc_g4, acc_h4);

     distance_5(t_J, t_K, t_L, t_N, t_Q, t_R, t_S,
                a2, b2,
                a3, b3, c3, d3, e3,
                a4, b4, c4, d4, e4, f4, g4, h4,
                a5, b5, c5, d5, e5, f5, g5, h5, i5, j5, k5, l5, m5,
                acc_a5, acc_b5, acc_c5, acc_d5, acc_e5, acc_f5, acc_g5, acc_h5, acc_i5, acc_j5, acc_k5, acc_l5, acc_m5);

    *acc_a2 = ac_a2;
    *acc_b2 = ac_b2;
    *acc_a1 = t_A || ac_a2 || ac_b2;

}

void update_map(char map[][14],
                tp_vertex vertex,
                char acc_a1,
                char acc_a2, char acc_b2,
                char acc_a3, char acc_b3, char acc_c3, char acc_d3, char acc_e3,
                char acc_a4, char acc_b4, char acc_c4, char acc_d4, char acc_e4, char acc_f4, char acc_g4, char acc_h4,
                char acc_a5, char acc_b5, char acc_c5, char acc_d5, char acc_e5, char acc_f5, char acc_g5, char acc_h5, char acc_i5, char acc_j5, char acc_k5, char acc_l5, char acc_m5){

    map[vertex.y+0][vertex.x+0] += acc_a1;

    switch (vertex.type){
           case 0: map[vertex.y+0][vertex.x-1] += acc_a2;
                   map[vertex.y-1][vertex.x+0] += acc_b2;
                   map[vertex.y+1][vertex.x-1] += acc_a3;
                   map[vertex.y+0][vertex.x-2] += acc_b3;
                   map[vertex.y-1][vertex.x-1] += acc_c3;
                   map[vertex.y-2][vertex.x+0] += acc_d3;
                   map[vertex.y-1][vertex.x+1] += acc_e3;
                   map[vertex.y+2][vertex.x-1] += acc_a4;
                   map[vertex.y+1][vertex.x-2] += acc_b4;
                   map[vertex.y+0][vertex.x-3] += acc_c4;
                   map[vertex.y-1][vertex.x-2] += acc_d4;
                   map[vertex.y-2][vertex.x-1] += acc_e4;
                   map[vertex.y-3][vertex.x+0] += acc_f4;
                   map[vertex.y-2][vertex.x+1] += acc_g4;
                   map[vertex.y-1][vertex.x+2] += acc_h4;
                   map[vertex.y+2][vertex.x+0] += acc_a5;
                   map[vertex.y+3][vertex.x-1] += acc_b5;
                   map[vertex.y+2][vertex.x-2] += acc_c5;
                   map[vertex.y+1][vertex.x-3] += acc_d5;
                   map[vertex.y+0][vertex.x-4] += acc_e5;
                   map[vertex.y-1][vertex.x-3] += acc_f5;
                   map[vertex.y-2][vertex.x-2] += acc_g5;
                   map[vertex.y-3][vertex.x-1] += acc_h5;
                   map[vertex.y-4][vertex.x+0] += acc_i5;
                   map[vertex.y-3][vertex.x+1] += acc_j5;
                   map[vertex.y-2][vertex.x+2] += acc_k5;
                   map[vertex.y-1][vertex.x+3] += acc_l5;
                   map[vertex.y+0][vertex.x+2] += acc_m5;
                   break;

           case 1: map[vertex.y-1][vertex.x+0] += acc_a2;
                   map[vertex.y+0][vertex.x+1] += acc_b2;
                   map[vertex.y-1][vertex.x-1] += acc_a3;
                   map[vertex.y-2][vertex.x+0] += acc_b3;
                   map[vertex.y-1][vertex.x+1] += acc_c3;
                   map[vertex.y+0][vertex.x+2] += acc_d3;
                   map[vertex.y+1][vertex.x+1] += acc_e3;
                   map[vertex.y-1][vertex.x-2] += acc_a4;
                   map[vertex.y-2][vertex.x-1] += acc_b4;
                   map[vertex.y-3][vertex.x+0] += acc_c4;
                   map[vertex.y-2][vertex.x+1] += acc_d4;
                   map[vertex.y-1][vertex.x+2] += acc_e4;
                   map[vertex.y+0][vertex.x+3] += acc_f4;
                   map[vertex.y+1][vertex.x+2] += acc_g4;
                   map[vertex.y+2][vertex.x+1] += acc_h4;
                   map[vertex.y+0][vertex.x-2] += acc_a5;
                   map[vertex.y-1][vertex.x-3] += acc_b5;
                   map[vertex.y-2][vertex.x-2] += acc_c5;
                   map[vertex.y-3][vertex.x-1] += acc_d5;
                   map[vertex.y-4][vertex.x+0] += acc_e5;
                   map[vertex.y-3][vertex.x+1] += acc_f5;
                   map[vertex.y-2][vertex.x+2] += acc_g5;
                   map[vertex.y-1][vertex.x+3] += acc_h5;
                   map[vertex.y+0][vertex.x+4] += acc_i5;
                   map[vertex.y+1][vertex.x+3] += acc_j5;
                   map[vertex.y+2][vertex.x+2] += acc_k5;
                   map[vertex.y+3][vertex.x+1] += acc_l5;
                   map[vertex.y+2][vertex.x+0] += acc_m5;
                   break;

           case 2: map[vertex.y+0][vertex.x+1] += acc_a2;
                   map[vertex.y+1][vertex.x+0] += acc_b2;
                   map[vertex.y-1][vertex.x+1] += acc_a3;
                   map[vertex.y+0][vertex.x+2] += acc_b3;
                   map[vertex.y+1][vertex.x+1] += acc_c3;
                   map[vertex.y+2][vertex.x+0] += acc_d3;
                   map[vertex.y+1][vertex.x-1] += acc_e3;
                   map[vertex.y-2][vertex.x+1] += acc_a4;
                   map[vertex.y-1][vertex.x+2] += acc_b4;
                   map[vertex.y+0][vertex.x+3] += acc_c4;
                   map[vertex.y+1][vertex.x+2] += acc_d4;
                   map[vertex.y+2][vertex.x+1] += acc_e4;
                   map[vertex.y+3][vertex.x+0] += acc_f4;
                   map[vertex.y+2][vertex.x-1] += acc_g4;
                   map[vertex.y+1][vertex.x-2] += acc_h4;
                   map[vertex.y-2][vertex.x+0] += acc_a5;
                   map[vertex.y-3][vertex.x+1] += acc_b5;
                   map[vertex.y-2][vertex.x+2] += acc_c5;
                   map[vertex.y-1][vertex.x+3] += acc_d5;
                   map[vertex.y+0][vertex.x+4] += acc_e5;
                   map[vertex.y+1][vertex.x+3] += acc_f5;
                   map[vertex.y+2][vertex.x+2] += acc_g5;
                   map[vertex.y+3][vertex.x+1] += acc_h5;
                   map[vertex.y+4][vertex.x+0] += acc_i5;
                   map[vertex.y+3][vertex.x-1] += acc_j5;
                   map[vertex.y+2][vertex.x-2] += acc_k5;
                   map[vertex.y+1][vertex.x-3] += acc_l5;
                   map[vertex.y+0][vertex.x-2] += acc_m5;
                   break;

           case 3: map[vertex.y+1][vertex.x+0] += acc_a2;
                   map[vertex.y+0][vertex.x-1] += acc_b2;
                   map[vertex.y+1][vertex.x+1] += acc_a3;
                   map[vertex.y+2][vertex.x+0] += acc_b3;
                   map[vertex.y+1][vertex.x-1] += acc_c3;
                   map[vertex.y+0][vertex.x-2] += acc_d3;
                   map[vertex.y-1][vertex.x-1] += acc_e3;
                   map[vertex.y+1][vertex.x+2] += acc_a4;
                   map[vertex.y+2][vertex.x+1] += acc_b4;
                   map[vertex.y+3][vertex.x+0] += acc_c4;
                   map[vertex.y+2][vertex.x-1] += acc_d4;
                   map[vertex.y+1][vertex.x-2] += acc_e4;
                   map[vertex.y+0][vertex.x-3] += acc_f4;
                   map[vertex.y-1][vertex.x-2] += acc_g4;
                   map[vertex.y-2][vertex.x-1] += acc_h4;
                   map[vertex.y+0][vertex.x+2] += acc_a5;
                   map[vertex.y+1][vertex.x+3] += acc_b5;
                   map[vertex.y+2][vertex.x+2] += acc_c5;
                   map[vertex.y+3][vertex.x+1] += acc_d5;
                   map[vertex.y+4][vertex.x+0] += acc_e5;
                   map[vertex.y+3][vertex.x-1] += acc_f5;
                   map[vertex.y+2][vertex.x-2] += acc_g5;
                   map[vertex.y+1][vertex.x-3] += acc_h5;
                   map[vertex.y+0][vertex.x-4] += acc_i5;
                   map[vertex.y-1][vertex.x-3] += acc_j5;
                   map[vertex.y-2][vertex.x-2] += acc_k5;
                   map[vertex.y-3][vertex.x-1] += acc_l5;
                   map[vertex.y-2][vertex.x+0] += acc_m5;
    }
}

// REMOVE
void search_dead_vertices(board board, tp_player player, char *tiles, unsigned char *dead_vertices, unsigned char *total_vertices){
    char acc_a1;
    char acc_a2, acc_b2;
    char acc_a3, acc_b3, acc_c3, acc_d3, acc_e3;
    char acc_a4, acc_b4, acc_c4, acc_d4, acc_e4, acc_f4, acc_g4, acc_h4;
    char acc_a5, acc_b5, acc_c5, acc_d5, acc_e5, acc_f5, acc_g5, acc_h5, acc_i5, acc_j5, acc_k5, acc_l5, acc_m5;

    tp_vertex current_vertex, next_vertex;

    *total_vertices = 0;
    *dead_vertices = 0;

    current_vertex.x = -1;
    // Find accessibility in each vertex
    while (find_vertex(board, player, &current_vertex, &next_vertex)){
    	(*total_vertices)++;

    	 vertex_processor(board,
                          player,
                          tiles,
                          vertex_square(next_vertex),
                          &acc_a1,
                          &acc_a2, &acc_b2,
                          &acc_a3, &acc_b3, &acc_c3, &acc_d3, &acc_e3,
                          &acc_a4, &acc_b4, &acc_c4, &acc_d4, &acc_e4, &acc_f4, &acc_g4, &acc_h4,
                          &acc_a5, &acc_b5, &acc_c5, &acc_d5, &acc_e5, &acc_f5, &acc_g5, &acc_h5, &acc_i5, &acc_j5, &acc_k5, &acc_l5, &acc_m5);

         if (!acc_a1 && !acc_a2 && !acc_b2 &&
        	 !acc_a3 && !acc_b3 && !acc_c3 && !acc_d3 && !acc_e3 &&
        	 !acc_a4 && !acc_b4 && !acc_c4 && !acc_d4 && !acc_e4 && !acc_f4 && !acc_g4 && !acc_h4 &&
             !acc_a5 && !acc_b5 && !acc_c5 && !acc_d5 && !acc_e5 && !acc_f5 && !acc_g5 && !acc_h5 && !acc_i5 && !acc_j5 && !acc_k5 && !acc_l5 && !acc_m5)
        	 (*dead_vertices)++;
    }
}
