#include "../include/snake.h"

// Initialisation
int             init(t_list *list)
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
    snake->prev = NULL;
    snake->next = NULL;
    list->first = snake;
    list->last = snake;
    return (0);
}

// Ajouter un element
int             snake_add(t_list *list, char t)
{
    t_snake     *snake;
    t_snake     *e;

    if (!list)
        return (-1);
    if ((snake = malloc(sizeof(*snake))) == NULL)
        return (-1);
    list->size += 1;
    
    // Add fin
    snake->next = NULL;
    e = list->first;

    if (e == NULL)
    {
        list->first = snake;
        return (0);
    }
    while (e->next != NULL)
        e = e->next;
    snake->prev = e;

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
    list->last = snake;
    return (0);
}

// Supprimer un element
int             snake_rm_last(t_list *list)
{
    t_snake     *snake;
    t_snake     *e;

    snake = list->last;
    if (snake == NULL)
        return (-1);
    if (list->size > 1)
    {
        e = snake->prev;
        list->last = e;
        list->size -= 1;
        e->next = NULL;
        free(snake);
    }
    else
        return (-1);
    return (0);
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
