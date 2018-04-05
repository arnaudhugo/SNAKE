#include "../include/snake.h"

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
}

void            direction(t_list *list, char t, int location_x, int location_y, int col, char arr[][col])
{
    t_snake     *e;
    char bonus;
    
    if (arr[location_x][location_y] == 'b')
    {
      bonus = rand_bonus(row, col);
      snake_add(list, t);
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
