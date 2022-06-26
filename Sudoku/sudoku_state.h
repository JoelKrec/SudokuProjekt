#pragma once

typedef struct gameState
{
    int state;
} GameState;


GameState initializeGameState();

void tryChangeState(GameState* state, int targetState);
