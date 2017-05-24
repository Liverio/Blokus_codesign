#include "IO.h"

void printGameStatus(square board[][14], char *tiles_hero, char *tiles_rival){
	unsigned char c, i, j;

	/****** AVAILABLE TILES ******/
    printf("\t");
    for (c='a'; c<='u'; c++)
    	printf("%c ", c);

    printf("\nHero\t");
    for (i=0; i<21; i++)
    	printf("%d ", tiles_hero[i]);
    printf("\n");

    printf("Rival\t");
    for (i=0; i<21; i++)
    	printf("%d ", tiles_rival[i]);
    printf("\n\n");


    // ****** BOARD ******

    // Columns numeration
    printf("  ");
    for (i=0; i<14; i++){
    	if (i<9)
    		printf("%d ", i+1);
    	else
    		printf("%c ", 97-9+i);
    }
    printf("\n");

    for (i=0; i<14; i++){
    	// Rows numeration
    	if (i<9)
    		printf("%d ", i+1);
    	else
    		printf("%c ", 97-9+i);

    	for (j=0; j<14; j++){
    		if (board[i][j] == SQUARE_HERO)
    			printf("x ");
    		else if(board[i][j] == SQUARE_RIVAL)
    			printf("+ ");
    		else
    			printf("- ");
    	}
    	printf("\n");
    }

    printf("\n\n");
}

void printAccessibilityMap(char *acc_map[][14]){
	unsigned char i, j;

    // Columns numeration
    printf("  ");
    for (i=0; i<14; i++){
    	if (i<9)
    		printf("%d  ", i+1);
    	else
    		printf("%c  ", 97-9+i);
    }
    printf("\n");

    for (i=0; i<14; i++){
    	// Rows numeration
    	if (i<9)
    		printf("%d ", i+1);
    	else
    		printf("%c ", 97-9+i);

    	for (j=0; j<14; j++){
			if (acc_map[i][j])
				printf("o  ");
			else
				printf("-  ");
    	}
    	printf("\n");
    }
    printf("\n\n");
}
