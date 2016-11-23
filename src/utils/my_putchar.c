/*
** my_putchar.c for pushswap in /home/raphael.goulmot/rendu/CPE_2016_Pushswap
** 
** Made by Raphaël Goulmot
** Login   <raphael.goulmot@epitech.net>
** 
** Started on  Tue Nov 22 16:16:27 2016 Raphaël Goulmot
** Last update Tue Nov 22 16:16:59 2016 Raphaël Goulmot
*/

#include <unistd.h>
#include "utils.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}
