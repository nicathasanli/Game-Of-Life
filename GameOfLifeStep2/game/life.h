#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct cell
{
    int row;
    int column;
    int isFull;
} Cell;

Cell newCell(int row, int col);
void printNeighbours(Cell c);