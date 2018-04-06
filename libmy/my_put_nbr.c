/*
** my_put_nbr.c for  in /home/arnaud/FDI-DVC1/Libmy02/libmy_02
** 
** Made by ARNAUD Hugo
** Login   <arnaud_h@etna-alternance.net>
** 
** Started on  Mon Oct  2 17:03:10 2017 ARNAUD Hugo
** Last update Tue Oct  3 10:05:22 2017 ARNAUD Hugo
*/
#include "../include/snake.h"

void	my_put_nbr(int n)
{
  int	a;

  a = 0;
  if (n < 0)
    {
      write (1, "-", 1);
      n = n * (-1);
    }
  if (n >= 10)
    {
      a = n % 10;
      a = a + 48;
      n = n / 10;
      my_put_nbr(n);
      write (1, &a, 1);
    }
  else 
    {
      a = n + 48;
      write (1, &a, 1);
    }
}
