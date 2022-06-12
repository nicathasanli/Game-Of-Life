#ifndef CLIPPED
#define CLIPPED
#include <stdio.h>
#include <stdlib.h>
#include "../game/cell.h"
#include "../game/gameplace.h"

Cell checkFullCellDeadorAlive(Gameplace gp, Cell **array, int z, int k);
Cell checkEmptyCellDeadorAlive(Gameplace gp, Cell **array, int z, int k);
#endif