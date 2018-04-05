#include "../include/snake.h"

void            direction(t_list *list, char t, int location_x, int location_y, int col, char arr[][col])
{
    int         tmp_x;
    int         tmp_y;
    t_snake     *e;

    tmp_x = 0;
    tmp_y = 0;
    e = list->first;

    if (arr[location_x][location_y] == 'b')
    {
        snake_add(list, t);
        snake_in_map(list, col, arr);
    }
    while (e)
    {
        if (list->first = e)
        {               
            e->next_x = e->location_x;
            e->next_y = e->location_y;
            e->location_x = location_x;
            e->location_y = location_y;

            tmp_x = e->next_x;
            tmp_y = e->next_y;

            e = e->next;
        }
        if (list->size > 1)
        {
            e->next_x = e->location_x;
            e->next_y = e->location_y;
            e->location_x = tmp_x;
            e->location_y = tmp_y;
            e = e->next;
        }
    }
    snake_in_map(list, col, arr);
}

void            move(t_list *list, int col, int row, char arr[][col])
{
    char        t;
    t_snake     *e;

    t = '\0';

    while (t != 'q')
    {
        e = list->first;

        //my_putstr("\033c\n");
        if (t == 'd') 
            direction(list, t, e->location_x, e->location_y + 1, col, arr);
        else if (t == 'a')
            direction(list, t, e->location_x, e->location_y - 1, col, arr);
        else if (t == 'w')
            direction(list, t, e->location_x - 1, e->location_y, col, arr);
        else if (t == 's')
            direction(list, t, e->location_x + 1, e->location_y, col, arr);
        aff_map(col, row, arr);
        t = readline();
    }
}