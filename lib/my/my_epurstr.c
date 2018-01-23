#include	<stdlib.h>
#include	<stdio.h>
#include	"my.h"

char		*my_epurstr(char *s, char c)
{
  char		*dest;
  int		i;
  int		j;

  if ((dest = malloc((my_strlen(s) + 1) * sizeof(char))) == NULL)
    return (NULL);
  i = 0;
  j = 0;
  while (s[i] != 0)
    {
      while (s[i] == c && s[i] != 0)
	i++;
      dest[j++] = s[i++];
    }
  dest[j] = 0;
  return (dest);
}
