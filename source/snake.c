#include "../include/snake.h"

int             list_init(t_list *list)
{
    t_snake     *snake;

    if (!list)
        return (-1);
    if ((snake = malloc(sizeof(*snake))) == NULL)
        return (-1);
    
    list->size = 1;
    snake->location_x = 4;
    snake->location_y = 13;
    snake->next_x = 4;
    snake->next_y = 12;
    list->first = snake;

    return (0);
}

// Ajouter un element en fin de list
int             list_add(t_list *list, char t)
{
    t_snake     *snake;
    t_snake     *e;

    if (!list)
        return (-1);
    if ((snake = malloc(sizeof(*snake))) == NULL)
        return (-1);
    
    list->size += 1;
    snake->next = NULL;
    e = list->first;

    if (e == NULL) // check si list vide
    {
        list->first = snake;
        return (0);
    }
    while (e->next != NULL) // Parcours de la list
        e = e->next;
    snake->location_x = e->next_x;
    snake->location_y = e->next_y;

    if (t == 'd')
    {
        snake->next_x = e->next_x;
        snake->next_y = e->next_y - 1;
    }
    else if (t == 'a')
    {
        snake->next_x = e->next_x;
        snake->next_y = e->next_y + 1;
    }
    else if (t == 'w')
    {
        snake->next_x = e->next_x + 1;
        snake->next_y = e->next_y;
    }
    else if (t == 's')
    {
        snake->next_x = e->next_x - 1;
        snake->next_y = e->next_y;
    }

    e->next = snake;
    return (0);
}

// Supprimer un element de la list
/*
int         list_sub(t_list *list, int value)
{
    t_elem  *prev;
    t_elem  *elem;

    prev = NULL;
    elem = list->first;
    while (elem)
    {
        if (elem->value == value)
        {
            if (prev)
                prev->next = elem->next;
            else
                list->first = elem->next;
            free(elem);
            return (0);
        }
        prev = elem;
        elem = elem->next;
    }
    return (-1);
}
*/

void            snake_in_map(t_list *list, int col, char arr[][col])
{
    t_snake     *e;

    e = list->first;

    while (e)
    {
        printf("x = %d\n", e->location_x);
        printf("y = %d\n", e->location_y);
        arr[e->location_x][e->location_y] = 's';
        arr[e->next_x][e->next_y] = ' ';
        e = e->next;
    }
}

// Vide la list
void            list_free(t_list *list)
{
    t_snake     *next;
    t_snake     *snake;

    snake = list->first;

    while (snake)
    {
        next = snake->next;
        free(snake);
        snake = next;
    }
}
