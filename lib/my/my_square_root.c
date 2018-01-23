int		my_square_root(int nb)
{
  int		i;

  i = 0;
  while (i < nb / 2)
    {
      if ((i * i) == nb)
	return (i);
      i++;
    }
  return (0);
}
