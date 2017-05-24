#include "types.h"

static char available(board board, tp_player player, signed char y, signed char x, tp_vertex vertex){
     square forbidden_rival;
     
     // Out of board
     if (vertex.x+x < 0 || vertex.x+x > 13 || vertex.y+y < 0 || vertex.y+y > 13)
       return 0;
       
     forbidden_rival = player == HERO ? FORBIDDEN_RIVAL : FORBIDDEN_HERO;
     	
     if (board[vertex.y+y][vertex.x+x] == SQUARE_FREE || board[vertex.y+y][vertex.x+x] == forbidden_rival)
        return 1;
     
     return 0;
}

static void acc_vertex_0(board board,
                  tp_player player,
                  tp_vertex vertex,
                  char *a2, char *b2,
                  char *a3, char *b3, char *c3, char *d3, char *e3,
                  char *a4, char *b4, char *c4, char *d4, char *e4, char *f4, char *g4, char *h4,
                  char *a5, char *b5, char *c5, char *d5, char *e5, char *f5, char *g5, char *h5, char *i5, char *j5, char *k5, char *l5, char *m5){
    /* Squares availability
	--			   i5
	--          h5 f4 j5
	--       g5 e4 d3 g4 k5
	--    f5 d4 c3 b2 e3 h4 l5
	-- e5 c4 b3 a2 xx    m5  
	--    d5 b4 a3
	--       c5 a4 a5
	--          b5 
	*/

     *a2 = available(board, player,  0,-1, vertex);
     *b2 = available(board, player, -1, 0, vertex);
     *a3 = available(board, player,  1,-1, vertex);
     *b3 = available(board, player,  0,-2, vertex);
     *c3 = available(board, player, -1,-1, vertex);
     *d3 = available(board, player, -2, 0, vertex);
     *e3 = available(board, player, -1, 1, vertex);
     *a4 = available(board, player,  2,-1, vertex);
     *b4 = available(board, player,  1,-2, vertex);
     *c4 = available(board, player,  0,-3, vertex);
     *d4 = available(board, player, -1,-2, vertex);
     *e4 = available(board, player, -2,-1, vertex);
     *f4 = available(board, player, -3, 0, vertex);
     *g4 = available(board, player, -2, 1, vertex);
     *h4 = available(board, player, -1, 2, vertex);
     *a5 = available(board, player,  2, 0, vertex);
     *b5 = available(board, player,  3,-1, vertex);
     *c5 = available(board, player,  2,-2, vertex);
     *d5 = available(board, player,  1,-3, vertex);
     *e5 = available(board, player,  0,-4, vertex);
     *f5 = available(board, player, -1,-3, vertex);
     *g5 = available(board, player, -2,-2, vertex);
     *h5 = available(board, player, -3,-1, vertex);
     *i5 = available(board, player, -4, 0, vertex);
     *j5 = available(board, player, -3, 1, vertex);
     *k5 = available(board, player, -2, 2, vertex);
     *l5 = available(board, player, -1, 3, vertex);
     *m5 = available(board, player,  0, 2, vertex);
}

static void acc_vertex_1(board board,
                  tp_player player,
                  tp_vertex vertex,
                  char *a2, char *b2,
                  char *a3, char *b3, char *c3, char *d3, char *e3,
                  char *a4, char *b4, char *c4, char *d4, char *e4, char *f4, char *g4, char *h4,
                  char *a5, char *b5, char *c5, char *d5, char *e5, char *f5, char *g5, char *h5, char *i5, char *j5, char *k5, char *l5, char *m5){
     /* -- Squares availability
		--			e5
		--       d5 c4 f5
		--    c5 b4 b3 d4 g5
		-- b5 a4 a3 a2 c3 e4 h5
		--    a5    xx b2 d3 f4 i5
		--             e3 g4 j5
		--          m5 h4 k5
		--             l5
     */

     *a2 = available(board, player, -1, 0, vertex);
     *b2 = available(board, player,  0, 1, vertex);
     *a3 = available(board, player, -1,-1, vertex);
     *b3 = available(board, player, -2, 0, vertex);
     *c3 = available(board, player, -1, 1, vertex);
     *d3 = available(board, player,  0, 2, vertex);
     *e3 = available(board, player,  1, 1, vertex);
     *a4 = available(board, player, -1,-2, vertex);
     *b4 = available(board, player, -2,-1, vertex);
     *c4 = available(board, player, -3, 0, vertex);
     *d4 = available(board, player, -2, 1, vertex);
     *e4 = available(board, player, -1, 2, vertex);
     *f4 = available(board, player,  0, 3, vertex);
     *g4 = available(board, player,  1, 2, vertex);
     *h4 = available(board, player,  2, 1, vertex);
     *a5 = available(board, player,  0,-2, vertex);
     *b5 = available(board, player, -1,-3, vertex);
     *c5 = available(board, player, -2,-2, vertex);
     *d5 = available(board, player, -3,-1, vertex);
     *e5 = available(board, player, -4, 0, vertex);
     *f5 = available(board, player, -3, 1, vertex);
     *g5 = available(board, player, -2, 2, vertex);
     *h5 = available(board, player, -1, 3, vertex);
     *i5 = available(board, player,  0, 4, vertex);
     *j5 = available(board, player,  1, 3, vertex);
     *k5 = available(board, player,  2, 2, vertex);
     *l5 = available(board, player,  3, 1, vertex);
     *m5 = available(board, player,  2, 0, vertex);
}

