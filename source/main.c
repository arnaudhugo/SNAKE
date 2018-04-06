#include "../include/snake.h"


/*
char rand_bonus(int row, int col)
{
    int min;
    char array[row][col];

    srand(time(NULL));
    min = 2;
    row = rand() % ((row - 2) - min) + min;
    col = rand() % ((col - 2) - min) + col;
    array[row][col] = 'b';
    return array[row][col];
}*/

int         main() 
{
    char    *path;
    t_list  list;

    init(&list);

    path = "maps/level1.txt";

    // PUT MAP IN ARRAY
    int     map;
    ssize_t file;
    char    buf[400];
    int     row;
    int     col;
    map = open(path, O_RDONLY);
    file = read(map, buf, sizeof(buf));
    col = count_x(buf);
    row = count_y(buf);
    char arr[row][col];
    int x;
    int y;
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
    // ---
    // PUT SNAKE IN ARR
    snake_in_map(&list, col, arr);

    put_rand_bonus(col, row, arr);
    put_rand_malus(col, row, arr);

/*
    int bx;
    int by;

    bx = 0;
    by = 0;

    while (arr[bx][by] == '1' || arr[bx][by] == 's')
    {
        srandom(time(NULL));
        bx = MY_RAND(1, row - 2);
        by = MY_RAND(1, col - 2);
    }
    arr[bx][by] = 'b';*/

    // JEU
    move(&list, col, row, arr);

    list_free(&list);

    return (0);
}