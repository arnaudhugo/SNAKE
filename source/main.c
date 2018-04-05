#include "../include/snake.h"

int         main() 
{
    char    *path;
    t_list  list;
    
    path = "maps/level1.txt";

    init(&list);

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
    get_map(path);

    // PUT SNAKE IN ARR
    snake_in_map(&list, col, arr);

    // JEU
    move(&list, col, row, arr);
    
    list_free(&list);
    return (0);
}