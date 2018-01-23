int		my_power_rec(int nb, int power)
{
  if (power < 0)
    return (0);
  if (power > 0)
    return (nb * my_power_rec(nb, power - 1));
  else
    return (1);
}
