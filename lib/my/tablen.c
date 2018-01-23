#include	<stdlib.h>
#include	<stdio.h>

int	tablen(char **tab)
{
  int		i;

  i = 0;
  while (tab[i] != NULL)
    i++;
  return (i);
}
