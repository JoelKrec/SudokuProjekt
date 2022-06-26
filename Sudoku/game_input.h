#pragma once
#include "sudoku_state.h"

int getInputGameState(GameState* state, int* posBig, int* posSmall, bool* detail, int (*sudoku)[9][9], int timeInSecs, clock_t loopStartClock);

void getInputControlState(GameState* state);

void getInputStartState(GameState* state, int (*sudoku)[9][9], int* timeInSecs);

int getInputEndState(GameState* state, int* timeInSecs);

int getStateInput(GameState* state, int* posBig, int* posSmall, bool* detail, int (*sudoku)[9][9], int* timeInSecs, clock_t loopStartClock);


