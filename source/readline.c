/*
** readline.c for SNAKE in /home/robinet/SNAKE/trunk
** 
** Made by ARNAUD Hugo
** Login   <arnaud_h@etna-alternance.net>
** 
** Started on  Tue Mar 27 02:18:08 2018 ARNAUD Hugo
** Last update Tue Mar 27 02:18:13 2018 ARNAUD Hugo
*/
#include "../include/snake.h"

char		    readline(void)
{
    ssize_t	    ret;
    char		*buff;

    if ((buff = malloc((50 + 1) * sizeof(char))) == NULL)
        return ('\0');
    if ((ret = read(0, buff, 50)) > 1)
    {
        buff[ret - 1] = '\0';
        return (buff[0]);
    }
    free(buff);
    return ('\0');
}
