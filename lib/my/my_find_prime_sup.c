int		my_find_prime_sup(int nb)
{
  int		i;

  i = nb;
  while (my_is_prime(i) != 1)
    i++;
  return (i);
}
