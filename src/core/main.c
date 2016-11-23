/*
** main.c for pushswap in /home/raphael.goulmot/rendu/CPE_2016_Pushswap
** 
** Made by Raphaël Goulmot
** Login   <raphael.goulmot@epitech.net>
** 
** Started on  Tue Nov 22 13:22:08 2016 Raphaël Goulmot
** Last update Tue Nov 22 19:10:00 2016 Raphaël Goulmot
*/
#include "utils.h"
#include <stdlib.h>

int	main(int argc, char **argv)
{
  int	*list_nbr;
  int	index;

  index = 1;
  list_nbr = malloc(sizeof(int) * (argc - 1));
  if (list_nbr == NULL)
    return (84);
  while (argv[index++])
    list_nbr[index - 2] = my_getnbr(argv[index - 1]);
  pushswap(list_nbr, argc - 1);
  return (0);
}
