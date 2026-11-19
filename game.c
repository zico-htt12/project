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

int play(Game *game, int x1, int x2, int y1, int y2){
    int dx = x1 - x2, dy = y1 - y2;
    if(x1<0 || x1>4 || x2<0 || x2>4 || y1<0 || y1>5 || y2<0 || y2>5 || dx*dx + dy*dy != 1)
        return -1;
    int i = x1 + x2, j = y1 + y2;              
    if(game->grid[i][j] != ' ')
        return -1;
    game->grid[i][j] = (dx == 0) ? '-' : '|';

    int done = 0;
    for(int a = 1; a < 9; a += 2)            
        for(int b = 1; b < 11; b += 2)
            if(game->grid[a][b] == ' ' && game->grid[a-1][b] != ' ' && game->grid[a+1][b] != ' '
               && game->grid[a][b-1] != ' ' && game->grid[a][b+1] != ' '){
                game->grid[a][b] = game->player;
                done++;
            }
    if(game->player == 'A') game->score1 += done; else game->score2 += done;
    if(done == 0) game->player = (game->player == 'A') ? 'B' : 'A';
    return done;
}