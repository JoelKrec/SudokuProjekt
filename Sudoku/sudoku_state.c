#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include "sudoku_state.h"

// returns a state in it's default position (start state (0))
GameState initializeGameState()
{
    GameState emptyState;

    emptyState.state = 0;

    return emptyState;
}


// params: a pointer with the GameState you want to change and your desired target state from 0 to 3
// changes the value of the pointer to the desired target state with the following rules:
// from: 0 to: 1
// from: 1 to: 2
// from: 2 to: 1, 3
// from: 3 to 1
void tryChangeState(GameState* state, int targetState)
{
    switch(state->state)
    {
    case 0:
        if(targetState == 1)
        {
            state->state = targetState;
        }
        break;
    case 1:
        if(targetState == 2)
        {
            (*state).state = targetState;
        }
        break;
    case 2:
        if(targetState == 3 || targetState == 1)
        {
            state->state = targetState;
        }
        break;
    case 3:
        if(targetState == 0)
        {
            state->state = targetState;
        }
        break;
    default:
        //Do nothing
        break;
    }

}
