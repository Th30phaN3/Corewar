char	*my_strupcase(char *str)
{
  int	i;

  i = 0;
  while (str[i] != 0)
    {
      if (str[i] <= 'z' && str[i] >= 'a')
	str[i] -= 32;
      i++;
    }
  return (str);
}
