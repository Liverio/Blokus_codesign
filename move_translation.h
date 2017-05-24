#ifndef MOVE_TRANSLATION_H
#define MOVE_TRANSLATION_H

typedef struct {
	tiles tile;
	char rotation;
	signed char offset_x;
	signed char offset_y;
} tp_move_translation;

// Vertex type - move_num
static tp_move_translation move_translations[4][127] = {
	// Type 0
	{
		// u
        {tile_u, 0,  0, -1},
        {tile_u, 0, -1,  0},

        // t
        {tile_t, 0,  0, -1},
        {tile_t, 0, -1,  0},
        {tile_t, 1,  0, -1},
        {tile_t, 1, -1,  0},
        {tile_t, 2,  0, -1},
        {tile_t, 2, -1,  1},
        {tile_t, 3,  0, -1},
        {tile_t, 3, -1,  0},
        {tile_t, 4, -1, -1},
        {tile_t, 5,  1, -1},
        {tile_t, 5, -1,  0},
        {tile_t, 6,  0, -1},
        {tile_t, 6, -1,  0},
        {tile_t, 7, -1, -1},

        // s
        {tile_s, 0, -1, -1},
        {tile_s, 1,  1, -1},
        {tile_s, 1, -1,  0},
        {tile_s, 2,  0, -1},
        {tile_s, 2, -1,  1},
        {tile_s, 3, -1, -1},

        // r
        {tile_r, 0, -1, -1},
        {tile_r, 1,  1, -1},
        {tile_r, 1,  0,  0},
        {tile_r, 1, -1,  1},
        {tile_r, 2,  0, -1},
        {tile_r, 2, -1,  0},
        {tile_r, 3, -1, -1},

        // q
        {tile_q, 0, -2,  0},
        {tile_q, 1,  0,  0},
        {tile_q, 2,  0, -2},
        {tile_q, 2, -2,  0},
        {tile_q, 3,  0, -2},

        // p
        {tile_p, 0, -1, -1},
        {tile_p, 2,  1, -1},
        {tile_p, 2, -1,  0},
        {tile_p, 3, -1, -1},
        {tile_p, 4,  0, -1},
        {tile_p, 4, -1,  1},

        // o
        {tile_o, 0,  0, -2},
        {tile_o, 0, -1,  0},
        {tile_o, 1,  0, -2},
        {tile_o, 2,  0, -1},
        {tile_o, 2, -1,  0},
        {tile_o, 3,  0, -1},
        {tile_o, 3, -2,  0},
        {tile_o, 4,  0, -1},
        {tile_o, 5,  0, -1},
        {tile_o, 5, -1,  0},
        {tile_o, 6, -2,  0},
        {tile_o, 7, -1,  0},

        // n
        {tile_n, 0,  0, -1},
        {tile_n, 1, -1, -1},
        {tile_n, 1, -1,  1},
        {tile_n, 2, -1,  0},
        {tile_n, 6,  1, -1},
        {tile_n, 6, -1, -1},

        // m
        {tile_m, 0,  0, -1},
        {tile_m, 1, -1, -1},
        {tile_m, 2, -1,  0},
        {tile_m, 3, -1,  0},
        {tile_m, 4,  0, -1},
        {tile_m, 4, -1,  0},
        {tile_m, 5,  0, -1},
        {tile_m, 6, -1, -1},
        {tile_m, 7,  0, -1},
        {tile_m, 7, -1,  0},

        // l
        {tile_l, 0,  1, -1},
        {tile_l, 0,  0,  0},
        {tile_l, 1, -1, -1},
        {tile_l, 2, -2,  0},
        {tile_l, 3,  0,  0},
        {tile_l, 3, -1,  1},
        {tile_l, 4,  0, -2},
        {tile_l, 4, -1,  0},
        {tile_l, 5,  0, -2},
        {tile_l, 6, -1, -1},
        {tile_l, 7,  0, -1},
        {tile_l, 7, -2,  0},

        // k
        {tile_k, 0,  0, -1},
        {tile_k, 1, -1, -1},
        {tile_k, 2, -2,  0},
        {tile_k, 3, -1,  0},
        {tile_k, 4,  0, -2},
        {tile_k, 4, -1,  1},
        {tile_k, 5,  0, -2},
        {tile_k, 6, -1, -1},
        {tile_k, 7,  1, -1},
        {tile_k, 7, -2,  0},

        // j
        {tile_j, 0,  0, -2},
        {tile_j, 2, -2,  0},

        // i
        {tile_i, 0, -1, -1},
        {tile_i, 1,  0, -1},
        {tile_i, 1, -1,  0},
        {tile_i, 2,  1, -1},
        {tile_i, 2,  0,  0},
        {tile_i, 3, -1, -1},

        // h
        {tile_h, 0, -1, -1},

        // g
        {tile_g, 0,  0, -1},
        {tile_g, 0, -1,  0},
        {tile_g, 1,  0, -1},
        {tile_g, 2,  0, -1},
        {tile_g, 2, -1,  0},
        {tile_g, 6, -1,  0},

        // f
        {tile_f, 0,  0, -1},
        {tile_f, 1, -1, -1},
        {tile_f, 2, -1,  0},
        {tile_f, 3, -1,  0},
        {tile_f, 4,  0, -1},
        {tile_f, 4, -1,  1},
        {tile_f, 5,  0, -1},
        {tile_f, 6, -1, -1},
        {tile_f, 7,  1, -1},
        {tile_f, 7, -1,  0},

        // e
        {tile_e, 0,  0, -2},
        {tile_e, 2, -1,  0},

        // d
        {tile_d, 0, -1,  0},
        {tile_d, 1,  0,  0},
        {tile_d, 2,  0, -1},
        {tile_d, 2, -1,  0},
        {tile_d, 3,  0, -1},

        // c
        {tile_c, 0,  0, -1},
        {tile_c, 2, -1,  0},

        // b
        {tile_b, 0,  0, -1},
        {tile_b, 2,  0,  0},

        // a
        {tile_a, 0,  0,  0}
	},
	// Type 1
	{
		// u
        {tile_u, 0,  0, -1},
        {tile_u, 0,  1,  0},

        // t
        {tile_t, 0,  0, -1},
        {tile_t, 0,  1,  0},
        {tile_t, 1,  0, -1},
        {tile_t, 1,  1,  0},
        {tile_t, 2,  0, -1},
        {tile_t, 2,  1,  0},
        {tile_t, 3,  0, -1},
        {tile_t, 3,  1,  1},
        {tile_t, 4, -1, -1},
        {tile_t, 4,  1,  0},
        {tile_t, 5,  1, -1},
        {tile_t, 6,  1, -1},
        {tile_t, 7,  0, -1},
        {tile_t, 7,  1,  0},

        // s
        {tile_s, 0, -1, -1},
        {tile_s, 0,  1,  0},
        {tile_s, 1,  1, -1},
        {tile_s, 2,  1, -1},
        {tile_s, 3,  0, -1},
        {tile_s, 3,  1,  1},

        // r
        {tile_r, 0, -1, -1},
        {tile_r, 0,  0,  0},
        {tile_r, 0,  1,  1},
        {tile_r, 1,  1, -1},
        {tile_r, 2,  1, -1},
        {tile_r, 3,  0, -1},
        {tile_r, 3,  1,  0},

        // q
        {tile_q, 0,  0,  0},
        {tile_q, 1,  2,  0},
        {tile_q, 2,  0, -2},
        {tile_q, 3,  0, -2},
        {tile_q, 3,  2,  0},

        // p
        {tile_p, 0,  1, -1},
        {tile_p, 2,  1, -1},
        {tile_p, 3, -1, -1},
        {tile_p, 3,  1,  0},
        {tile_p, 4,  0, -1},
        {tile_p, 4,  1,  1},

        // o
        {tile_o, 0,  0, -2},
        {tile_o, 1,  0, -2},
        {tile_o, 1,  1,  0},
        {tile_o, 2,  0, -1},
        {tile_o, 2,  2,  0},
        {tile_o, 3,  0, -1},
        {tile_o, 3,  1,  0},
        {tile_o, 4,  0, -1},
        {tile_o, 4,  1,  0},
        {tile_o, 5,  0, -1},
        {tile_o, 6,  1,  0},
        {tile_o, 7,  2,  0},

        // n
        {tile_n, 0,  1, -1},
        {tile_n, 0,  1,  1},
        {tile_n, 1,  0, -1},
        {tile_n, 2,  1,  0},
        {tile_n, 6,  1, -1},
        {tile_n, 6, -1, -1},

        // m
        {tile_m, 0,  1, -1},
        {tile_m, 1,  0, -1},
        {tile_m, 2,  1,  0},
        {tile_m, 3,  1,  0},
        {tile_m, 4,  0, -1},
        {tile_m, 5,  0, -1},
        {tile_m, 5,  1,  0},
        {tile_m, 6,  0, -1},
        {tile_m, 6,  1,  0},
        {tile_m, 7,  1, -1},

        // l
        {tile_l, 0,  1, -1},
        {tile_l, 1, -1, -1},
        {tile_l, 1,  0,  0},
        {tile_l, 2,  0,  0},
        {tile_l, 2,  1,  1},
        {tile_l, 3,  2,  0},
        {tile_l, 4,  0, -2},
        {tile_l, 5,  0, -2},
        {tile_l, 5,  1,  0},
        {tile_l, 6,  0, -1},
        {tile_l, 6,  2,  0},
        {tile_l, 7,  1, -1},

        // k
        {tile_k, 0,  1, -1},
        {tile_k, 1,  0, -1},
        {tile_k, 2,  1,  0},
        {tile_k, 3,  2,  0},
        {tile_k, 4,  0, -2},
        {tile_k, 5,  0, -2},
        {tile_k, 5,  1,  1},
        {tile_k, 6, -1, -1},
        {tile_k, 6,  2,  0},
        {tile_k, 7,  1, -1},

        // j
        {tile_j, 0,  0, -2},
        {tile_j, 2,  2,  0},

        // i
        {tile_i, 0,  0, -1},
        {tile_i, 0,  1,  0},
        {tile_i, 1,  1, -1},
        {tile_i, 2,  1, -1},
        {tile_i, 3, -1, -1},
        {tile_i, 3,  0,  0},

        // h
        {tile_h, 0,  0, -1},

        // g
        {tile_g, 0,  0, -1},
        {tile_g, 1,  0, -1},
        {tile_g, 1,  1,  0},
        {tile_g, 2,  0, -1},
        {tile_g, 2,  1,  0},
        {tile_g, 6,  1,  0},

        // f
        {tile_f, 0,  1, -1},
        {tile_f, 1,  0, -1},
        {tile_f, 2,  1,  0},
        {tile_f, 3,  1,  0},
        {tile_f, 4,  0, -1},
        {tile_f, 5,  0, -1},
        {tile_f, 5,  1,  1},
        {tile_f, 6, -1, -1},
        {tile_f, 6,  1,  0},
        {tile_f, 7,  1, -1},

        // e
        {tile_e, 0,  0, -2},
        {tile_e, 2,  2,  0},

        // d
        {tile_d, 0,  0,  0},
        {tile_d, 1,  1,  0},
        {tile_d, 2,  0, -1},
        {tile_d, 3,  0, -1},
        {tile_d, 3,  1,  0},

        // c
        {tile_c, 0,  0, -1},
        {tile_c, 2,  1,  0},

        // b
        {tile_b, 0,  0, -1},
        {tile_b, 2,  1,  0},

        // a
        {tile_a, 0,  0,  0}
	},
	// Type 2
	{
		// u
        {tile_u, 0,  1,  0},
        {tile_u, 0,  0,  1},

        // t
        {tile_t, 0,  1,  1},
        {tile_t, 1,  1,  0},
        {tile_t, 1, -1,  1},
        {tile_t, 2,  1,  0},
        {tile_t, 2,  0,  1},
        {tile_t, 3,  1,  1},
        {tile_t, 4,  1,  0},
        {tile_t, 4,  0,  1},
        {tile_t, 5,  1,  0},
        {tile_t, 5,  0,  1},
        {tile_t, 6,  1, -1},
        {tile_t, 6,  0,  1},
        {tile_t, 7,  1,  0},
        {tile_t, 7,  0,  1},

        // s
        {tile_s, 0,  1,  1},
        {tile_s, 1,  1,  0},
        {tile_s, 1, -1,  1},
        {tile_s, 2,  1, -1},
        {tile_s, 2,  0,  1},
        {tile_s, 3,  1,  1},

        // r
        {tile_r, 0,  1,  1},
        {tile_r, 1,  1,  0},
        {tile_r, 1,  0,  1},
        {tile_r, 2,  1, -1},
        {tile_r, 2,  0,  0},
        {tile_r, 2, -1,  1},
        {tile_r, 3,  1,  1},

        // q
        {tile_q, 0,  0,  2},
        {tile_q, 1,  2,  0},
        {tile_q, 1,  0,  2},
        {tile_q, 2,  0,  0},
        {tile_q, 3,  2,  0},

        // p
        {tile_p, 0,  1, -1},
        {tile_p, 0,  0,  1},
        {tile_p, 2,  1,  1},
        {tile_p, 3,  1,  0},
        {tile_p, 3, -1,  1},
        {tile_p, 4,  1,  1},

        // o
        {tile_o, 0,  0,  1},
        {tile_o, 1,  1,  0},
        {tile_o, 1,  0,  1},
        {tile_o, 2,  2,  0},
        {tile_o, 3,  1,  0},
        {tile_o, 4,  1,  0},
        {tile_o, 4,  0,  2},
        {tile_o, 5,  0,  2},
        {tile_o, 6,  1,  0},
        {tile_o, 6,  0,  1},
        {tile_o, 7,  2,  0},
        {tile_o, 7,  0,  1},

        // n
        {tile_n, 0,  1, -1},
        {tile_n, 0,  1,  1},
        {tile_n, 1,  0,  1},
        {tile_n, 2,  1,  1},
        {tile_n, 2, -1,  1},
        {tile_n, 6,  1,  0},

        // m
        {tile_m, 0,  1,  0},
        {tile_m, 0,  0,  1},
        {tile_m, 1,  0,  1},
        {tile_m, 2,  1,  1},
        {tile_m, 3,  1,  0},
        {tile_m, 3,  0,  1},
        {tile_m, 4,  0,  1},
        {tile_m, 5,  1,  1},
        {tile_m, 6,  1,  0},
        {tile_m, 7,  1,  0},

        // l
        {tile_l, 0,  1,  0},
        {tile_l, 0,  0,  2},
        {tile_l, 1,  0,  2},
        {tile_l, 2,  1,  1},
        {tile_l, 3,  2,  0},
        {tile_l, 3,  0,  1},
        {tile_l, 4,  0,  0},
        {tile_l, 4, -1,  1},
        {tile_l, 5,  1,  1},
        {tile_l, 6,  2,  0},
        {tile_l, 7,  1, -1},
        {tile_l, 7,  0,  0},

        // k
        {tile_k, 0,  1, -1},
        {tile_k, 0,  0,  2},
        {tile_k, 1,  0,  2},
        {tile_k, 2,  1,  1},
        {tile_k, 3,  2,  0},
        {tile_k, 3, -1,  1},
        {tile_k, 4,  0,  1},
        {tile_k, 5,  1,  1},
        {tile_k, 6,  2,  0},
        {tile_k, 7,  1,  0},

        // j
        {tile_j, 0,  0,  2},
        {tile_j, 2,  2,  0},

        // i
        {tile_i, 0,  1,  0},
        {tile_i, 1,  1, -1},
        {tile_i, 1,  0,  0},
        {tile_i, 2,  1,  0},
        {tile_i, 2,  0,  1},
        {tile_i, 3,  0,  1},

        // h
        {tile_h, 0,  0,  0},

        // g
        {tile_g, 0,  0,  1},
        {tile_g, 1,  1,  0},
        {tile_g, 1,  0,  1},
        {tile_g, 2,  1,  0},
        {tile_g, 6,  1,  0},
        {tile_g, 6,  0,  1},

        // f
        {tile_f, 0,  1, -1},
        {tile_f, 0,  0,  1},
        {tile_f, 1,  0,  1},
        {tile_f, 2,  1,  1},
        {tile_f, 3,  1,  0},
        {tile_f, 3, -1,  1},
        {tile_f, 4,  0,  1},
        {tile_f, 5,  1,  1},
        {tile_f, 6,  1,  0},
        {tile_f, 7,  1,  0},

        // e
        {tile_e, 0,  0,  1},
        {tile_e, 2,  2,  0},

        // d
        {tile_d, 0,  0,  1},
        {tile_d, 1,  1,  0},
        {tile_d, 1,  0,  1},
        {tile_d, 2,  0,  0},
        {tile_d, 3,  1,  0},

        // c
        {tile_c, 0,  0,  1},
        {tile_c, 2,  1,  0},

        // b
        {tile_b, 0,  0,  0},
        {tile_b, 2,  1,  0},

        // a
        {tile_a, 0,  0,  0}
	},
	// Type 3
	{
		// u
        {tile_u, 0, -1,  0},
        {tile_u, 0,  0,  1},

        // t
        {tile_t, 0, -1,  0},
        {tile_t, 0,  1,  1},
        {tile_t, 1, -1,  1},
        {tile_t, 2, -1,  1},
        {tile_t, 3, -1,  0},
        {tile_t, 3,  0,  1},
        {tile_t, 4, -1,  0},
        {tile_t, 4,  0,  1},
        {tile_t, 5, -1,  0},
        {tile_t, 5,  0,  1},
        {tile_t, 6, -1,  0},
        {tile_t, 6,  0,  1},
        {tile_t, 7, -1, -1},
        {tile_t, 7,  0,  1},

        // s
        {tile_s, 0, -1,  0},
        {tile_s, 0,  1,  1},
        {tile_s, 1, -1,  1},
        {tile_s, 2, -1,  1},
        {tile_s, 3, -1, -1},
        {tile_s, 3,  0,  1},

        // r
        {tile_r, 0, -1,  0},
        {tile_r, 0,  0,  1},
        {tile_r, 1, -1,  1},
        {tile_r, 2, -1,  1},
        {tile_r, 3, -1, -1},
        {tile_r, 3,  0,  0},
        {tile_r, 3,  1,  1},

        // q
        {tile_q, 0, -2,  0},
        {tile_q, 0,  0,  2},
        {tile_q, 1,  0,  2},
        {tile_q, 2, -2,  0},
        {tile_q, 3,  0,  0},

        // p
        {tile_p, 0, -1, -1},
        {tile_p, 0,  0,  1},
        {tile_p, 2, -1,  0},
        {tile_p, 2,  1,  1},
        {tile_p, 3, -1,  1},
        {tile_p, 4, -1,  1},

        // o
        {tile_o, 0, -1,  0},
        {tile_o, 0,  0,  1},
        {tile_o, 1,  0,  1},
        {tile_o, 2, -1,  0},
        {tile_o, 3, -2,  0},
        {tile_o, 4,  0,  2},
        {tile_o, 5, -1,  0},
        {tile_o, 5,  0,  2},
        {tile_o, 6, -2,  0},
        {tile_o, 6,  0,  1},
        {tile_o, 7, -1,  0},
        {tile_o, 7,  0,  1},

        // n
        {tile_n, 0,  0,  1},
        {tile_n, 1, -1, -1},
        {tile_n, 1, -1,  1},
        {tile_n, 2,  1,  1},
        {tile_n, 2, -1,  1},
        {tile_n, 6, -1,  0},

        // m
        {tile_m, 0,  0,  1},
        {tile_m, 1, -1,  0},
        {tile_m, 1,  0,  1},
        {tile_m, 2, -1,  0},
        {tile_m, 2,  0,  1},
        {tile_m, 3, -1,  1},
        {tile_m, 4, -1,  1},
        {tile_m, 5,  0,  1},
        {tile_m, 6, -1,  0},
        {tile_m, 7, -1,  0},

        // l
        {tile_l, 0,  0,  2},
        {tile_l, 1, -1,  0},
        {tile_l, 1,  0,  2},
        {tile_l, 2, -2,  0},
        {tile_l, 2,  0,  1},
        {tile_l, 3, -1,  1},
        {tile_l, 4, -1,  1},
        {tile_l, 5,  0,  0},
        {tile_l, 5,  1,  1},
        {tile_l, 6, -1, -1},
        {tile_l, 6,  0,  0},
        {tile_l, 7, -2,  0},

        // k
        {tile_k, 0,  0,  2},
        {tile_k, 1, -1, -1},
        {tile_k, 1,  0,  2},
        {tile_k, 2, -2,  0},
        {tile_k, 2,  1,  1},
        {tile_k, 3, -1,  1},
        {tile_k, 4, -1,  1},
        {tile_k, 5,  0,  1},
        {tile_k, 6, -1,  0},
        {tile_k, 7, -2,  0},

        // j
        {tile_j, 0,  0,  2},
        {tile_j, 2, -2,  0},

        // i
        {tile_i, 0, -1, -1},
        {tile_i, 0,  0,  0},
        {tile_i, 1, -1,  0},
        {tile_i, 2,  0,  1},
        {tile_i, 3, -1,  0},
        {tile_i, 3,  0,  1},

        // h
        {tile_h, 0, -1,  0},

        // g
        {tile_g, 0, -1,  0},
        {tile_g, 0,  0,  1},
        {tile_g, 1,  0,  1},
        {tile_g, 2, -1,  0},
        {tile_g, 6, -1,  0},
        {tile_g, 6,  0,  1},

        // f
        {tile_f, 0,  0,  1},
        {tile_f, 1, -1, -1},
        {tile_f, 1,  0,  1},
        {tile_f, 2, -1,  0},
        {tile_f, 2,  1,  1},
        {tile_f, 3, -1,  1},
        {tile_f, 4, -1,  1},
        {tile_f, 5,  0,  1},
        {tile_f, 6, -1,  0},
        {tile_f, 7, -1,  0},

        // e
        {tile_e, 0,  0,  1},
        {tile_e, 2, -1,  0},

        // d
        {tile_d, 0, -1,  0},
        {tile_d, 0,  0,  1},
        {tile_d, 1,  0,  1},
        {tile_d, 2, -1,  0},
        {tile_d, 3,  0,  0},

        // c
        {tile_c, 0,  0,  1},
        {tile_c, 2, -1,  0},

        // b
        {tile_b, 0,  0,  0},
        {tile_b, 2,  0,  0},

        // a
        {tile_a, 0,  0,  0}
	}
};

#endif
