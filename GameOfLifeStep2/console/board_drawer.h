#include <stdio.h>
#include <stdlib.h>
#include "life.h"
typedef struct gameplace{
    int number_of_rows;
    int number_of_columns;
} Gameplace;
Gameplace newgameplace(int rows, int cols);
Cell **ppCreateCells(Gameplace gp);
void printGameplace(Gameplace gp, Cell **array);
void printGameplaceFull(Gameplace gp, Cell **array);
Cell **ppaddRandomFullCells(Gameplace gp, int count);
Cell checkFullCellDeadorAlive(Gameplace gp, Cell **array, int z, int k);
Cell checkEmptyCellDeadorAlive(Gameplace gp, Cell **array, int z, int k);
Cell **ppPlayGame(Gameplace gp, Cell **array);
