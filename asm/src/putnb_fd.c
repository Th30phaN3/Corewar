#include	"asm.h"

int	false_label(t_label *label, char *arg, int line)
{
  if (label == NULL)
    {
      my_error(2, "label ", 1);
      my_error(2, arg, 1);
      my_error(2, " undefine line ", 1);
      my_putnb_fd(line, 2);
      my_error(2, "\n", 1);
      return (-1);
    }
  return (0);
}

void	my_putchar_fd(char c, int fd)
{
  write(fd, &c, 1);
}

void     my_putnb_fd(int nb, int fd)
{
  if ((nb < 0) && (nb != -2147483648))
    {
      write(fd, "-", 1);
      nb *= -1;
    }
  if (nb > 9)
    my_putnb_fd(nb / 10, fd);
  my_putchar_fd((nb % 10) + 48, fd);
}
