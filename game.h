#include <stdio.h>

typedef struct {
    char grid[9][11];
    int score1;
    int score2;
    char player;
} Game;


void initialisation(Game *game);
void printGrid(const Game *game);
int play(Game *game, int x1, int x2, int y1, int y2);

