#include "../include/snake.h"

void        get_map(char *path, int col, char arr[][col])
{
    int     map;
    int     x;
    int     y;
    char    buf[400];
    ssize_t file;
    t_list  list;
    
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
}

void            snake_in_map(t_list *list, int col, char arr[][col])
{
    t_snake     *e;

    e = list->first;

    while (e)
    {
        arr[e->location_x][e->location_y] = 's';
        arr[e->next_x][e->next_y] = ' ';
        e = e->next;
    }
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

void        gen_sized_map(int p_row, int p_col)
{
    char    *path;
    int     fd;
    int     x;
    int     y;
    char    c;
    char    e;
    char    d;
    char    t;
    ssize_t file;
    
    x = 0;
    y = 0;
    c = '1';
    e = ' ';
    d = '\n';
    path = "maps/gen_map.txt";
    fd = open(path, O_RDWR | O_TRUNC);

    while (x < p_row)
    {
        y = 0;
        while (y < p_col)
        {
            if (x == 0 || x == (p_row - 1))
                write(fd, &c, 1);
            else
            {
                if (y == 0 || y == (p_col - 1))
                    write(fd, &c, 1);
                else
                    write(fd, &e, 1);
            }
            y++;
        }
        write(fd, &d, 1);
        x++;
    }
}