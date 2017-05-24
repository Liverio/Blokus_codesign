#ifndef DISTANCE_2_C
#define DISTANCE_2_C

static void distance_2(char B, char C, char D, char E, char F, char G, char H, char I, char J, char K, char L, char M, char N, char O, char P, char Q, char R, char S, char T, char U,
                char a2, char b2,
                char a3, char b3, char c3, char d3, char e3,
                char a4, char b4, char c4, char d4, char e4, char f4, char g4, char h4,
                char a5, char b5, char c5, char d5, char e5, char f5, char g5, char h5, char i5, char j5, char k5, char l5, char m5,
                char *acc_a2, char *acc_b2){
                     
     *acc_a2 = (U && a3 && b3 && c3 && a2) ||
               (T && d4 && a3 && b3 && a2) ||
               (T && a3 && b3 && a2 && b2) ||
               (T && a4 && b4 && a3 && a2) ||
               (T && d4 && a3 && c3 && a2) ||
               (T && b4 && b3 && c3 && a2) ||
               (T && b4 && a3 && c3 && a2) ||
               (T && d3 && e3 && a2 && b2) ||
               (T && d4 && e4 && c3 && a2) ||
               (S && b4 && b3 && a2 && b2) ||
               (S && c5 && a4 && a3 && a2) ||
               (S && g4 && d3 && a2 && b2) ||
               (S && g5 && e4 && c3 && a2) ||
               (R && c5 && b4 && a3 && a2) ||
               (R && a3 && e3 && a2 && b2) ||
               (R && b4 && a3 && a2 && b2) ||
			   (R && g4 && e3 && a2 && b2) ||
			   (R && g5 && d4 && c3 && a2) ||
			   (Q && g5 && d4 && b3 && a2) ||
			   (Q && b3 && d3 && a2 && b2) ||
			   (Q && c5 && b4 && b3 && a2) ||
			   (P && e4 && b3 && c3 && a2) ||
			   (P && b4 && d4 && b3 && a2) ||
			   (P && a4 && a3 && b3 && a2) ||
			   (O && a4 && a3 && c3 && a2) ||
			   (O && c4 && a3 && b3 && a2) ||
			   (O && b4 && c4 && b3 && a2) ||
			   (O && e4 && a3 && c3 && a2) ||
			   (O && c4 && d4 && b3 && a2) ||
			   (O && c4 && b3 && c3 && a2) ||
			   (N && e4 && d3 && a2 && b2) ||
			   (N && a5 && a4 && a3 && a2) ||
			   (N && e4 && c3 && d3 && a2) ||
			 (N && d4 && b3 && a2 && b2) ||
			 (M && c3 && d3 && a2 && b2) ||
			 (M && e4 && c3 && a2 && b2) ||
			 (M && d4 && b3 && c3 && a2) ||
			 (M && b3 && c3 && a2 && b2) ||
			 (M && a3 && c3 && a2 && b2) ||
			 (M && d4 && c3 && a2 && b2) ||
			 (M && b4 && a3 && b3 && a2) ||
			 (M && c3 && e3 && a2 && b2) ||
			 (L && a3 && d3 && a2 && b2) ||
			 (L && f5 && d4 && b3 && a2) ||
			 (L && d5 && b4 && a3 && a2) ||
			 (L && b3 && e3 && a2 && b2) ||
			 (L && a4 && a3 && a2 && b2) ||
			 (L && f5 && d4 && c3 && a2) ||
			 (L && d5 && b4 && b3 && a2) ||
			 (L && h4 && e3 && a2 && b2) ||
			 (K && f4 && d3 && a2 && b2) ||
			 (K && h5 && e4 && c3 && a2) ||
			 (K && f5 && c4 && b3 && a2) ||
			 (K && c4 && b3 && a2 && b2) ||
			 (K && b5 && a4 && a3 && a2) ||
			 (K && d5 && c4 && b3 && a2) ||
			 (J && e5 && c4 && b3 && a2) ||
			 (I && d4 && c3 && a2) ||
			 (I && b4 && a3 && a2) ||
			 (I && e3 && a2 && b2) ||
			 (I && a3 && a2 && b2) ||
			 (H && c3 && a2 && b2) ||
			 (G && a3 && c3 && a2) ||
			 (G && a3 && b3 && a2) ||
			 (G && b3 && c3 && a2) ||
			 (F && d3 && a2 && b2) ||
			 (F && e4 && c3 && a2) ||
			 (F && d4 && b3 && a2) ||
			 (F && b3 && a2 && b2) ||
			 (F && a4 && a3 && a2) ||
			 (F && b4 && b3 && a2) ||
			 (E && c4 && b3 && a2) ||
			 (D && c3 && a2) ||
			 (D && a2 && b2) ||
			 (D && a3 && a2) ||
			 (C && b3 && a2) ||
			 (B && a2);

	*acc_b2 = (U && c3 && d3 && e3 && b2) ||
				 (T && e4 && c3 && e3 && b2) ||
				 (T && a3 && b3 && a2 && b2) ||
				 (T && g4 && c3 && e3 && b2) ||
				 (T && g4 && c3 && d3 && b2) ||
				 (T && e4 && d3 && e3 && b2) ||
				 (T && d4 && e4 && c3 && b2) ||
				 (T && g4 && h4 && e3 && b2) ||
				 (T && d3 && e3 && a2 && b2) ||
				 (S && g5 && d4 && c3 && b2) ||
				 (S && b4 && b3 && a2 && b2) ||
				 (S && k5 && h4 && e3 && b2) ||
				 (S && g4 && d3 && a2 && b2) ||
				 (R && g5 && e4 && c3 && b2) ||
				 (R && a3 && e3 && a2 && b2) ||
				 (R && k5 && g4 && e3 && b2) ||
				 (R && b4 && a3 && a2 && b2) ||
				 (R && g4 && e3 && a2 && b2) ||
				 (Q && b3 && d3 && a2 && b2) ||
				 (Q && k5 && g4 && d3 && b2) ||
				 (Q && g5 && e4 && d3 && b2) ||
				 (P && h4 && d3 && e3 && b2) ||
				 (P && d4 && c3 && d3 && b2) ||
				 (P && e4 && g4 && d3 && b2) ||
				 (O && f4 && g4 && d3 && b2) ||
				 (O && e4 && f4 && d3 && b2) ||
				 (O && d4 && c3 && e3 && b2) ||
				 (O && h4 && c3 && e3 && b2) ||
				 (O && f4 && c3 && d3 && b2) ||
				 (O && f4 && d3 && e3 && b2) ||
				 (N && e4 && d3 && a2 && b2) ||
				 (N && d4 && b3 && a2 && b2) ||
				 (N && m5 && h4 && e3 && b2) ||
				 (N && d4 && b3 && c3 && b2) ||
				 (M && c3 && d3 && a2 && b2) ||
				 (M && e4 && c3 && a2 && b2) ||
				 (M && b3 && c3 && a2 && b2) ||
				 (M && a3 && c3 && a2 && b2) ||
				 (M && g4 && d3 && e3 && b2) ||
				 (M && e4 && c3 && d3 && b2) ||
				 (M && d4 && c3 && a2 && b2) ||
				 (M && c3 && e3 && a2 && b2) ||
				 (L && a3 && d3 && a2 && b2) ||
				 (L && j5 && g4 && e3 && b2) ||
				 (L && h5 && e4 && c3 && b2) ||
				 (L && b3 && e3 && a2 && b2) ||
				 (L && a4 && a3 && a2 && b2) ||
				 (L && j5 && g4 && d3 && b2) ||
				 (L && h5 && e4 && d3 && b2) ||
				 (L && h4 && e3 && a2 && b2) ||
				 (K && f4 && d3 && a2 && b2) ||
				 (K && c4 && b3 && a2 && b2) ||
				 (K && j5 && f4 && d3 && b2) ||
				 (K && h5 && f4 && d3 && b2) ||
				 (K && f5 && d4 && c3 && b2) ||
				 (K && l5 && h4 && e3 && b2) ||
				 (J && i5 && f4 && d3 && b2) ||
				 (I && e3 && a2 && b2) ||
				 (I && a3 && a2 && b2) ||
				 (I && g4 && e3 && b2) ||
				 (I && e4 && c3 && b2) ||
				 (H && c3 && a2 && b2) ||
				 (G && d3 && e3 && b2) ||
				 (G && c3 && d3 && b2) ||
				 (G && c3 && e3 && b2) ||
				 (F && d3 && a2 && b2) ||
				 (F && b3 && a2 && b2) ||
				 (F && g4 && d3 && b2) ||
				 (F && e4 && d3 && b2) ||
				 (F && d4 && c3 && b2) ||
				 (F && h4 && e3 && b2) ||
				 (E && f4 && d3 && b2) ||
				 (D && a2 && b2) ||
				 (D && e3 && b2) ||
				 (D && c3 && b2) ||
				 (C && d3 && b2) ||
				 (B && b2);
}

#endif
