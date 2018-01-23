#include <stdio.h>

int		check_error(char *str, char *base)
{
  int		i;
  int		j;
  int		check;

  i = 0;
  while (str[i] != 0)
    {
      j = 0;
      check = 0;
      while (base[j] != 0)
	{
	  if (str[i] == base[j] || str[i] == '-' || str[i] == '+')
	    check = 1;
	  j++;
	}
      if (check == 0)
	return (1);
      i++;
    }
  return (0);
}

int		check_base(char *base)
{
  int		i;
  int		j;

  i = 0;
  while (base[i] != 0)
    {
      j = i;
      while (base[j] != 0)
	{
	  if ((base[i] == base[j] && i != j) || base[i] == '-'	\
	      || base[i] == '+')
	    return (1);
	  j++;
	}
      i++;
    }
  return (0);
}

int		place_base(char c, char *base)
{
  int		i;

  i = 0;
  while (base[i] != 0)
    {
      if (base[i] == c)
	return (i);
      i++;
    }
  return (-1);
}

int		my_getnbr_base(char *str, char *base)
{
  int		isneg;
  int		res;
  int		i;

  res = 0;
  isneg = 0;
  if (check_error(str, base) == 1 || check_base(base) == 1)
    return (0);
  while (*str != 0 && (*str == '-' || *str == '+'))
    {
      if (*str == '-')
        isneg++;
      str++;
    }
  isneg %= 2;
  i = 0;
  while (str[i] != 0)
    {
      res += place_base(str[i], base) *				\
	my_power_rec(my_strlen(base), my_strlen(str) - i++ - 1);
    }
  if (isneg == 1)
    res *= -1;
  return (res);
}
