#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <stdbool.h>
#include "game_input.h"
#include "sudoku_state.h"
#include "displayGame.h"
#include "control_screen.h"
#include "saveload.h"
#include "saveScreen.h"


//params: pointer to an int with the desired position to change
//
//increases a position variable accordingly on the vertical axis
void increaseVertical(int* position)
{
    *position -= 3;
    if(*position <= -1)
    {
        *position += 9;
    }
}

//params: pointer to int with the desired positions to change and a boolean whether the user is in detailed view or not
//
//moves the user one block or field up depending on the detail param
void goUp(int* posSmall, int* posBig, bool* detail)
{
    if(*detail)
    {
        increaseVertical(posSmall);
    }
    else
    {
        increaseVertical(posBig);
    }
}

//params: pointer to an int with the desired position to change
//
//decreases a position variable accordingly on the vertical axis
void decreaseVertical(int* position)
{
    *position += 3;
    if(*position >= 9)
    {
        *position -= 9;
    }
}

//params: pointer to int with the desired positions to change and a boolean whether the user is in detailed view or not
//
//moves the user one block or field down depending on the detail param
void goDown(int* posSmall, int* posBig, bool* detail)
{
    if(*detail)
    {
        decreaseVertical(posSmall);
    }
    else
    {
        decreaseVertical(posBig);
    }
}

//params: pointer to an int with the desired position to change
//
//increases a position variable accordingly on the horizontal axis
void increaseHorizontal(int* position)
{
    *position += 1;
    switch(*position)
    {
    case 3:
        *position = 0;
        break;
    case 6:
        *position = 3;
        break;
    case 9:
        *position = 6;
        break;
    }
}

//params: pointer to an int with the desired positions to change and a boolean whether the user is in detailed view or not
//
//moves the user one block or field to the right depending on the detail param
void goRight(int* posSmall, int* posBig, bool* detail)
{
    if(*detail)
    {
        increaseHorizontal(posSmall);
    }
    else
    {
        increaseHorizontal(posBig);
    }
}

//params: pointer to an int with the desired position to change
//
//decreases a position variable accordingly on the horizontal axis
void decreaseHorizontal(int* position)
{
    *position -= 1;
    switch(*position)
    {
    case -1:
        *position = 2;
        break;
    case 2:
        *position = 5;
        break;
    case 5:
        *position = 8;
        break;
    }
}

//params: pointer to int with the desired positions to change and a boolean whether the user is in detailed view or not
//
//moves the user one block or field to the left depending on the detail param
void goLeft(int* posSmall, int* posBig, bool* detail)
{
    if(*detail)
    {
        decreaseHorizontal(posSmall);
    }
    else
    {
        decreaseHorizontal(posBig);
    }
}


