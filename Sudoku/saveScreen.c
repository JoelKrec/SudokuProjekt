#include "saveScreen.h"
#include "displayGame.h"

//params: clock startet at the beginning of the loop, the total time and a pointer to the current board
//
//Shows the save screen, lets the user chose a name and then saves the current board with a time stamp
void saveSudoku(clock_t loopStartTime, int timeInSecs,int (*sudoku)[9][9])
{
    Savegame game;

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            game.sudoku[i][j] = (*sudoku)[i][j];
        }
    }

    game.timePlayed = timeInSecs + getCurrentSudokuTimeInSecs(loopStartTime);

    cls();

    printHeadingMain("Save Game");

    printf("\n\n\n");

    printf("            Name your savegame file: ");

    char name[128];

    bool isCorrectName = false;
    do
    {
        setCursor(37, 7);                                           //clears any unwanted name and lets the user type another one
        printf("                                           ");
        setCursor(37, 7);

        scanf("%s", name);



        printf("\n\nAre you sure you want to name your savegame file '%s'?    -   Press Y to confirm or any other key to decline           ", name);

        char c = getch();

        if(c == 'y' || c == 'Y')
        {
            isCorrectName = true;
        }
        else
        {
            isCorrectName = false;
        }

    }while(!isCorrectName);

    game.name = name;

    char* savedName = save(game);

    printf("\n\n");

    if(savedName == "-1")
    {
        printHeadingSub("Could not save the game    -    Try to check your 'savegames' folder permission!");
    }
    else
    {
        char* saveMessage;

        asprintf(&saveMessage, "Saved game as %s    -    Press any key to quit!", savedName);

        printHeadingSub(saveMessage);
    }
}
