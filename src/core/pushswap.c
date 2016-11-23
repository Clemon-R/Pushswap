/*
** pushswap.h for pushswap in /home/raphael.goulmot/rendu/CPE_2016_Pushswap
** 
** Made by Raphaël Goulmot
** Login   <raphael.goulmot@epitech.net>
** 
** Started on  Tue Nov 22 13:46:57 2016 Raphaël Goulmot
** Last update Wed Nov 23 16:12:25 2016 Raphaël Goulmot
*/
#include "utils.h"
#include <stdlib.h>

void	my_swap(int *list, int i1, int i2)
{
  int	tmp;

  tmp = list[i1];
  list[i1] = list[i2];
  list[i2] = tmp;
  my_putstr("s");
}

void	rotate(int *list, int size, char sens)
{
  int	tmp;
  int	index;

  if (!sens)
    {
      index = 0;
      tmp = list[0];
      while (index++ < size)
	list[index - 1] = index == size ? tmp : list[index];
    }
  else
    {
      index = size - 1;
      tmp = list[size - 1];
      while (index-- >= 0)
	list[index + 1] = index == -1 ? tmp : list[index];
    }
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

void	commands(t_list *list, int *index, char str)
{
  if (*index == 1)
    my_swap(str ? list->lb : list->la, *index, *index - 1);
  else if (!str && list->la[list->sa - 1] < list->la[0])
    rotate(list->la, list->sa, 1);
  else if (str && list->lb[list->sb - 1] > list->lb[0])
    rotate(list->lb, list->sb, 1);
  else if (!str && list->la[0] > list->la[list->sa - 1])
    rotate(list->la, list->sa, 0);
  else if (str && list->lb[0] < list->lb[list->sb - 1])
    rotate(list->lb, list->sb, 0);
  else
    {
      if (!str)
	exchange(list->la, list->lb, list->sa--, list->sb++);
      else
	exchange(list->lb, list->la, list->sb--, list->sa++);
      my_putchar(str ? 'a' : 'b');
      *index = 1;
      return;
    }
  my_putchar(str ? 'b' : 'a');
}

t_list	*pushswap(int *list, int size)
{
  char	check;
  char	space;
  int	index;
  t_list	*values;

  values = malloc(sizeof(t_list));
  values->la = list;
  values->sa = size;
  values->lb = malloc(sizeof(int) * size);
  values->sb = 0;
  check = 0;
  space = 1;
  while (!check)
    {
      check = 1;
      index = 1;
      while (index < values->sa || index < values->sb)
	{
	  while (values->la[index] < values->la[index - 1])
	    {
	      check = 0;
	      if (!space)
		my_putchar(' ');
	      space = 0;
	      commands(values, &index, 0);
	    }
	  while (values->lb[index] > values->lb[index - 1])
	    {
	      check = 0;
	      my_putchar(' ');
	      commands(values, &index, 1);
	    }
	  index++;
	}
    }
  while (values->sb-- > 0)
    {
      my_putchar(' ');
      exchange(values->lb, values->la, values->sb + 1, values->sa++);
      my_putchar('a');
    }
  my_putchar('\n');
  return (values);
}
