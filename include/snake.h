#ifndef __SNAKE_H__
# define __SNAKE_H__

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h> // A SUPP
#include <fcntl.h>

typedef struct      s_snake
{
    int             location_x;
    int             location_y;
    int             next_x;
    int             next_y;
    struct s_snake  *prev;
    struct s_snake  *next;
}                   t_snake;

typedef struct      s_list
{
    int             size;
    t_snake         *first;
    t_snake         *last;
}                   t_list;

// SOURCE
void    list_free(t_list *list);
void    snake_in_map(t_list *list, int col, char arr[][col]);
void    aff_map(int col, int row, char arr[][col]);
void    move(t_list *list, int col, int row, char arr[][col]);

int     init(t_list *list);
int     snake_add(t_list *list, char t);
int     count_x(char *c);
int     count_y(char *c);

char    readline(void);
// -------

// LIBMY
void    my_putstr(char *str);
void    my_putchar(char c);
// -------

#endif