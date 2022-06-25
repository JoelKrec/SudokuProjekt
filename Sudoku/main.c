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
    Game_state state = initialize_game_state();

    int sudoku[9][9] = {{0,1,2,3,4,5,6,7,8}, {0,1,2,3,4,5,6,7,8}, {0,1,2,3,4,5,6,7,8}, {0,1,2,3,4,5,6,7,8}, {0,1,2,3,4,5,6,7,8}, {0,1,2,3,4,5,6,7,8}, {0,1,2,3,4,5,6,7,8}, {0,1,2,3,4,5,6,7,8}, {0,1,2,3,4,5,6,7,8}};
    clock_t st;
    int frame = 0;

    int posX = 0;
    int posY = 0;
    bool detail = false;

    st = clock();
/*
    while(1)
    {
            //system("cls");

            st = clock();

            Game_state state;

            state.state = 1;

            printf("%i", frame);

            printf("\n\n");

            printf("\nx: %i \ny: %i", posX, posY);
            printf("\nSmall array = %d", detail);


            get_state_input(&state, &posX, &posY, &detail, &sudoku, &st);

            printf("\n\n\n");

            int timeInSecs = get_current_sudoku_time_in_secs(st);

            printf("Time it took was %i seconds", timeInSecs);

            printf("\n\n\n");

            frame++;


    }
*/
    show_control_screen();

    return 0;
}
