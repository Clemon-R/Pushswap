/*
** utils.h for pushswap in /home/raphael.goulmot/rendu/CPE_2016_Pushswap
** 
** Made by Raphaël Goulmot
** Login   <raphael.goulmot@epitech.net>
** 
** Started on  Tue Nov 22 13:37:39 2016 Raphaël Goulmot
** Last update Tue Nov 22 17:45:32 2016 Raphaël Goulmot
*/

#ifndef UTILS_H_
# define UTILS_H_

typedef struct	s_list
{
  int		*la;
  int		sa;
  int		*lb;
  int		sb;
}		t_list;

void	my_putchar(char);
void	my_putstr(char *);
int	my_getnbr(char *);
t_list	*pushswap(int *, int);
void	my_put_nbr(long);

#endif /* !UTILS_H_ */
