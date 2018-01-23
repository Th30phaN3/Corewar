#include	"vm.h"

void            swap_octet(int *nb)
{
  char          save;
  t_endian      nb_2;

  nb_2.integer = *nb;
  save = nb_2.chara[3];
  nb_2.chara[3] = nb_2.chara[0];
  nb_2.chara[0] = save;
  save = nb_2.chara[2];
  nb_2.chara[2] = nb_2.chara[1];
  nb_2.chara[1] = save;
  *nb = nb_2.integer;
}

int             collect_data_header(header_t *header, int fd)
{
  int           rd;

  if ((rd = read(fd, header, sizeof(header_t))) == - 1)
    return (my_error(2, "Error: Can't read file.\n", -1));
  swap_octet(&header->prog_size);
  swap_octet(&header->magic);
  if (header->magic != COREWAR_EXEC_MAGIC)
    return (my_error(2, "Error: wrong magic number.\n", -1));
  if (header->prog_size < 0)
    return (my_error(2, "Error: wrong program size.\n", -1));
  if (header->prog_size > MAX_SIZE)
    return (my_error(2, "Error: program size is too big.\n", -1));
  return (0);
}

int             my_error(int fd, char *str, int value)
{
  int           i;

  i = 0;
  if (str != NULL)
    {
      while (str[i])
        write(fd, &str[i++], 1);
    }
  return (value);
}

void    my_putchar_fd(char c, int fd)
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
