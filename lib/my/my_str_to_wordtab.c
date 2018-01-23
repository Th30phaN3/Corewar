#include<stdlib.h>
#include<stdio.h>

char            **my_str_to_wordtab(char *str, char c)
{
  char          **tab;
  int           i;
  int           j;
  int           k;

  i = 0;
  j = 0;
  if ((tab = malloc((my_strlen(str) + 1) * sizeof(tab))) == NULL)
    return (NULL);
  while (str[i])
    {
      k = 0;
      if ((tab[j] = malloc((my_strlen(str) + 1) * sizeof(char))) == NULL)
        return (NULL);
      while (str[i] == c && str[i])
        i++;
      while (str[i] != c && str[i])
        tab[j][k++] = str[i++];
      tab[j++][k] = 0;
      while (str[i] == c && str[i])
        i++;
    }
  tab[j] = NULL;
  return (tab);
}
