#ifndef __SNAKE_H__
# define __SNAKE_H__

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

typedef struct      s_snake
{
    int             location_x;
    int             location_y;
    int             next_x;
    int             next_y;
    struct s_snake  *next;
}                   t_snake;

typedef struct      s_list
{
    int             size;
    t_snake         *first;
}                   t_list;

// SOURCE
void    snake_in_map(t_list *list, int col, char arr[][col]);
void    aff_map(int col, int row, char arr[][col]);
void    list_free(t_list *list);
void    move(t_list *list, int col, int row, char arr[][col]);

char    readline(void);

int     list_init(t_list *list);
int     list_add(t_list *list, char t);
int     count_x(char *c);
int     count_y(char *c);
// -------

// LIBMY
void    my_putstr(char *str);
void    my_putchar(char c);
// -------

#endif