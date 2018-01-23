#include	<stdio.h>
#include	"my.h"

int		aff_c(va_list vl, char c)
{
  my_putchar(va_arg(vl, int));
  return (1);
}

int		aff_s(va_list vl, char c)
{
  char		*s;

  s = va_arg(vl, char*);
  if (s == NULL)
    {
      my_putstr("(null)");
      return (6);
    }
  return (my_putstr(s));
}

int		aff_i(va_list vl, char c)
{
  int		nb_i;
  unsigned int	nb_u;
  int		count;

  count = 0;
  if (c == 'i' || c == 'd')
    {
      nb_i = va_arg(vl, int);
      my_put_nbr(nb_i);
      while (nb_i = nb_i / 10)
	count++;
      count++;
    }
  if (c == 'u')
    {
      nb_u = va_arg(vl, unsigned int);
      my_put_nbr(nb_u);
      while (nb_u = nb_u / 10)
	count++;
      count++;
    }
  return (count);
}

int		aff_hex(va_list vl, char c)
{
  int		count;
  int		nb;

  count = 0;
  nb = va_arg(vl, int);
  if (c == 'X')
    my_putnbr_base(nb, "0123456789ABCDEF");
  if (c == 'x')
    my_putnbr_base(nb, "0123456789abcdef");
  while (nb = nb / 16)
    count++;
  count++;
  return (count);
}

int		aff_oct(va_list vl, char c)
{
  int		count;
  int		nb;

  count = 0;
  nb = va_arg(vl, int);
  my_putnbr_base(nb, "012345678");
  while (nb / 8)
    {
      count++;
      nb /= 8;
    }
  count++;
  return (0);
}
