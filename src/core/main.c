/*
** main.c for pushswap in /home/raphael.goulmot/rendu/CPE_2016_Pushswap
** 
** Made by Raphaël Goulmot
** Login   <raphael.goulmot@epitech.net>
** 
** Started on  Tue Nov 22 13:22:08 2016 Raphaël Goulmot
** Last update Thu Nov 24 15:10:39 2016 Raphaël Goulmot
*/
#include "utils.h"
#include <stdlib.h>

int	main(int argc, char **argv)
{
  int	*list_nbr;
  int	i;

  list_nbr = malloc(sizeof(int) * (argc - 1));
  if (list_nbr == NULL)
    return (84);
  i = 1;
  while (argv[i++])
    list_nbr[i - 2] = my_getnbr(argv[i - 1]);
  pushswap(list_nbr, argc - 1);
  return (0);
}
