/**

A simple Sudoku game to play

Authors: Nikita Morosov, Lukas Tetzlaf, Joel Krec

Date: 26.06.2022

**/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <stdbool.h>
#include "game_input.h"
#include "sudoku_state.h"
#include "end_screen.h"
#include "sudoku_time.h"


int main()
{
    system("chcp 437");
    system("cls");

    GameState state = initializeGameState();

    int sudoku[9][9] = {{0,1,2,3,4,5,6,7,8}, {0,1,2,3,4,5,6,7,8}, {0,1,2,3,4,5,6,7,8}, {0,1,2,3,4,5,6,7,8}, {0,1,2,3,4,5,6,7,8}, {0,1,2,3,4,5,6,7,8}, {0,1,2,3,4,5,6,7,8}, {0,1,2,3,4,5,6,7,8}, {0,1,2,3,4,5,6,7,8}};

    int timeInSecs = 0;
    double loopTime = 0;

    int posX = 0;
    int posY = 0;
    bool detail = false;

    clock_t st = clock();


    while(1)
    {
        loopTime += getCurrentSudokuTimeInSecs(st);      // calculates the time the last loop took and adds it to variable

        if(loopTime >= 1)                                // Adds the time of the last loops if it exceeds more than one second and clears it afterwards
        {
            timeInSecs += (int) loopTime;
            loopTime = 0;
        }

        st = clock();                                   // creates the new loop clock

        int playCondition = getStateInput(&state, &posX, &posY, &detail, &sudoku, &timeInSecs, st);   // gets and uses the user input

        if(!playCondition)                              // stops the game if it needs to
        {
            return 0;
        }


    }
    return 0;
}