static void acc_vertex_2(board board,
                  tp_player player,
                  tp_vertex vertex,
                  char *a2, char *b2,
                  char *a3, char *b3, char *c3, char *d3, char *e3,
                  char *a4, char *b4, char *c4, char *d4, char *e4, char *f4, char *g4, char *h4,
                  char *a5, char *b5, char *c5, char *d5, char *e5, char *f5, char *g5, char *h5, char *i5, char *j5, char *k5, char *l5, char *m5){
     /*
        -- Squares availability
		--             b5 
		--          a5 a4 c5
		--             a3 b4 d5
		--    m5    xx a2 b3 c4 e5 
		-- l5 h4 e3 b2 c3 d4 f5
		--    k5 g4 d3 e4 g5  
		--       j5 f4 h5
		--			i5
     */

     *a2 = available(board, player,  0, 1, vertex);
     *b2 = available(board, player,  1, 0, vertex);
     *a3 = available(board, player, -1, 1, vertex);
     *b3 = available(board, player,  0, 2, vertex);
     *c3 = available(board, player,  1, 1, vertex);
     *d3 = available(board, player,  2, 0, vertex);
     *e3 = available(board, player,  1,-1, vertex);
     *a4 = available(board, player, -2, 1, vertex);
     *b4 = available(board, player, -1, 2, vertex);
     *c4 = available(board, player,  0, 3, vertex);
     *d4 = available(board, player,  1, 2, vertex);
     *e4 = available(board, player,  2, 1, vertex);
     *f4 = available(board, player,  3, 0, vertex);
     *g4 = available(board, player,  2,-1, vertex);
     *h4 = available(board, player,  1,-2, vertex);
     *a5 = available(board, player, -2, 0, vertex);
     *b5 = available(board, player, -3, 1, vertex);
     *c5 = available(board, player, -2, 2, vertex);
     *d5 = available(board, player, -1, 3, vertex);
     *e5 = available(board, player,  0, 4, vertex);
     *f5 = available(board, player,  1, 3, vertex);
     *g5 = available(board, player,  2, 2, vertex);
     *h5 = available(board, player,  3, 1, vertex);
     *i5 = available(board, player,  4, 0, vertex);
     *j5 = available(board, player,  3,-1, vertex);
     *k5 = available(board, player,  2,-2, vertex);
     *l5 = available(board, player,  1,-3, vertex);
     *m5 = available(board, player,  0,-2, vertex);
}

static void acc_vertex_3(board board,
                  tp_player player,
                  tp_vertex vertex,
                  char *a2, char *b2,
                  char *a3, char *b3, char *c3, char *d3, char *e3,
                  char *a4, char *b4, char *c4, char *d4, char *e4, char *f4, char *g4, char *h4,
                  char *a5, char *b5, char *c5, char *d5, char *e5, char *f5, char *g5, char *h5, char *i5, char *j5, char *k5, char *l5, char *m5){
     /*
        -- Squares availability
		--          l5  
		--       k5 h4 m5 
		--    j5 g4 e3         
		-- i5 f4 d3 b2 xx    a5
		--    h5 e4 c3 a2 a3 a4 b5
		--       g5 d4 b3 b4 c5
		--          f5 c4 d5
		--			   e5
     */

     *a2 = available(board, player,  1, 0, vertex);
     *b2 = available(board, player,  0,-1, vertex);
     *a3 = available(board, player,  1, 1, vertex);
     *b3 = available(board, player,  2, 0, vertex);
     *c3 = available(board, player,  1,-1, vertex);
     *d3 = available(board, player,  0,-2, vertex);
     *e3 = available(board, player, -1,-1, vertex);
     *a4 = available(board, player,  1, 2, vertex);
     *b4 = available(board, player,  2, 1, vertex);
     *c4 = available(board, player,  3, 0, vertex);
     *d4 = available(board, player,  2,-1, vertex);
     *e4 = available(board, player,  1,-2, vertex);
     *f4 = available(board, player,  0,-3, vertex);
     *g4 = available(board, player, -1,-2, vertex);
     *h4 = available(board, player, -2,-1, vertex);
     *a5 = available(board, player,  0, 2, vertex);
     *b5 = available(board, player,  1, 3, vertex);
     *c5 = available(board, player,  2, 2, vertex);
     *d5 = available(board, player,  3, 1, vertex);
     *e5 = available(board, player,  4, 0, vertex);
     *f5 = available(board, player,  3,-1, vertex);
     *g5 = available(board, player,  2,-2, vertex);
     *h5 = available(board, player,  1,-3, vertex);
     *i5 = available(board, player,  0,-4, vertex);
     *j5 = available(board, player, -1,-3, vertex);
     *k5 = available(board, player, -2,-2, vertex);
     *l5 = available(board, player, -3,-1, vertex);
     *m5 = available(board, player, -2, 0, vertex);
}
