#include "../include/snake.h"

void        get_map(char path)
{
    char    arr[row][col];
    int     x;
    int     y;

    x = 0;
    y = 0;
    map = open(path, O_RDONLY);

    while (file > 0)
    {
        file = read(map, buf, 1);
        if (*buf != '\n')
        {
            arr[x][y] = *buf;
            y++;
        }
        else
        {
            arr[x][y] = '\n';
            x++;
            y = 0;
        }
    }
    return (arr);
}

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