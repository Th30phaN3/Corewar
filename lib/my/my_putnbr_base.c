int		milen(char *str)
{
  int		i;

  i = 0;
  while (str[i] != 0)
    i++;
  return (i);
}

int             my_putnbr_base(int nb, char *base)
{
  if (nb < 0)
    {
      my_putchar('-');
      nb = -nb;
    }
  if (nb / milen(base))
    my_putnbr_base(nb / milen(base), base);
  my_putchar(base[nb % milen(base)]);
}
