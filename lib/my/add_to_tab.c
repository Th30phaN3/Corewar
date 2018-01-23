#include	<stdio.h>
#include	<stdlib.h>

char		*my_strdup(char*);

char            **add_to_tab(char *str, char **tab)
{
  char          **new;
  int           i;

  if ((new = malloc(sizeof(char**) * (tablen(tab) + 2))) == NULL)
    return (NULL);
  i = 0;
  while (tab[i] != NULL)
    {
      new[i] = my_strdup(tab[i]);
      i++;
    }
  new[i] = my_strdup(str);
  i++;
  new[i] = NULL;
  free_tab(tab);
  return (new);
}
