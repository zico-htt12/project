#ifndef GAME_H
#define GAME_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char grid[9][11];
    int score1;
    int score2;
    char player;
} Game;


void initialisation(Game *game);
void printGrid(const Game *game);
int play(Game *game, int y1, int x1, int y2, int x2);
int checkSquare(Game *game, int x, int y);
#endif
