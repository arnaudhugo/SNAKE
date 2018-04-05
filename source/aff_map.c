#include "../include/snake.h"

void        aff_map(int col, int row, char arr[][col])
{
    int     i;
    int     j;

    i = 0;
    j = 0;

    while (i < row)
    {
        j = 0;
        while (j < col)
        {
            my_putchar(arr[i][j]);
            j++;
        }
        my_putstr("\n");
        i++;
    }
}