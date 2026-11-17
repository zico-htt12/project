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

int play(Game *game, int y1, int x1, int y2, int x2){
    if(x1>5 || x1<0 || x2>5 || x2<0 || y1>4 || y1<0 || y2>4 || y2<0 || (abs(x1-x2)+ abs(y1-y2)!=1))
        return 1;
    int squares=0;
    int xplacement= x1+x2;
    int yplacement= y1+y2;
    if(game->grid[yplacement][xplacement]=='|' || game->grid[yplacement][xplacement]=='-' )
        return 2;
    if(y1==y2){
        game->grid[yplacement][xplacement]='-';
        if(checkSquare(game, yplacement+1,xplacement)==0){
            game->grid[yplacement+1][xplacement]= game->player;
            game->player=='A'?game->score1++:game->score2++;
            squares++;
        }
        if(checkSquare(game, yplacement-1,xplacement)==0){
            game->grid[yplacement-1][xplacement]= game->player;
            game->player=='A'?game->score1++:game->score2++;
            squares++;
        }
    }
    else{
        game->grid[yplacement][xplacement]='|';
        if(checkSquare(game, yplacement,xplacement+1)==0){
            game->grid[yplacement][xplacement+1]= game->player;
            game->player=='A'?game->score1++:game->score2++;
            squares++;
        }
        if(checkSquare(game, yplacement,xplacement-1)==0){
            game->grid[yplacement][xplacement-1]= game->player;
            game->player=='A'?game->score1++:game->score2++;
            squares++;
        }}
    if(squares==0){
    game->player=='A'?(game->player='B'):(game->player='A');}
    return 0;
    

}

int checkSquare(Game *game, int y, int x){
    if(y>=8 || x>=10 || y<=0 || x<=0)
        return 1;
    if(game->grid[y][x]!= ' ')
        return 1;
    if(game->grid[y+1][x]== '-' && game->grid[y][x+1]== '|' && game->grid[y-1][x]=='-' && game->grid[y][x-1]== '|')
        return 0;

    return 1;
}
