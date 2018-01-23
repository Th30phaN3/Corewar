int             mystrlen(char *str)
{
  int           i;

  i = 0;
  while (str[i] != 0)
    i++;
  return (i);
}

char		*my_revstr(char *str)
{
  int		i;
  char		save;
  int		size;

  i = 0;
  size = mystrlen(str);
  while (i < size / 2)
    {
      save = str[i];
      str[i] = str[size - i - 1];
      str[size - i - 1] = save;
      i++;
    }
  return (str);
}
