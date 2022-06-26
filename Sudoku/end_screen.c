#include "end_screen.h"
#include <stdio.h>
#include <time.h>
#include "sudoku_time.h"

//params: total time
//
//Shows the end screen and how long the use needed for completion
void showEndScreen(int timeInSecs)
{
    system("cls");

    printHeadingMain("You won!");

    printf("\n\n\n\n");

    printf("You finished in %i seconds!", timeInSecs);

    printf("\n\n\n\n");

    printf("Press any key to continue!");
}
