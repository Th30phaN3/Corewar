int		my_putstr(char *s)
{
  int		i;

  i = 0;
  while (s[i])
    {
      my_putchar(s[i]);
      i++;
    }
  return (i);
}
