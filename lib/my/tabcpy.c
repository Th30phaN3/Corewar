#include	<stdlib.h>

char		*my_strcpy(char*, char*);

char		**tabcpy(char **src, char **tab)
{
  int		i;

  i = 0;
  while (src[i] != NULL)
    {
      tab[i] = my_strcpy(tab[i], src[i]);
      i++;
    }
  tab[i] = NULL;
  return (tab);
}