//params: pointer to int with the desired positions to change, a boolean pointer, the current gamestate pointer, a pointer to the current board, the total time in seconds and the current Loop clock
//
//moves the user through the game board, lets them change numbers and save or win the game
//
//returns: 1 if the game can continue and 0 if the game has come to an end through winning or saving the game
int getInputGameState(GameState* state, int* posBig, int* posSmall, bool* detail, int (*sudoku)[9][9], int timeInSecs, clock_t loopStartClock)
{
    int returnInt = 1;
    int checkInt = 0;
    int inputNumber = 0;
    bool changeNumber = false;

    int screenSize = getScreenWidth();


    screenSize = screenSize / 5;

    int overflowScreenSize = screenSize % 18;
    screenSize -= overflowScreenSize;

    grid(screenSize * 2, screenSize, *posBig, *posSmall, *detail);    //Startwert kommt von Nikita nach
    fillGrid(*sudoku, screenSize * 2, screenSize);

    int c = getch();
    switch(c)
    {

    // Handling movement

    case 119: // = W
    case 72:  // = Arrow up
        goUp(posSmall, posBig, detail);

        break;
    case 115:  // = S
    case 80:   // = Arrow down
        goDown(posSmall, posBig, detail);

        break;
    case 100:  // = D
    case 77:   // = Arrow right
        goRight(posSmall, posBig, detail);

        break;
    case 97:   // = A
    case 75:   // = Arrow left
        goLeft(posSmall, posBig, detail);

        break;
    case 32:   // = Spacebar
        if(*detail)
        {
            *detail = false;
        }
        else
        {
            *detail = true;
        }
        break;

    case 'c':  // = C
        tryChangeState(state, 1);
        break;

    case 13:    // = Return
        checkInt = sudokuCheck(*sudoku);

        switch(checkInt)
        {
        case -1:
            // board not filled / contains zeros!
            setCursor(0, screenSize + 1);   // Sets the cursor to the end of the Board

            printf("\nBoard not filled completly. Fill every field slot and try again!");

            break;
        case 0:
            // board not solved but filled completly
            setCursor(0, screenSize + 1);   // Sets the cursor to the end of the Board

            printf("\nBoard not correct. Change some values and try again!                ");   // added more spaces to overwrite potential other messages like the one above this one

            break;
        case 1:
            tryChangeState(state, 3);
            break;
        default:
            break;
        }
        break;

    case 27:    // = ESC
        saveSudoku(loopStartClock, timeInSecs, sudoku);

        returnInt = 0;
        break;

    // Handling number input

    case 48:
        inputNumber = 0;
        changeNumber = true;
        break;
    case 49:
        inputNumber = 1;
        changeNumber = true;
        break;
    case 50:
        inputNumber = 2;
        changeNumber = true;
        break;
    case 51:
        inputNumber = 3;
        changeNumber = true;
        break;
    case 52:
        inputNumber = 4;
        changeNumber = true;
        break;
    case 53:
        inputNumber = 5;
        changeNumber = true;
        break;
    case 54:
        inputNumber = 6;
        changeNumber = true;
        break;
    case 55:
        inputNumber = 7;
        changeNumber = true;
        break;
    case 56:
        inputNumber = 8;
        changeNumber = true;
        break;
    case 57:
        inputNumber = 9;
        changeNumber = true;
        break;
    default:
        break;
    }

    if(changeNumber)  // Only changes the value if an actual number input was made
    {
        (*sudoku)[*posBig][*posSmall] = inputNumber;
    }

    return returnInt;
}


//params: A pointer to the current gamestate
//
//shows the control screen and changes state to the game gamestate after any button press
void getInputControlState(GameState* state)
{
    system("cls");

    showControlScreen();

    switch(getch())
    {
    default:
        printf("continue!");  //Waits for Input and continues after any button press!
        break;
    }

    system("cls");

    tryChangeState(state, 2);
}


//params: A pointer to the current gamestate, a pointer to the current board and a pointer to the total time
//
//Shows the loading screen, lets the user chose a save file and changes state to the control screen state
void getInputStartState(GameState* state, int (*sudoku)[9][9], int* timeInSecs)
{
    Savegame game;

    game.timePlayed = 0;
    if (loadScreen(&game)) {

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                (*sudoku)[i][j] = game.sudoku[i][j];
            }
        }

        *timeInSecs = game.timePlayed;
    }
    else{
        *timeInSecs = 0;
    }

    tryChangeState(state, 1);
}


//params: A pointer to the current gamestate and a pointer to the total time
//
//Shows the win screen and closes the game
//
//returns always 0 to quit the game
int getInputEndState(GameState* state, int* timeInSecs)
{
    showEndScreen(*timeInSecs);

    return 0;
}

//params:pointer to int with the desired positions to change, a boolean pointer, the current gamestate pointer, a pointer to the current board, the total time in seconds and the current Loop clock
//
//Processes the user input and starts the according state function
//
//returns: 1 if the game can continue and 0 if the game needs to close
int getStateInput(GameState* state, int* posBig, int* posSmall, bool* detail, int (*sudoku)[9][9], int* timeInSecs, clock_t loopStartClock)
{
    int returnInt = 1;
    switch(state->state)
    {
    case 0:
        getInputStartState(state, sudoku, timeInSecs);
        break;
    case 1:
        getInputControlState(state);
        break;
    case 2:
        returnInt = getInputGameState(state, posBig, posSmall, detail, sudoku, *timeInSecs, loopStartClock);
        break;
    case 3:
        returnInt = getInputEndState(state, timeInSecs);
        break;
    }
    return returnInt;
}
