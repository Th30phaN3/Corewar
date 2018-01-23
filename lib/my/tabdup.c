#include	<stdio.h>
#include	<stdlib.h>

char		*my_strdup(char*);

char            **tabdup(char **src)
{
  char          **tab;
  int           i;

  if ((tab = malloc(sizeof(char**) * (tablen(src) + 1))) == NULL)
    return (NULL);
  i = 0;
  while (src[i] != NULL)
    {
      tab[i] = my_strdup(src[i]);
      i++;
    }
  tab[i] = NULL;
  return (tab);
}
