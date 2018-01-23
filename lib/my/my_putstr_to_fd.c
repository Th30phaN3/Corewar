void		my_putstr_to_fd(char *s, int fd)
{
  int		i;

  i = -1;
  while (++i < my_strlen(s))
    my_putchar_to_fd(s[i], fd);
}
