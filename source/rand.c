#include "../include/snake.h"

void    put_rand_bonus(int col, int row, char arr[][col])
{
    int bx;
    int by;

    bx = 0;
    by = 0;

    while (arr[bx][by] == '1' || arr[bx][by] == 's' || arr[bx][by] == 'm')
    {
        srandom(time(NULL));
        bx = MY_RAND(1, row - 2);
        by = MY_RAND(1, col - 2);
    }
    arr[bx][by] = 'b';
}

void    put_rand_malus(int col, int row, char arr[][col])
{
    int bx;
    int by;

    bx = 0;
    by = 0;

    while (arr[bx][by] == '1' || arr[bx][by] == 's' || arr[bx][by] == 'b')
    {
        srandom(time(NULL));
        bx = MY_RAND(1, row - 2);
        by = MY_RAND(1, col - 2);
    }
    arr[bx][by] = 'm';
}