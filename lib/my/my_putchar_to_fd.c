void	my_putchar_to_fd(char c, int fd)
{
  write(fd, &c, 1);
}
