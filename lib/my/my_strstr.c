#include	<stdio.h>

int		mistrlen(char *str)
{
  int		i;

  i = 0;
  while (str[i] != 0)
    i++;
  return (i);
}

char		*my_strstr(char *str, char *to_find)
{
  int		i;

  while (*str != 0)
    {
      i = 0;
      while (str[i] == to_find[i])
	i++;
      if (i == mistrlen(to_find))
      	return (str);
      str++;
    }
  return (NULL);
}
