/*
** pushswap.h for pushswap in /home/raphael.goulmot/rendu/CPE_2016_Pushswap
** 
** Made by Raphaël Goulmot
** Login   <raphael.goulmot@epitech.net>
** 
** Started on  Tue Nov 22 13:46:57 2016 Raphaël Goulmot
** Last update Sun Nov 27 17:36:40 2016 Raphaël Goulmot
*/
#include "utils.h"
#include <stdlib.h>

void	rotate(int *list, int size, char sens)
{
  int	tmp;
  int	index;

  index = !sens ? 0 : size - 1;
  tmp = !sens ? list[0] : list[size - 1];
  while ((!sens && index ++ < size) || (sens && index-- >= 0))
    list[index + (!sens ? -1 : 1)] = ((!sens && index == size)
		      || (sens && index == -1)) ? tmp : list[index];
  my_putstr(!sens ? "r" : "rr");
}

void	exchange(int *list1, int *list2, int s1, int s2)
{
  int	i1;
  int	i2;

  i2 = s2;
  while (i2-- > 0)
    list2[i2 + 1] = list2[i2];
  list2[0] = list1[0];
  i1 = 0;
  while (i1++ < s1 - 1)
    list1[i1 - 1] = list1[i1];
  my_putstr("p");
}

char	commands(t_list *list, int *index, char str)
{
  int	tmp;

  if ((!str && list->la[0] > list->la[list->sa - 1])
      || (str && list->lb[0] < list->lb[list->sb - 1]))
    rotate(!str ? list->la : list->lb, !str ? list->sa : list->sb, 0);
  else if ((!str && list->la[list->sa - 1] < list->la[0])
	   || (str && list->lb[list->sb - 1] > list->lb[0]))
    rotate(!str ? list->la : list->lb, !str ? list->sa : list->sb, 1);
  else if (*index == 1)
    {
      tmp = (str ? list->lb[*index] : list->la[*index]);
      if (str)
	list->lb[*index] = list->lb[*index - 1];
      else
	list->la[*index] = list->la[*index - 1];
      if (str)
	list->lb[*index - 1] = tmp;
      else
	list->la[*index - 1] = tmp;
      my_putstr("s");
    }
  else
    return (0);
  my_putchar(str ? 'b' : 'a');
  return (1);
}

void	pushswap_extend(t_list *values, int *i, char *check)
{
  while ((*i > 0 && *i < values->sa && values->la[*i] < values->la[*i - 1])
	 || (*i > 0 && *i < values->sb && values->lb[*i] > values->lb[*i - 1])
	 || (*check == 2 && values->sb > 0))
    {
      if (values->now >= 0)
	my_putchar(' ');
      *check = 1;
      values->now = !(*i < values->sa && values->la[*i] < values->la[*i - 1]
		      && *check != 2);
      if (*check == 2 || !commands(values, i, values->now))
	{
	  if (!values->now)
	    exchange(values->la, values->lb, values->sa--, values->sb++);
	  else
	    exchange(values->lb, values->la, values->sb--, values->sa++);
	  my_putchar(values->now ? 'a' : 'b');
	}
      *i = 0;
    }
}

void	pushswap(int *list, int size)
{
  int	i;
  t_list	*values;
  char	check;

  values = malloc(sizeof(t_list));
  values->la = list;
  values->sa = size;
  values->lb = malloc(sizeof(int) * size);
  values->sb = 0;
  values->now = -1;
  i = 0;
  check = 1;
  while (check)
    {
      check = check != 2 ? 0 : check;
      i = check == 2 ? 0 : i;
      while (i < values->sa || i < values->sb)
	{
	  pushswap_extend(values, &i, &check);
	  i++;
	}
      check = !check ? 2 : check == 2 ? 0 : check;
    }
  free(values);
  my_putchar('\n');
}
