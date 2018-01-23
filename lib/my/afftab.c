#include	<stdlib.h>

void		afftab(char **tab)
{
  int		i;

  i = 0;
  while (tab[i] != NULL)
    {
      my_putstr(tab[i++]);
      my_putchar('\n');
    }
}
