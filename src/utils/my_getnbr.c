/*
** my_getnbr.c for pushswap in /home/raphael.goulmot/rendu/CPE_2016_Pushswap
** 
** Made by Raphaël Goulmot
** Login   <raphael.goulmot@epitech.net>
** 
** Started on  Tue Nov 22 13:28:08 2016 Raphaël Goulmot
** Last update Tue Nov 22 13:37:19 2016 Raphaël Goulmot
*/

int	my_getnbr(char *str)
{
  int	value;
  int	i;

  value = 0;
  i = 0;
  while (str[i++])
    {
      value *= 10;
      value += str[i - 1] - 48;
    }
  return (value);
}
