#include	"my.h"

int		aff_soct(va_list vl, char c)
{
  int		i;
  char		*s;
  int		count;

  i = 0;
  count = 0;
  s = va_arg(vl, char*);
  while (s[i])
    {
      if (my_isprintable(s[i]) == 0)
	{
	  my_putstr("\\00");
	  my_putnbr_base(s[i], "012345678");
	  while (s[i] = s[i] / 8)
	    count++;
	  count++;
	}
      else
	{
	  my_putchar(s[i]);
	  count++;
	}
      i++;
    }
  return (count);
}

int		aff_bin(va_list vl, char c)
{
  int		nb;
  int		count;

  count = 0;
  nb = va_arg(vl, int);
  my_putnbr_base(nb, "01");
  while (nb = nb / 2)
    count++;
  return (count);
}

int		aff_coct(va_list vl, char c)
{
  char		d;
  int		count;

  d = va_arg(vl, int);
  count = 0;
  if (my_isprintable(d) == 0)
    {
      my_putstr("\\00");
      my_putnbr_base(d, "012345678");
      while (d = d / 8)
	count++;
    }
  else
    {
      my_putchar(d);
      count++;
    }
  return (count);
}

int		aff_point(va_list vl, char c)
{
  int		nb;
  int		count;

  count = 0;
  my_putstr("0x");
  count += 2;
  nb = va_arg(vl, int);
  if (nb == 0)
    return (my_putstr("(nil)"));
  my_putnbr_base(nb, "0123456789abcdef");
  while (nb = nb / 16)
    count++;
  return (count);
}
