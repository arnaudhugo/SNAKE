#include "../include/snake.h"

void get_map()
{}

void            snake_in_map(t_list *list, int col, char arr[][col])
{
    t_snake     *e;

    e = list->first;

    while (e)
    {
        // DEBUG
        /*
        printf("-\nx = %d\n", e->location_x);
        printf("y = %d\n", e->location_y);
        printf("nx = %d\n", e->next_x);
        printf("ny = %d\n", e->next_y);*/
        // ---
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