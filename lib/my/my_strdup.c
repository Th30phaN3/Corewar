#include	<stdlib.h>
#include	<stdio.h>

char		*my_strdup(char *src)
{
  char		*dest;
  int		i;

  if ((dest = malloc(my_strlen(src) * sizeof(char) + 1)) == NULL)
    return (NULL);
  i = 0;
  while (src[i])
    dest[i] = src[i++];
  dest[i] = 0;
  return (dest);
}
