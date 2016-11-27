/*
** utils.h for pushswap in /home/raphael.goulmot/rendu/CPE_2016_Pushswap
** 
** Made by Raphaël Goulmot
** Login   <raphael.goulmot@epitech.net>
** 
** Started on  Tue Nov 22 13:37:39 2016 Raphaël Goulmot
** Last update Sun Nov 27 17:43:41 2016 Raphaël Goulmot
*/

#ifndef UTILS_H_
# define UTILS_H_

typedef struct	s_list
{
  int		*la;
  int		sa;
  int		*lb;
  int		sb;
  char		now;
}		t_list;

void	my_putchar(char);
void	my_putstr(char *);
int	my_getnbr(char *);
void	rotate(int *, int, char);
void	exchange(int *, int *, int, int);
char	commands(t_list *, int *, char);
void	pushswap_extend(t_list *, int *, char *);
void	pushswap(int *, int);
void	my_put_nbr(long);

#endif /* !UTILS_H_ */
