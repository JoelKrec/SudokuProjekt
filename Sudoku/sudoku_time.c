#include <time.h>
#include "sudoku_time.h"
#include <stdbool.h>

//params: clock_t created at the beginning of the game
//returns the difference in time since the beginning of the game in seconds
double getCurrentSudokuTimeInSecs(clock_t startTime)
{
    int timeInTicks = clock() - startTime;

    return (double)timeInTicks / CLOCKS_PER_SEC;
}
