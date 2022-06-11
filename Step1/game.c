#include "game.h"

Gameplace newgameplace(int rows, int cols)
{
    Gameplace game;
    game.number_of_rows = rows;
    game.number_of_columns = cols;
    return game;
}

Cell **ppCreateCells(Gameplace game)
{
    int size = game.number_of_rows * game.number_of_columns;
    Cell **array = (Cell **)malloc(game.number_of_columns * sizeof(Cell *));

    for (int z = 0; z < size; z++)
    {
        array[z] = (Cell *)malloc(game.number_of_rows * sizeof(Cell));
    }

    for (int i = 0; i < game.number_of_rows; i++)
    {
        for (int j = 0; j < game.number_of_columns; j++)
        {
            array[i][j] = newCell(i, j);
        }
    }

    return array;
}

void printGameplace(Gameplace game, Cell **array)
{
    for (int i = 0; i < game.number_of_rows; i++)
    {
        for (int j = 0; j < game.number_of_columns; j++)
        {
            printf("|%d %d|", array[i][j].row, array[i][j].column);
        }
        printf("\n");
    }
}

void printGameplaceFull(Gameplace game, Cell **array)
{
    for (int i = 0; i < game.number_of_rows; i++)
    {
        for (int j = 0; j < game.number_of_columns; j++)
        {
            printf("|%d|", array[i][j].isFull);
        }
        printf("\n");
    }
}

Cell **ppaddRandomFullCells(Gameplace game, int count)
{
    srand(time(NULL));
    Cell **arrcell = ppCreateCells(game);

    for (int i = 0; i < count; i++)
    {
        int row = rand() % game.number_of_rows;
        int col = rand() % game.number_of_columns;
        arrcell[row][col].isFull = 1;
    }

    return arrcell;
}

Cell checkFullCellDeadorAlive(Gameplace game, Cell **array, int z, int k)
{
    int index = 0;
    for (int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            int neighbor_row = z + i;
            int neighbor_column = k + j;
            if (neighbor_column < 0 || neighbor_row < 0 || neighbor_column >= game.number_of_columns || neighbor_row >= game.number_of_rows)
            {
                continue;
            }
            else if (neighbor_row == z && neighbor_column == k)
            {
                continue;
            }
            else if (array[neighbor_row][neighbor_column].isFull == 1)
            {
                index++;
            }
        }
    }

    return index == 3 || index == 2 ? newCell(-1, -1) : array[z][k];
}

Cell checkEmptyCellDeadorAlive(Gameplace game, Cell **array, int z, int k)
{
    int index = 0;
    for (int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            int neighbor_row = z + i;
            int neighbor_column = k + j;
            if (neighbor_column < 0 || neighbor_row < 0 || neighbor_column >= game.number_of_columns || neighbor_row >= game.number_of_rows)
            {
                continue;
            }
            if (neighbor_row == z && neighbor_column == k)
            {
                continue;
            }
            if (array[neighbor_row][neighbor_column].isFull == 1)
            {
                index++;
            }
        }
    }

    return (index == 3) ? array[z][k] : newCell(-1, -1);
}

Cell **ppPlayGame(Gameplace game, Cell **array)
{
    int size = game.number_of_rows * game.number_of_columns;
    Cell deletedCells[size];
    Cell addedCells[size];
    int index1 = 0;
    int index2 = 0;

    for (int i = 0; i < game.number_of_rows; i++)
    {
        for (int j = 0; j < game.number_of_columns; j++)
        {
            if (array[i][j].isFull == 1)
            {
                if (checkFullCellDeadorAlive(game, array, i, j).column >= 0 && checkFullCellDeadorAlive(game, array, i, j).row >= 0)
                    deletedCells[index1++] = checkFullCellDeadorAlive(game, array, i, j);
            }
            else
            {
                if (checkEmptyCellDeadorAlive(game, array, i, j).column >= 0 && checkEmptyCellDeadorAlive(game, array, i, j).row >= 0)
                    addedCells[index2++] = checkEmptyCellDeadorAlive(game, array, i, j);
            }
        }
    }
    /// printf("Deleted Cells\n");
    for (int i = 0; i < index1; i++)
    {
        //  printf("%d %d\n", deletedCells[i].row, deletedCells[i].column);
        array[deletedCells[i].row][deletedCells[i].column].isFull = 0;
    }

    //  printf("Added Cells\n");
    for (int i = 0; i < index2; i++)
    {
        // printf("%d %d\n", addedCells[i].row, addedCells[i].column);
        array[addedCells[i].row][addedCells[i].column].isFull = 1;
    }
    // printf("---------------\n");

    return array;
}
