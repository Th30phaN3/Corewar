int		check_limit(char *str, int size_nb, int isneg, int res)
{
  if (size_nb > 10)
    res = 0;
  else
    if (size_nb == 10)
      {
	if (str[0] > '2')
	  return (0);
	if (str[0] == '2')
	  {
	    if (isneg == 1 && res > 0)
	      return (0);
	    if (isneg == 0 && res < 0)
	      return (0);
	  }
      }
  return (res);
}

int             my_strlen_nb(char *str)
{
  int           i;

  i = 0;
  while (str[i] != 0 && (str[i] <= '9' && str[i] >= '0'))
    i++;
  return (i);
}

int		check_error(char *str)
{
  int		i;

  i = 0;
  while (str[i] != 0 && (str[i] > '9' || str[i] < '0'))
    {
      if (str[i] != '+' && str[i] != '-' && (str[i] > '9' || str[i] < '0'))
	return (1);
      i++;
    }
  if (str[i] == 0)
    return (1);
  return (0);
}

int             power10(int nb)
{
  int           i;
  int           res;

  res = 1;
  i = 0;
  while (i < nb)
    {
      res = res * 10;
      i++;
    }
  return (res);
}

int		my_getnbr(char *str)
{
  int		res;
  int		size_nb;
  int		i;
  int		isneg;

  res = 0;
  isneg = 0;
  if (check_error(str) == 1)
    return (0);
  while (*str != 0 && (*str <= '9' && *str >= '0') == 0)
    {
      if (*str == '-')
	isneg++;
      str++;
    }
  isneg %= 2;
  size_nb = my_strlen_nb(str);
  i = 0;
  while (str[i] != 0 && i < size_nb)
    res += (str[i] - 48) * power10(size_nb - i++ - 1);
  if (isneg == 1)
    res *= -1;
  res = check_limit(str, size_nb, isneg, res);
  return (res);
}
