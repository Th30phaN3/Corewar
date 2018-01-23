#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "my.h"

char            *my_strdup(char *src)
{
  char          *dest;
  int           i;

  i = 0;
  while (src[i])
    i++;
  if ((dest = malloc(i * sizeof(char) + 1)) == NULL)
    return (NULL);
  i = 0;
  while (src[i])
    dest[i] = src[i++];
  dest[i] = 0;
  return (dest);
}

char            *my_strcat_malloc(char *dest, char *src)
{
  char          *new;
  int           i;
  int           j;

  i = 0;
  j = 0;
  while (dest[i])
    i++;
  while (src[j])
    j++;
  if ((new = malloc((i + j + 1) * sizeof(char))) == NULL)
    return (NULL);
  i = 0;
  j = 0;
  while (dest[i])
    new[j++] = dest[i++];
  i = 0;
  while (src[i])
    new[j++] = src[i++];
  new[j] = 0;
  free(dest);
  return (new);
}

char		*get_str_chariot(char *save)
{
  int		i;
  char		*str;

  i = 0;
  while (save[i] != '\n' && save[i] != 0)
    i++;
  if ((str = malloc((i + 1) * sizeof(*str))) == NULL)
    return (NULL);
  i = 0;
  while (save[i] != '\n' && save[i] != 0)
    str[i] = save[i++];
  str[i] = 0;
  return (str);
}

int		check_if_chariot(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    {
      if (str[i++] == '\n')
	return (1);
    }
  return (0);
}

char		*get_next_line(const int fd)
{
  static char	*save = "";
  char		*str;
  char		*res;
  int		nb_lu;
  char		buf[READ_SIZE];

  str = my_strdup(save);
  nb_lu = 1;
  while (check_if_chariot(str) != 1 && nb_lu != 0)
    {
      if ((nb_lu = read(fd, buf, READ_SIZE)) == -1)
	return (NULL);
      if (nb_lu == 0 && str[0] == 0)
	return (NULL);
      buf[nb_lu] = 0;
      str = my_strcat_malloc(str, buf);
    }
  res = get_str_chariot(str);
  while (*str != '\n' && *str != 0)
    str++;
  if (*str == '\n')
    str++;
  save = my_strdup(str);
  return (res);
}
