#include "control_screen.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <windows.h>


//shows the control screen
void showControlScreen()
{
    printHeadingMain("Controls");

    printControls();

    printf("\n");

    printFullLine(getScreenWidth(), '_');

    char* continueText = "Press any key to continue!";

    int paddingSize = (getScreenWidth() - strlen(continueText)) / 2;

    for(int i = 0; i < paddingSize; i++)
    {
       printf(" ");
    }

    printf("%s", continueText);
}

//prints the controls predefined in two arrays centered around the filler string
void printControls()
{
    int controlsArraysLength = 5;

    char* controlsKeysArray[5] = {"WASD or arrow keys",
    "Space bar",
    "C",
    "Return",
    "Escape"};

    char* controlsDefinitionArray[5] = {"Move in fields or blocks",
    "Switch between blocks and fields",
    "Shows controls screen",
    "Checks your board for completion",
    "Saves and quits the game"};

    char* filler = "    <-->   ";

    for(int i = 0; i < controlsArraysLength; i++)
    {
        printf("\n");

        int padding = getScreenWidth() / 2 - strlen(controlsKeysArray[i]) - 7;

        for(int j = 0; j < padding; j++)
        {
            printf(" ");
        }

        printf("%s%s%s\n", controlsKeysArray[i], filler, controlsDefinitionArray[i]);
    }
}

//params: string you want to print, char which you want to surround your heading, int how wide you want your side lines to be
void printHeading(char* header, char frameChar, int borderWidth)
{
    int screenWidth = getScreenWidth();

    printFullLine(screenWidth, frameChar);

    printBorderLine(screenWidth, frameChar, borderWidth);

    for(int i = 0; i < borderWidth; i++) {
        printf("%c", frameChar);
    }

    int headerLength = strlen(header);

    if(headerLength % 2 != 0)
    {
        printf(" ");
    }

    int emptySpaceNextToHeader = (screenWidth - (borderWidth * 2) - headerLength) / 2;

    for(int i = 0; i < emptySpaceNextToHeader; i++)
    {
        printf(" ");
    }

    printf("%s", header);

    for(int i = 0; i < emptySpaceNextToHeader; i++)
    {
        printf(" ");
    }

    for(int i = 0; i < borderWidth; i++) {
        printf("%c", frameChar);
    }

    printBorderLine(screenWidth, frameChar, borderWidth);

    printFullLine(screenWidth, frameChar);
}

//prints the heading with '#' and a thickness of 2
void printHeadingMain(char* header)
{
    printHeading(header, '#', 2);
}

//prints the heading with '.' and a thickness of 1
void printHeadingSub(char* header)
{
    printHeading(header, '.', 1);
}

//params: the width of the screen and a char you want to use as a line
//
//prints a line starting at the current cursor position which is as long as screenWidth is with the chosen char
void printFullLine(int screenWidth, char frameChar)
{
    for(int i = 0; i < screenWidth; i++)
    {
        printf("%c", frameChar);
    }
}

//params: screenWidth, a char to print and the border thickness
//
//prints two dots starting at the current cursor position and the screenWidth with the chosen char
void printBorderLine(int screenWidth, char frameChar, int borderWidth)
{
    for(int i = 0; i < borderWidth; i++) {
        printf("%c", frameChar);
    }
    for(int i = 0; i < screenWidth - borderWidth * 2; i++) {
        printf(" ");
    }
    for(int i = 0; i < borderWidth; i++) {
        printf("%c", frameChar);
    }
}

//calculates and returns the current width of the terminal
int getScreenWidth()
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int ret;
    ret = GetConsoleScreenBufferInfo(GetStdHandle( STD_OUTPUT_HANDLE ),&csbi);

    return csbi.dwSize.X;
}
