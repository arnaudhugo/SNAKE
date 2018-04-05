#include "../include/snake.h"


int     count_x(char *c)
{
    int i;
    
    i = 0;
    while (c[i] != '\n')
        i++;
    return i;
}

int     count_y(char *c)
{
    int count;
    int i;

    count = 0;
    i = 0;
    while (c[i] != '\0')
    {
        if (c[i] == '\n')
            count++;
        i++;
    }
    count++;
    return count;
}
