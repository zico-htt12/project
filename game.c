#include "game.h"

void initialisation(Game* game){

    for(int i=0;i<9; i++){
        for(int j=0;j< 11; j++ ){
            if(i%2==1)
                game->grid[i][j]=' ';
            else {  
            if(j%2==1)
                game->grid[i][j]=' ';
            else
                game->grid[i][j]='.';}
        }
    }
    game->score1=0;
    game->score2=0;
    game->player='A';
}

void printGrid(const Game* game){
    for(int i=0;i<9;i++){
        for(int j=0;j<11;j++){
            printf("%c ", game->grid[i][j]);
        }
        printf("\n");
    }

}