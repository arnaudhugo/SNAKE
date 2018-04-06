#include "../include/snake.h"

void            direction(t_list *list, char t, int location_x, int location_y, int col, int row, char arr[][col])
{
    int         bx;
    int         by;
    t_snake     *e;

    bx = 0;
    by = 0;
    
    if (arr[location_x][location_y] == 'b')
    {
        put_rand_bonus(col, row, arr);
        snake_add(list, t);
    }
    if (arr[location_x][location_y] == 'm')
    {
        put_rand_malus(col, row, arr);
        if(!snake_rm_last(list))
            return ;
    }
    e = list->last;
    while (e && list->first != e)
    {
        e->location_x = e->prev->location_x;
        e->location_y = e->prev->location_y;
        e->next_x = e->prev->next_x;
        e->next_y = e->prev->next_y;
        e = e->prev;
    }
    e = list->first;

    e->next_x = e->location_x;
    e->next_y = e->location_y;
    e->location_x = location_x;
    e->location_y = location_y;
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
            direction(list, t, e->location_x, e->location_y + 1, col, row, arr);
        else if (t == 'a')
            direction(list, t, e->location_x, e->location_y - 1, col, row, arr);
        else if (t == 'w')
            direction(list, t, e->location_x - 1, e->location_y, col, row, arr);
        else if (t == 's')
            direction(list, t, e->location_x + 1, e->location_y, col, row, arr);
        aff_map(col, row, arr);
        /*
        int v = list->size;
        my_putstr("Votre score :");
        my_putchar(list->size);
        */
        t = readline();
    }
}
