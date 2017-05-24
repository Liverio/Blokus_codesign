#ifndef OFFSETS_H
#define OFFSETS_H

/*
************************************************************************************
* Offset of the 'center' each tile and rotation with regard to each type of vertex *
************************************************************************************
*/
/*
*************
* Rotations *
*************
*   y  
*   |
*   - x
*  /
* z
*  + is clockwise
*  - is anti-clockwise
* (xy plane, xz plane)
* 0) (  0, 0)
* 1) (  0, 180)
* 2) (+90, 0)
* 3) (+90, 180)
* 4) (180, 0)
* 5) (180, 180)
* 6) (-90, 0)
* 7) (-90, 180)

* **** f ****
* 0)       1)       2)       3)       4)       5)       6)       7)
*    o       o        o          o      oo       oo       oxo      oxo
*    x       x        oxo      oxo      x         x         o      o
*   oo       oo                         o         o
*
* **** g ****
* 0)       1)       2)       3)       4)       5)       6)       7)
*   o         o       oxo      oxo       o       o         o        o
*   xo       ox        o        o       ox       xo       oxo      oxo
*   o         o                          o       o    
*
* **** h ****
* 0)       1)       2)       3)       4)       5)       6)       7)
*   xo       ox       ox       xo       oo       oo       oo       oo
*   oo       oo       oo       oo       ox       xo       xo       ox
*
* **** i ****
* 0)       1)       2)       3)       4)       5)       6)       7)
*   ox        xo       o       o        oo        oo       o       o
*    oo      oo       ox       xo        xo      ox       xo       ox
*                     o         o                         o         o    
* **** j ****
* 0)       1)       2)       3)       4)       5)       6)       7)
*   o        o        ooxoo    ooxxoo   o        o        ooxoo    ooxoo
*   o        o                          o        o
*   x        x                          x        x
*   o        o                          o        o
*   o        o                          o        o
*
* **** k ****
* 0)       1)       2)       3)       4)       5)       6)       7)
*    o       o        o           o     oo       oo       ooxo     oxoo
*    o       o        oxoo     ooxo     x         x          o     o
*    x       x                          o         o
*   oo       oo                         o         o
*
* **** l ****
* 0)       1)       2)       3)       4)       5)       6)       7)
*    o       o        oo         oo      o       o        oox       xoo
*    o       o         xoo     oox      xo       ox         oo     oo
*   ox       xo                         o         o
*   o         o                         o         o
*
* **** m ****
* 0)       1)       2)       3)       4)       5)       6)       7)
*    o       o        oo        oo      oo       oo       oxo      oxo
*   ox       xo       oxo      oxo      xo       ox        oo      oo
*   oo       oo                         o         o
*
* **** n ****
* 0)       1)       2)       3)       4)       5)       6)       7)
*   oo       oo       o o      o o      oo       oo       oxo      oxo
*    x       x        oxo      oxo      x         x       o o      o o
*   oo       oo                         oo       oo
*
*
*
*
*
* **** q ****
* 0)       1)       2)       3)       4)       5)       6)       7)
*   o          o      xoo      oox      oox      xoo        o      o
*   o          o      o          o        o      o          o      o
*   xoo      oox      o          o        o      o        oox      xoo
*
* **** r ****
* 0)       1)       2)       3)       4)       5)       6)       7)
*   oo        oo        o      o        o          o       oo      oo
*    xo      ox        xo      ox       ox        xo      ox        xo
*     o      o        oo        oo       oo      oo       o          o
*

*/

#define NU 99	/* to identify how many offsets to evaluate and also for friendly view of Non-Used offsets */
typedef struct{
	char x1_offset, y1_offset;
	char x2_offset, y2_offset;
	char x3_offset, y3_offset;
} tpOffset;

