#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "game.h"

int main(int argc, char const *argv[])
{

    Gameplace gp = newgameplace(20, 20);

    Cell **ppaddRandomCells = ppaddRandomFullCells(gp, 80);

    while (1)
    {
        printf("\033[2J");
        // hide cursor
        printf("\033[?25l");
        // goto 0,0
        for (int i = 0; i < gp.number_of_rows; ++i)
        {
            printf("\033[%d;4H", i + 2);
            for (int j = 0; j < gp.number_of_columns; ++j)
            {
                int c = ppaddRandomCells[i][j].isFull == 1 ? 104 : 40;
                printf("\033[%dm  ", c);
                // draw 2 space with color 40 or 101 (black or magenta)
            }
        }
        ppaddRandomCells = ppPlayGame(gp, ppaddRandomCells);
        //show cursor
        printf("\033[?25h");
        sleep(1);
        printf("\n");
    }

    return 0;
}
