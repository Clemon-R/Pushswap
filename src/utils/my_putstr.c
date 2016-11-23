/*
** my_putstr.c for pushswap in /home/raphael.goulmot/rendu/CPE_2016_Pushswap
** 
** Made by Raphaël Goulmot
** Login   <raphael.goulmot@epitech.net>
** 
** Started on  Tue Nov 22 16:18:45 2016 Raphaël Goulmot
** Last update Tue Nov 22 16:19:28 2016 Raphaël Goulmot
*/

#include "utils.h"

void	my_putstr(char *str)
{
  int	index;

  index = 0;
  while (str[index++])
    my_putchar(str[index - 1]);
}