static tpOffset offset[21][8][4] = {	// [tile][rotation][vertex]{x1_offset, y1_offset, x2_offset, y2_offset, x3_offset, y3_offset}
  /***** Monomino *****/
  // a
  {
    {{ 0, 0,NU,NU,NU,NU}, { 0, 0,NU,NU,NU,NU}, { 0, 0,NU,NU,NU,NU}, { 0, 0,NU,NU,NU,NU}},
    {{ 0, 0,NU,NU,NU,NU}, { 0, 0,NU,NU,NU,NU}, { 0, 0,NU,NU,NU,NU}, { 0, 0,NU,NU,NU,NU}},
    {{ 0, 0,NU,NU,NU,NU}, { 0, 0,NU,NU,NU,NU}, { 0, 0,NU,NU,NU,NU}, { 0, 0,NU,NU,NU,NU}},
    {{ 0, 0,NU,NU,NU,NU}, { 0, 0,NU,NU,NU,NU}, { 0, 0,NU,NU,NU,NU}, { 0, 0,NU,NU,NU,NU}},
    {{ 0, 0,NU,NU,NU,NU}, { 0, 0,NU,NU,NU,NU}, { 0, 0,NU,NU,NU,NU}, { 0, 0,NU,NU,NU,NU}},
    {{ 0, 0,NU,NU,NU,NU}, { 0, 0,NU,NU,NU,NU}, { 0, 0,NU,NU,NU,NU}, { 0, 0,NU,NU,NU,NU}},
    {{ 0, 0,NU,NU,NU,NU}, { 0, 0,NU,NU,NU,NU}, { 0, 0,NU,NU,NU,NU}, { 0, 0,NU,NU,NU,NU}},
    {{ 0, 0,NU,NU,NU,NU}, { 0, 0,NU,NU,NU,NU}, { 0, 0,NU,NU,NU,NU}, { 0, 0,NU,NU,NU,NU}}  
  },
  
  
  /***** Domino *****/  
  // b
  {
    {{ 0,-1,NU,NU,NU,NU}, { 0,-1,NU,NU,NU,NU}, { 0, 0,NU,NU,NU,NU}, { 0, 0,NU,NU,NU,NU}},
    {{ 0,-1,NU,NU,NU,NU}, { 0,-1,NU,NU,NU,NU}, { 0, 0,NU,NU,NU,NU}, { 0, 0,NU,NU,NU,NU}},
    {{ 0, 0,NU,NU,NU,NU}, { 1, 0,NU,NU,NU,NU}, { 1, 0,NU,NU,NU,NU}, { 0, 0,NU,NU,NU,NU}},
    {{ 1, 0,NU,NU,NU,NU}, { 0, 0,NU,NU,NU,NU}, { 0, 0,NU,NU,NU,NU}, { 1, 0,NU,NU,NU,NU}},
    {{ 0, 0,NU,NU,NU,NU}, { 0, 0,NU,NU,NU,NU}, { 0, 1,NU,NU,NU,NU}, { 0, 1,NU,NU,NU,NU}},
    {{ 0, 0,NU,NU,NU,NU}, { 0, 0,NU,NU,NU,NU}, { 0, 1,NU,NU,NU,NU}, { 0, 1,NU,NU,NU,NU}},
    {{-1, 0,NU,NU,NU,NU}, { 0, 0,NU,NU,NU,NU}, { 0, 0,NU,NU,NU,NU}, {-1, 0,NU,NU,NU,NU}},
    {{ 0, 0,NU,NU,NU,NU}, { 1, 0,NU,NU,NU,NU}, { 1, 0,NU,NU,NU,NU}, { 0, 0,NU,NU,NU,NU}}  
  },
  
  
  /***** Trominoes *****/
  // c
  {
    {{ 0,-1,NU,NU,NU,NU}, { 0,-1,NU,NU,NU,NU}, { 0, 1,NU,NU,NU,NU}, { 0, 1,NU,NU,NU,NU}},
    {{ 0,-1,NU,NU,NU,NU}, { 0,-1,NU,NU,NU,NU}, { 0, 1,NU,NU,NU,NU}, { 0, 1,NU,NU,NU,NU}},
    {{-1, 0,NU,NU,NU,NU}, { 1, 0,NU,NU,NU,NU}, { 1, 0,NU,NU,NU,NU}, {-1, 0,NU,NU,NU,NU}},
    {{-1, 0,NU,NU,NU,NU}, { 1, 0,NU,NU,NU,NU}, { 1, 0,NU,NU,NU,NU}, {-1, 0,NU,NU,NU,NU}},
    {{ 0,-1,NU,NU,NU,NU}, { 0,-1,NU,NU,NU,NU}, { 0, 1,NU,NU,NU,NU}, { 0, 1,NU,NU,NU,NU}},
    {{ 0,-1,NU,NU,NU,NU}, { 0,-1,NU,NU,NU,NU}, { 0, 1,NU,NU,NU,NU}, { 0, 1,NU,NU,NU,NU}},
    {{-1, 0,NU,NU,NU,NU}, { 1, 0,NU,NU,NU,NU}, { 1, 0,NU,NU,NU,NU}, {-1, 0,NU,NU,NU,NU}},
    {{-1, 0,NU,NU,NU,NU}, { 1, 0,NU,NU,NU,NU}, { 1, 0,NU,NU,NU,NU}, {-1, 0,NU,NU,NU,NU}}  
  },
  
  
  // d
  {
    {{-1, 0,NU,NU,NU,NU}, { 0, 0,NU,NU,NU,NU}, { 0, 1,NU,NU,NU,NU}, { 0, 1,-1, 0,NU,NU}},
    {{ 0, 0,NU,NU,NU,NU}, { 1, 0,NU,NU,NU,NU}, { 0, 1, 1, 0,NU,NU}, { 0, 1,NU,NU,NU,NU}},
    {{-1, 0, 0,-1,NU,NU}, { 0,-1,NU,NU,NU,NU}, { 0, 0,NU,NU,NU,NU}, {-1, 0,NU,NU,NU,NU}},
    {{ 0,-1,NU,NU,NU,NU}, { 1, 0, 0,-1,NU,NU}, { 1, 0,NU,NU,NU,NU}, { 0, 0,NU,NU,NU,NU}},
    {{ 0,-1,NU,NU,NU,NU}, { 1, 0, 0,-1,NU,NU}, { 1, 0,NU,NU,NU,NU}, { 0, 0,NU,NU,NU,NU}},
    {{-1, 0, 0,-1,NU,NU}, { 0,-1,NU,NU,NU,NU}, { 0, 0,NU,NU,NU,NU}, {-1, 0,NU,NU,NU,NU}},
    {{ 0, 0,NU,NU,NU,NU}, { 1, 0,NU,NU,NU,NU}, { 0, 1, 1, 0,NU,NU}, { 0, 1,NU,NU,NU,NU}},
    {{-1, 0,NU,NU,NU,NU}, { 0, 0,NU,NU,NU,NU}, { 0, 1,NU,NU,NU,NU}, { 0, 1,-1, 0,NU,NU}},
  },
  
  
  /***** Tetrominodes *****/
  // e
  {
    {{ 0,-2,NU,NU,NU,NU}, { 0,-2,NU,NU,NU,NU}, { 0, 1,NU,NU,NU,NU}, { 0, 1,NU,NU,NU,NU}},
    {{ 0,-2,NU,NU,NU,NU}, { 0,-2,NU,NU,NU,NU}, { 0, 1,NU,NU,NU,NU}, { 0, 1,NU,NU,NU,NU}},
    {{-1, 0,NU,NU,NU,NU}, { 2, 0,NU,NU,NU,NU}, { 2, 0,NU,NU,NU,NU}, {-1, 0,NU,NU,NU,NU}},
    {{-2, 0,NU,NU,NU,NU}, { 1, 0,NU,NU,NU,NU}, { 1, 0,NU,NU,NU,NU}, {-2, 0,NU,NU,NU,NU}},
    {{ 0,-1,NU,NU,NU,NU}, { 0,-1,NU,NU,NU,NU}, { 0, 2,NU,NU,NU,NU}, { 0, 2,NU,NU,NU,NU}},
    {{ 0,-1,NU,NU,NU,NU}, { 0,-1,NU,NU,NU,NU}, { 0, 2,NU,NU,NU,NU}, { 0, 2,NU,NU,NU,NU}},
    {{-2, 0,NU,NU,NU,NU}, { 1, 0,NU,NU,NU,NU}, { 1, 0,NU,NU,NU,NU}, {-2, 0,NU,NU,NU,NU}},
    {{-1, 0,NU,NU,NU,NU}, { 2, 0,NU,NU,NU,NU}, { 2, 0,NU,NU,NU,NU}, {-1, 0,NU,NU,NU,NU}}
  },
  
  
  // f
  {
    {{ 0,-1,NU,NU,NU,NU}, { 1,-1,NU,NU,NU,NU}, { 0, 1, 1,-1,NU,NU}, { 0, 1,NU,NU,NU,NU}},	/* Vertex 2 {upper, bottom-left} */
    {{-1,-1,NU,NU,NU,NU}, { 0,-1,NU,NU,NU,NU}, { 0, 1,NU,NU,NU,NU}, { 0, 1,-1,-1,NU,NU}},	/* Vertex 3 {upper, bottom-right} */
    {{-1, 0,NU,NU,NU,NU}, { 1, 0,NU,NU,NU,NU}, { 1, 1,NU,NU,NU,NU}, { 1, 1,-1, 0,NU,NU}},	/* Vertex 3 {upper, bottom-right} */
    {{-1, 0,NU,NU,NU,NU}, { 1, 0,NU,NU,NU,NU}, {-1, 1, 1, 0,NU,NU}, {-1, 1,NU,NU,NU,NU}},	/* Vertex 2 {upper, bottom-left} */
    {{-1, 1, 0,-1,NU,NU}, { 0,-1,NU,NU,NU,NU}, { 0, 1,NU,NU,NU,NU}, {-1, 1,NU,NU,NU,NU}},	/* Vertex 0 {upper-right, bottom} */
    {{ 0,-1,NU,NU,NU,NU}, { 1, 1, 0,-1,NU,NU}, { 1, 1,NU,NU,NU,NU}, { 0, 1,NU,NU,NU,NU}},	/* Vertex 1 {upper-left, bottom} */
    {{-1,-1,NU,NU,NU,NU}, { 1, 0,-1,-1,NU,NU}, { 1, 0,NU,NU,NU,NU}, {-1, 0,NU,NU,NU,NU}},	/* Vertex 1 {upper-left, bottom} */
    {{-1, 0, 1,-1,NU,NU}, { 1,-1,NU,NU,NU,NU}, { 1, 0,NU,NU,NU,NU}, {-1, 0,NU,NU,NU,NU}}	/* Vertex 0 {upper-right, bottom} */  
  },
  
  
  // g
  {
    {{-1, 0, 0,-1,NU,NU}, { 0,-1,NU,NU,NU,NU}, { 0, 1,NU,NU,NU,NU}, { 0, 1,-1, 0,NU,NU}},	/* Vertex 0 {mid, bottom} 		Vertex 3 {upper, mid} */
    {{ 0,-1,NU,NU,NU,NU}, { 1, 0, 0,-1,NU,NU}, { 0, 1, 1, 0,NU,NU}, { 0, 1,NU,NU,NU,NU}},	/* Vertex 1 {mid, bottom} 		Vertex 2 {upper, mid} */
    {{-1, 0, 0,-1,NU,NU}, { 1, 0, 0,-1,NU,NU}, { 1, 0,NU,NU,NU,NU}, {-1, 0,NU,NU,NU,NU}},	/* Vertex 0 {upper-right, bottom} 	Vertex 1 {upper-left, bottom} */
    {{-1, 0, 0,-1,NU,NU}, { 1, 0, 0,-1,NU,NU}, { 1, 0,NU,NU,NU,NU}, {-1, 0,NU,NU,NU,NU}},	/* Vertex 0 {upper-right, bottom} 	Vertex 1 {upper-left, bottom} */
    {{ 0,-1,NU,NU,NU,NU}, { 1, 0, 0,-1,NU,NU}, { 0, 1, 1, 0,NU,NU}, { 0, 1,NU,NU,NU,NU}},	/* Vertex 1 {mid, bottom} 		Vertex 2 {upper, mid} */
    {{-1, 0, 0,-1,NU,NU}, { 0,-1,NU,NU,NU,NU}, { 0, 1,NU,NU,NU,NU}, { 0, 1,-1, 0,NU,NU}},	/* Vertex 0 {mid, bottom} 		Vertex 3 {upper, mid} */
    {{-1, 0,NU,NU,NU,NU}, { 1, 0,NU,NU,NU,NU}, { 0, 1, 1, 0,NU,NU}, { 0, 1,-1, 0,NU,NU}},	/* Vertex 2 {upper, bottom-left} 	Vertex 3 {upper, bottom-right} */
    {{-1, 0,NU,NU,NU,NU}, { 1, 0,NU,NU,NU,NU}, { 0, 1, 1, 0,NU,NU}, { 0, 1,-1, 0,NU,NU}}	/* Vertex 2 {upper, bottom-left} 	Vertex 3 {upper, bottom-right} */  
  },
  
  
  // h
  {
    {{-1,-1,NU,NU,NU,NU}, { 0,-1,NU,NU,NU,NU}, { 0, 0,NU,NU,NU,NU}, {-1, 0,NU,NU,NU,NU}},
    {{ 0,-1,NU,NU,NU,NU}, { 1,-1,NU,NU,NU,NU}, { 1, 0,NU,NU,NU,NU}, { 0, 0,NU,NU,NU,NU}},
    {{ 0,-1,NU,NU,NU,NU}, { 1,-1,NU,NU,NU,NU}, { 1, 0,NU,NU,NU,NU}, { 0, 0,NU,NU,NU,NU}},
    {{-1,-1,NU,NU,NU,NU}, { 0,-1,NU,NU,NU,NU}, { 0, 0,NU,NU,NU,NU}, {-1, 0,NU,NU,NU,NU}},
    {{ 0, 0,NU,NU,NU,NU}, { 1, 0,NU,NU,NU,NU}, { 1, 1,NU,NU,NU,NU}, { 0, 1,NU,NU,NU,NU}},
    {{-1, 0,NU,NU,NU,NU}, { 0, 0,NU,NU,NU,NU}, { 0, 1,NU,NU,NU,NU}, {-1, 1,NU,NU,NU,NU}},
    {{-1, 0,NU,NU,NU,NU}, { 0, 0,NU,NU,NU,NU}, { 0, 1,NU,NU,NU,NU}, {-1, 1,NU,NU,NU,NU}},
    {{ 0, 0,NU,NU,NU,NU}, { 1, 0,NU,NU,NU,NU}, { 1, 1,NU,NU,NU,NU}, { 0, 1,NU,NU,NU,NU}}
  },
  
  
  // i
  {
    {{-1,-1,NU,NU,NU,NU}, { 1, 0, 0,-1,NU,NU}, { 1, 0,NU,NU,NU,NU}, { 0, 0,-1,-1,NU,NU}},
    {{-1, 0, 0,-1,NU,NU}, { 1,-1,NU,NU,NU,NU}, { 0, 0, 1,-1,NU,NU}, {-1, 0,NU,NU,NU,NU}},
    {{ 0, 0, 1,-1,NU,NU}, { 1,-1,NU,NU,NU,NU}, { 0, 1, 1, 0,NU,NU}, { 0, 1,NU,NU,NU,NU}},
    {{-1,-1,NU,NU,NU,NU}, { 0, 0,-1,-1,NU,NU}, { 0, 1,NU,NU,NU,NU}, { 0, 1,-1, 0,NU,NU}},
    {{-1, 0,NU,NU,NU,NU}, { 1, 1, 0, 0,NU,NU}, { 1, 1,NU,NU,NU,NU}, { 0, 1,-1, 0,NU,NU}},
    {{-1, 1, 0, 0,NU,NU}, { 1, 0,NU,NU,NU,NU}, { 0, 1, 1, 0,NU,NU}, {-1, 1,NU,NU,NU,NU}},
    {{-1, 0, 0,-1,NU,NU}, { 0,-1,NU,NU,NU,NU}, {-1, 1, 0, 0,NU,NU}, {-1, 1,NU,NU,NU,NU}},
    {{ 0,-1,NU,NU,NU,NU}, { 1, 0, 0,-1,NU,NU}, { 1, 1,NU,NU,NU,NU}, { 1, 1, 0, 0,NU,NU}}
  },
  
  
  /***** Pentominoes *****/
  // j
  {
    {{ 0,-2,NU,NU,NU,NU}, { 0,-2,NU,NU,NU,NU}, { 0, 2,NU,NU,NU,NU}, { 0, 2,NU,NU,NU,NU}},
    {{ 0,-2,NU,NU,NU,NU}, { 0,-2,NU,NU,NU,NU}, { 0, 2,NU,NU,NU,NU}, { 0, 2,NU,NU,NU,NU}},
    {{-2, 0,NU,NU,NU,NU}, { 2, 0,NU,NU,NU,NU}, { 2, 0,NU,NU,NU,NU}, {-2, 0,NU,NU,NU,NU}},
    {{-2, 0,NU,NU,NU,NU}, { 2, 0,NU,NU,NU,NU}, { 2, 0,NU,NU,NU,NU}, {-2, 0,NU,NU,NU,NU}},
    {{ 0,-2,NU,NU,NU,NU}, { 0,-2,NU,NU,NU,NU}, { 0, 2,NU,NU,NU,NU}, { 0, 2,NU,NU,NU,NU}},
    {{ 0,-2,NU,NU,NU,NU}, { 0,-2,NU,NU,NU,NU}, { 0, 2,NU,NU,NU,NU}, { 0, 2,NU,NU,NU,NU}},
    {{-2, 0,NU,NU,NU,NU}, { 2, 0,NU,NU,NU,NU}, { 2, 0,NU,NU,NU,NU}, {-2, 0,NU,NU,NU,NU}},
    {{-2, 0,NU,NU,NU,NU}, { 2, 0,NU,NU,NU,NU}, { 2, 0,NU,NU,NU,NU}, {-2, 0,NU,NU,NU,NU}}
  },
  
  
  // k
  {
    {{ 0,-1,NU,NU,NU,NU}, { 1,-1,NU,NU,NU,NU}, { 0, 2, 1,-1,NU,NU}, { 0, 2,NU,NU,NU,NU}},
    {{-1,-1,NU,NU,NU,NU}, { 0,-1,NU,NU,NU,NU}, { 0, 2,NU,NU,NU,NU}, { 0, 2,-1,-1,NU,NU}},
    {{-2, 0,NU,NU,NU,NU}, { 1, 0,NU,NU,NU,NU}, { 1, 1,NU,NU,NU,NU}, { 1, 1,-2, 0,NU,NU}},
    {{-1, 0,NU,NU,NU,NU}, { 2, 0,NU,NU,NU,NU}, {-1, 1, 2, 0,NU,NU}, {-1, 1,NU,NU,NU,NU}},
    {{-1, 1, 0,-2,NU,NU}, { 0,-2,NU,NU,NU,NU}, { 0, 1,NU,NU,NU,NU}, {-1, 1,NU,NU,NU,NU}},
    {{ 0,-2,NU,NU,NU,NU}, { 1, 1, 0,-2,NU,NU}, { 1, 1,NU,NU,NU,NU}, { 0, 1,NU,NU,NU,NU}},
    {{-1,-1,NU,NU,NU,NU}, { 2, 0,-1,-1,NU,NU}, { 2, 0,NU,NU,NU,NU}, {-1, 0,NU,NU,NU,NU}},
    {{-2, 0, 1,-1,NU,NU}, { 1,-1,NU,NU,NU,NU}, { 1, 0,NU,NU,NU,NU}, {-2, 0,NU,NU,NU,NU}}
  },

  
  // l
  {
    {{ 0, 0, 1,-1,NU,NU}, { 1,-1,NU,NU,NU,NU}, { 0, 2, 1, 0,NU,NU}, { 0, 2,NU,NU,NU,NU}},
    {{-1,-1,NU,NU,NU,NU}, { 0, 0,-1,-1,NU,NU}, { 0, 2,NU,NU,NU,NU}, { 0, 2,-1, 0,NU,NU}},
    {{-2, 0,NU,NU,NU,NU}, { 1, 1, 0, 0,NU,NU}, { 1, 1,NU,NU,NU,NU}, { 0, 1,-2, 0,NU,NU}},
    {{-1, 1, 0, 0,NU,NU}, { 2, 0,NU,NU,NU,NU}, { 0, 1, 2, 0,NU,NU}, {-1, 1,NU,NU,NU,NU}},
    {{-1, 0, 0,-2,NU,NU}, { 0,-2,NU,NU,NU,NU}, {-1, 1, 0, 0,NU,NU}, {-1, 1,NU,NU,NU,NU}},
    {{ 0,-2,NU,NU,NU,NU}, { 1, 0, 0,-2,NU,NU}, { 1, 1,NU,NU,NU,NU}, { 1, 1, 0, 0,NU,NU}},
    {{-1,-1,NU,NU,NU,NU}, { 2, 0, 0,-1,NU,NU}, { 2, 0,NU,NU,NU,NU}, { 0, 0,-1,-1,NU,NU}},
    {{-2, 0, 0,-1,NU,NU}, { 1,-1,NU,NU,NU,NU}, { 0, 0, 1,-1,NU,NU}, {-2, 0,NU,NU,NU,NU}}
  },
  
  
  // m
  {
    {{ 0,-1,NU,NU,NU,NU}, { 1,-1,NU,NU,NU,NU}, { 0, 1, 1, 0,NU,NU}, { 0, 1,NU,NU,NU,NU}},
    {{-1,-1,NU,NU,NU,NU}, { 0,-1,NU,NU,NU,NU}, { 0, 1,NU,NU,NU,NU}, { 0, 1,-1, 0,NU,NU}},
    {{-1, 0,NU,NU,NU,NU}, { 1, 0,NU,NU,NU,NU}, { 1, 1,NU,NU,NU,NU}, { 0, 1,-1, 0,NU,NU}},
    {{-1, 0,NU,NU,NU,NU}, { 1, 0,NU,NU,NU,NU}, { 0, 1, 1, 0,NU,NU}, {-1, 1,NU,NU,NU,NU}},
    {{-1, 0, 0,-1,NU,NU}, { 0,-1,NU,NU,NU,NU}, { 0, 1,NU,NU,NU,NU}, {-1, 1,NU,NU,NU,NU}},
    {{ 0,-1,NU,NU,NU,NU}, { 1, 0, 0,-1,NU,NU}, { 1, 1,NU,NU,NU,NU}, { 0, 1,NU,NU,NU,NU}},
    {{-1,-1,NU,NU,NU,NU}, { 1, 0, 0,-1,NU,NU}, { 1, 0,NU,NU,NU,NU}, {-1, 0,NU,NU,NU,NU}},
    {{-1, 0, 0,-1,NU,NU}, { 1,-1,NU,NU,NU,NU}, { 1, 0,NU,NU,NU,NU}, {-1, 0,NU,NU,NU,NU}}
  },
 
  
  // n
  {
    {{ 0,-1,NU,NU,NU,NU}, { 1, 1, 1,-1,NU,NU}, { 1, 1, 1,-1,NU,NU}, { 0, 1,NU,NU,NU,NU}},
    {{-1, 1,-1,-1,NU,NU}, { 0,-1,NU,NU,NU,NU}, { 0, 1,NU,NU,NU,NU}, {-1, 1,-1,-1,NU,NU}},
    {{-1, 0,NU,NU,NU,NU}, { 1, 0,NU,NU,NU,NU}, { 1, 1,-1, 1,NU,NU}, { 1, 1,-1, 1,NU,NU}},
    {{-1, 0,NU,NU,NU,NU}, { 1, 0,NU,NU,NU,NU}, { 1, 1,-1, 1,NU,NU}, { 1, 1,-1, 1,NU,NU}},
    {{-1,-1,-1, 1,NU,NU}, { 0,-1,NU,NU,NU,NU}, { 0, 1,NU,NU,NU,NU}, {-1, 1,-1,-1,NU,NU}},
    {{ 0,-1,NU,NU,NU,NU}, { 1, 1, 1,-1,NU,NU}, { 1, 1, 1,-1,NU,NU}, { 0, 1,NU,NU,NU,NU}},
    {{ 1,-1,-1,-1,NU,NU}, { 1,-1,-1,-1,NU,NU}, { 1, 0,NU,NU,NU,NU}, {-1, 0,NU,NU,NU,NU}},
    {{ 1,-1,-1,-1,NU,NU}, { 1,-1,-1,-1,NU,NU}, { 1, 0,NU,NU,NU,NU}, {-1, 0,NU,NU,NU,NU}}
  },


  // o
  {
    {{-1, 0, 0,-2,NU,NU}, { 0,-2,NU,NU,NU,NU}, { 0, 1,NU,NU,NU,NU}, { 0, 1,-1, 0,NU,NU}},
    {{ 0,-2,NU,NU,NU,NU}, { 1, 0, 0,-2,NU,NU}, { 0, 1, 1, 0,NU,NU}, { 0, 1,NU,NU,NU,NU}},    
    {{-1, 0, 0,-1,NU,NU}, { 2, 0, 0,-1,NU,NU}, { 2, 0,NU,NU,NU,NU}, {-1, 0,NU,NU,NU,NU}},    
    {{-2, 0, 0,-1,NU,NU}, { 1, 0, 0,-1,NU,NU}, { 1, 0,NU,NU,NU,NU}, {-2, 0,NU,NU,NU,NU}},    
    {{ 0,-1,NU,NU,NU,NU}, { 1, 0, 0,-1,NU,NU}, { 0, 2, 1, 0,NU,NU}, { 0, 2,NU,NU,NU,NU}},    
    {{-1, 0, 0,-1,NU,NU}, { 0,-1,NU,NU,NU,NU}, { 0, 2,NU,NU,NU,NU}, { 0, 2,-1, 0,NU,NU}},    
    {{-2, 0,NU,NU,NU,NU}, { 1, 0,NU,NU,NU,NU}, { 0, 1, 1, 0,NU,NU}, { 0, 1,-2, 0,NU,NU}},    
    {{-1, 0,NU,NU,NU,NU}, { 2, 0,NU,NU,NU,NU}, { 0, 1, 2, 0,NU,NU}, { 0, 1,-1, 0,NU,NU}}
  },
  
  
  // p
  {
    {{-1,-1,NU,NU,NU,NU}, { 1,-1,NU,NU,NU,NU}, { 0, 1, 1,-1,NU,NU}, { 0, 1,-1,-1,NU,NU}},
    {{-1,-1,NU,NU,NU,NU}, { 1,-1,NU,NU,NU,NU}, { 0, 1, 1,-1,NU,NU}, { 0, 1,-1,-1,NU,NU}},
    {{-1, 0, 1,-1,NU,NU}, { 1,-1,NU,NU,NU,NU}, { 1, 1,NU,NU,NU,NU}, { 1, 1,-1, 0,NU,NU}},
    {{-1,-1,NU,NU,NU,NU}, { 1, 0,-1,-1,NU,NU}, {-1, 1, 1, 0,NU,NU}, {-1, 1,NU,NU,NU,NU}},
    {{-1, 1, 0,-1,NU,NU}, { 1, 1, 0,-1,NU,NU}, { 1, 1,NU,NU,NU,NU}, {-1, 1,NU,NU,NU,NU}},
    {{-1, 1, 0,-1,NU,NU}, { 1, 1, 0,-1,NU,NU}, { 1, 1,NU,NU,NU,NU}, {-1, 1,NU,NU,NU,NU}},
    {{-1,-1,NU,NU,NU,NU}, { 1, 0,-1,-1,NU,NU}, {-1, 1, 1, 0,NU,NU}, {-1, 1,NU,NU,NU,NU}},
    {{-1, 0, 1,-1,NU,NU}, { 1,-1,NU,NU,NU,NU}, { 1, 1,NU,NU,NU,NU}, { 1, 1,-1, 0,NU,NU}}
  },
  
  
  // q
  {
    {{-2, 0,NU,NU,NU,NU}, { 0, 0,NU,NU,NU,NU}, { 0, 2,NU,NU,NU,NU}, { 0, 2,-2, 0,NU,NU}},
    {{ 0, 0,NU,NU,NU,NU}, { 2, 0,NU,NU,NU,NU}, { 0, 2, 2, 0,NU,NU}, { 0, 2,NU,NU,NU,NU}},
    {{-2, 0, 0,-2,NU,NU}, { 0,-2,NU,NU,NU,NU}, { 0, 0,NU,NU,NU,NU}, {-2, 0,NU,NU,NU,NU}},
    {{ 0,-2,NU,NU,NU,NU}, { 2, 0, 0,-2,NU,NU}, { 2, 0,NU,NU,NU,NU}, { 0, 0,NU,NU,NU,NU}},
    {{ 0,-2,NU,NU,NU,NU}, { 2, 0, 0,-2,NU,NU}, { 2, 0,NU,NU,NU,NU}, { 0, 0,NU,NU,NU,NU}},
    {{-2, 0, 0,-2,NU,NU}, { 0,-2,NU,NU,NU,NU}, { 0, 0,NU,NU,NU,NU}, {-2, 0,NU,NU,NU,NU}},
    {{ 0, 0,NU,NU,NU,NU}, { 2, 0,NU,NU,NU,NU}, { 0, 2, 2, 0,NU,NU}, { 0, 2,NU,NU,NU,NU}},
    {{-2, 0,NU,NU,NU,NU}, { 0, 0,NU,NU,NU,NU}, { 0, 2,NU,NU,NU,NU}, { 0, 2,-2, 0,NU,NU}}
  },
  
  
  // r
  {
    {{-1,-1,NU,NU,NU,NU}, { 1, 1, 0, 0,-1,-1}, { 1, 1,NU,NU,NU,NU}, { 0, 1,-1, 0,NU,NU}},
    {{-1, 1, 0, 0, 1,-1}, { 1,-1,NU,NU,NU,NU}, { 0, 1, 1, 0,NU,NU}, {-1, 1,NU,NU,NU,NU}},
    {{-1, 0, 0,-1,NU,NU}, { 1,-1,NU,NU,NU,NU}, {-1, 1, 0, 0, 1,-1}, {-1, 1,NU,NU,NU,NU}},
    {{-1,-1,NU,NU,NU,NU}, { 1, 0, 0,-1,NU,NU}, { 1, 1,NU,NU,NU,NU}, { 1, 1, 0, 0,-1,-1}},
    {{-1,-1,NU,NU,NU,NU}, { 1, 0, 0,-1,NU,NU}, { 1, 1,NU,NU,NU,NU}, { 1, 1, 0, 0,-1,-1}},
    {{-1, 0, 0,-1,NU,NU}, { 1,-1,NU,NU,NU,NU}, {-1, 1, 0, 0, 1,-1}, {-1, 1,NU,NU,NU,NU}},
    {{-1, 1, 0, 0, 1,-1}, { 1,-1,NU,NU,NU,NU}, { 0, 1, 1, 0,NU,NU}, {-1, 1,NU,NU,NU,NU}},
    {{-1,-1,NU,NU,NU,NU}, { 1, 1, 0, 0,-1,-1}, { 1, 1,NU,NU,NU,NU}, { 0, 1,-1, 0,NU,NU}}
  },
  
  
  // s
  {
    {{-1,-1,NU,NU,NU,NU}, { 1, 0,-1,-1,NU,NU}, { 1, 1,NU,NU,NU,NU}, { 1, 1,-1, 0,NU,NU}},
    {{-1, 0, 1,-1,NU,NU}, { 1,-1,NU,NU,NU,NU}, {-1, 1, 1, 0,NU,NU}, {-1, 1,NU,NU,NU,NU}},
    {{-1, 1, 0,-1,NU,NU}, { 1,-1,NU,NU,NU,NU}, { 0, 1, 1,-1,NU,NU}, {-1, 1,NU,NU,NU,NU}},
    {{-1,-1,NU,NU,NU,NU}, { 1, 1, 0,-1,NU,NU}, { 1, 1,NU,NU,NU,NU}, { 0, 1,-1,-1,NU,NU}},
    {{-1,-1,NU,NU,NU,NU}, { 1, 0,-1,-1,NU,NU}, { 1, 1,NU,NU,NU,NU}, { 1, 1,-1, 0,NU,NU}},
    {{-1, 0, 1,-1,NU,NU}, { 1,-1,NU,NU,NU,NU}, {-1, 1, 1, 0,NU,NU}, {-1, 1,NU,NU,NU,NU}},
    {{-1, 1, 0,-1,NU,NU}, { 1,-1,NU,NU,NU,NU}, { 0, 1, 1,-1,NU,NU}, {-1, 1,NU,NU,NU,NU}},
    {{-1,-1,NU,NU,NU,NU}, { 1, 1, 0,-1,NU,NU}, { 1, 1,NU,NU,NU,NU}, { 0, 1,-1,-1,NU,NU}}
  },
  
  
  // t
  {
    {{-1, 0, 0,-1,NU,NU}, { 1, 0, 0,-1,NU,NU}, { 1, 1,NU,NU,NU,NU}, { 1, 1,-1, 0,NU,NU}},
    {{-1, 0, 0,-1,NU,NU}, { 1, 0, 0,-1,NU,NU}, {-1, 1, 1, 0,NU,NU}, {-1, 1,NU,NU,NU,NU}},
    {{-1, 1, 0,-1,NU,NU}, { 1, 0, 0,-1,NU,NU}, { 0, 1, 1, 0,NU,NU}, {-1, 1,NU,NU,NU,NU}},
    {{-1, 0, 0,-1,NU,NU}, { 1, 1, 0,-1,NU,NU}, { 1, 1,NU,NU,NU,NU}, { 0, 1,-1, 0,NU,NU}},
    {{-1,-1,NU,NU,NU,NU}, { 1, 0,-1,-1,NU,NU}, { 0, 1, 1, 0,NU,NU}, { 0, 1,-1, 0,NU,NU}},
    {{-1, 0, 1,-1,NU,NU}, { 1,-1,NU,NU,NU,NU}, { 0, 1, 1, 0,NU,NU}, { 0, 1,-1, 0,NU,NU}},
    {{-1, 0, 0,-1,NU,NU}, { 1,-1,NU,NU,NU,NU}, { 0, 1, 1,-1,NU,NU}, { 0, 1,-1, 0,NU,NU}},
    {{-1,-1,NU,NU,NU,NU}, { 1, 0, 0,-1,NU,NU}, { 0, 1, 1, 0,NU,NU}, { 0, 1,-1,-1,NU,NU}}
  },
  
  
  // u
  {
    {{-1, 0, 0,-1,NU,NU}, { 1, 0, 0,-1,NU,NU}, { 0, 1, 1, 0,NU,NU}, { 0, 1,-1, 0,NU,NU}},
    {{-1, 0, 0,-1,NU,NU}, { 1, 0, 0,-1,NU,NU}, { 0, 1, 1, 0,NU,NU}, { 0, 1,-1, 0,NU,NU}},
    {{-1, 0, 0,-1,NU,NU}, { 1, 0, 0,-1,NU,NU}, { 0, 1, 1, 0,NU,NU}, { 0, 1,-1, 0,NU,NU}},
    {{-1, 0, 0,-1,NU,NU}, { 1, 0, 0,-1,NU,NU}, { 0, 1, 1, 0,NU,NU}, { 0, 1,-1, 0,NU,NU}},
    {{-1, 0, 0,-1,NU,NU}, { 1, 0, 0,-1,NU,NU}, { 0, 1, 1, 0,NU,NU}, { 0, 1,-1, 0,NU,NU}},
    {{-1, 0, 0,-1,NU,NU}, { 1, 0, 0,-1,NU,NU}, { 0, 1, 1, 0,NU,NU}, { 0, 1,-1, 0,NU,NU}},
    {{-1, 0, 0,-1,NU,NU}, { 1, 0, 0,-1,NU,NU}, { 0, 1, 1, 0,NU,NU}, { 0, 1,-1, 0,NU,NU}},
    {{-1, 0, 0,-1,NU,NU}, { 1, 0, 0,-1,NU,NU}, { 0, 1, 1, 0,NU,NU}, { 0, 1,-1, 0,NU,NU}}
  }
};

#endif
