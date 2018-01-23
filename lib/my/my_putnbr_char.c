#include	<stdlib.h>
#include	<stdio.h>
#include	"my.h"

int		count_malloc(int nb)
{
  int		count;

  count = 0;
  while (nb > 0)
    {
      nb = nb / 10;
      count++;
    }
  return (count);
}

char		*my_putnbr_char(int nb)
{
  char		*dest;
  int		i;
  int		check_neg;

  i = 0;
  if ((dest = malloc(sizeof(char) * (count_malloc(nb) + 2))) == NULL)
    return (NULL);
  check_neg = 0;
  if (nb < 0)
    {
      check_neg = 1;
      nb *= -1;
    }
  while (nb > 0)
    {
      dest[i++] = nb % 10 + 48;
      nb = nb / 10;
    }
  if (check_neg == 1)
    dest[i++] = '-';
  dest[i] = 0;
  my_revstr(dest);
  return (dest);
}
