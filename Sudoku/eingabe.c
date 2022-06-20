#include <stdio.h>
#include "eingabe.h"

void get_input2()
{
    int c = getch();
    switch(c)
    {
    case 72:
        printf("UP\n");
        break;
    case 80:
        printf("DOWN\n");
        break;
    case 77:
        printf("RIGHT\n");
        break;
    case 75:
        printf("LEFT\n");
        break;
    default:
        printf("%i", c);
        break;
    }
}
