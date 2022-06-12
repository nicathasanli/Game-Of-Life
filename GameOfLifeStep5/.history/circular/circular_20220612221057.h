#ifndef CIRCULAR
#define CIRCULAR
#include <stdio.h>
#include <stdlib.h>
#include "../game/cell.h"
#include "../game/gameplace.h"

Cell checkFullCellDeadorAlive_Circular(Gameplace gp, Cell **array, int z, int k);
Cell checkEmptyCellDeadorAlive_Circular(Gameplace gp, Cell **array, int z, int k);
#endif