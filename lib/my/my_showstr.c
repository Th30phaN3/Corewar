int		my_showstr(char *str)
{
  int		i;

  i = 0;
  while (str[i] != 0)
    {
      if (str[i] >= 32 && str[i] <= 126)
	write(1, &str[i], 1);
      if (str[i] <= 15)
	{
	  write(1, "0", 1);
	  my_putnbr_base(str[i], "0123456789abcdef");
	}
      if ((str[i] >= 16 && str[i] <= 31) || str[i] == 127)
	my_putnbr_base(str[i], "0123456789abcdef");
      i++;
    }
  return (0);
}
