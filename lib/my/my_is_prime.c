int		my_is_prime(int nb)
{
  int		i;
  int		j;

  i = 1;
  if (nb == 0 || nb == 1 || nb < 0)
    return (0);
  while (i < nb)
    {
      j = 2;
      while (j < nb)
	{
	  if ((i * j) == nb)
	    return (0);
	  j++;
	}
      i++;
    }
  return (1);
}
