#include <stdio.h>
#include <stdlib.h>
#include "game.h"

static void clear_stdin(void)
{
    int ch;
    while (1)
    {
        ch = getchar();
        if (ch == '\n' || ch == EOF)
        {
            break;
        }
    }
}

int main(void)
{
    Game game;
    initialisation(&game);

    printf("Welcome to Dots and Boxes!\n");

    while (game.score1 + game.score2 < 20)
    {
        printGrid(&game);
        printf("\nPlayer %c, enter two dots (row col row col): ", game.player);
        int r1, c1, r2, c2;
        int n = scanf("%d %d %d %d", &r1, &c1, &r2, &c2);

        if (n == EOF)
        {
            return 0;
        }
        if (n != 4)
        {
            printf("Invalid input, enter four numbers.\n");
            clear_stdin();
            continue;
        }

        int res = play(&game, r1, c1, r2, c2);
        if (res == 1)
        {
            printf("Invalid move: the dots must be adjacent and inside the grid.\n");
            continue;
        }
        if (res == 2)
        {
            printf("This line is already drawn.\n");
            continue;
        }
    }

    printGrid(&game);
    printf("Player A's score: %d\n", game.score1);
    printf("Player B's score: %d\n", game.score2);

    if (game.score1 > game.score2)
    {
        printf("Player A wins!\n");
    }
    else if (game.score1 < game.score2)
    {
        printf("Player B wins!\n");
    }
    else
    {
        printf("It's a tie!\n");
    }

    return 0;
}
