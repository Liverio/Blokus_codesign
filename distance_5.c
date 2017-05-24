#ifndef DISTANCE_5_C
#define DISTANCE_5_C

static void distance_5(char J, char K, char L, char N, char Q, char R, char S,
                char a2, char b2,
                char a3, char b3, char c3, char d3, char e3,
                char a4, char b4, char c4, char d4, char e4, char f4, char g4, char h4,
                char a5, char b5, char c5, char d5, char e5, char f5, char g5, char h5, char i5, char j5, char k5, char l5, char m5,
                char *acc_a5, char *acc_b5, char *acc_c5, char *acc_d5, char *acc_e5, char *acc_f5, char *acc_g5, char *acc_h5, char *acc_i5, char *acc_j5, char *acc_k5, char *acc_l5, char *acc_m5){
    *acc_a5 = (N && a5 && a4 && a3 && a2);
    
    *acc_b5 = (K && b5 && a4 && a3 && a2);
    
    *acc_c5 = (S && c5 && a4 && a3 && a2) ||
          (R && c5 && b4 && a3 && a2) ||
          (Q && c5 && b4 && b3 && a2);
    
    *acc_d5 = (L && d5 && b4 && a3 && a2) ||
          (L && d5 && b4 && b3 && a2) ||
          (K && d5 && c4 && b3 && a2);
    
    *acc_e5 = (J && e5 && c4 && b3 && a2);
    
    *acc_f5 = (L && f5 && d4 && b3 && a2) ||
          (L && f5 && d4 && c3 && a2) ||
          (K && f5 && c4 && b3 && a2) ||
          (K && f5 && d4 && c3 && b2);
    
    *acc_g5 = (S && g5 && d4 && c3 && b2) ||
          (S && g5 && e4 && c3 && a2) ||
          (R && g5 && e4 && c3 && b2) ||
          (R && g5 && d4 && c3 && a2) ||
          (Q && g5 && d4 && b3 && a2) ||
          (Q && g5 && e4 && d3 && b2);
    
    *acc_h5 = (L && h5 && e4 && c3 && b2) ||
          (L && h5 && e4 && d3 && b2) ||
          (K && h5 && e4 && c3 && a2) ||
          (K && h5 && f4 && d3 && b2);
    
    *acc_i5 = (J && i5 && f4 && d3 && b2);
    
    *acc_j5 = (L && j5 && g4 && e3 && b2) ||
          (L && j5 && g4 && d3 && b2) ||
          (K && j5 && f4 && d3 && b2);
    
    *acc_k5 = (S && k5 && h4 && e3 && b2) ||
          (R && k5 && g4 && e3 && b2) ||
          (Q && k5 && g4 && d3 && b2);
    
    *acc_l5 = (K && l5 && h4 && e3 && b2);
    
    *acc_m5 = (N && m5 && h4 && e3 && b2);
}

#endif
