#include "../include/snake.h"

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

    if (path == NULL)
        path = "maps/level1.txt";
    map = open(path, O_RDONLY);
    file = read(map, buf, sizeof(buf));
    col = count_x(buf);
    row = count_y(buf);

    char    arr[row][col];

    get_map(path, col, arr);
    // ---

    // PUT SNAKE IN ARR
    snake_in_map(&list, col, arr);

    // PUT BONUS AND MALUS ON MAP
    put_rand_bonus(col, row, arr);
    put_rand_malus(col, row, arr);

    // GAME
    move(&list, col, row, arr);

    list_free(&list);

    return (0);
}