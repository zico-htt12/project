#include <stdio.h>
#include <stdlib.h>
#include "game.h"


static void clear_stdin(void) {
    int ch;
    while (1) {
        ch = getchar();
        if (ch == '\n' || ch == EOF) {
            break;
        }
    }
}


int main(void){
    Game game;
    initialisation(&game);

    printf("Welcome to dots and bxoes!\n");

    while(game.score1+game.score2<20){
        printGrid(&game);
        printf("\nPlayer %c, choose a column and row: ", game.player);
        int r1, c1, r2, c2;
        int n = scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
        
        if(n==EOF) { return 0; }
        if (n!=4) { 
            printf("invalid input, enter four numbers");
            clear_stdin();
            continue;
        }

        if(play(&game, r1, r2, c1, c2) == -1){
            printf("invalid move dots neeed to connect\n");
            continue;
	}
    }
    printGrid(&game);
    printf("player As score: %d", game.score1);
    printf("player Bs score: %d", game.score2);
    
    if(game.score1>game.score2) { printf("player A wins!"); }
	else if(game.score1<game.score2) { printf("player B wins!"); }
	else { printf("its a tie"); }
}
