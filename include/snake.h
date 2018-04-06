#ifndef __SNAKE_H__
# define __SNAKE_H__

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#include <stdio.h>

# define MY_RAND(MIN, MAX) ((random() % (MAX - MIN)) + MIN)

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
void    *menu();
void    get_map(char *path, int col, char arr[][col]);
void    gen_sized_map(int p_row, int p_col);
void    list_free(t_list *list);
void    snake_in_map(t_list *list, int col, char arr[][col]);
void    aff_map(int col, int row, char arr[][col]);
void    move(t_list *list, int col, int row, char arr[][col]);
void    put_rand_bonus(int col, int row, char arr[][col]);
void    put_rand_malus(int col, int row, char arr[][col]);

int     init(t_list *list);
int     snake_add(t_list *list, char t);
int     snake_rm_last(t_list *list);
int     count_x(char *c);
int     count_y(char *c);

char    readline(void);
// -------

// LIBMY
void    my_putstr(char *str);
void    my_putchar(char c);
void	my_put_nbr(int n);
// -------

#endif