#include	"vm.h"

int		collect_data(t_fight **champion, int fd)
{
  int		rd;
  int		nb;
  char		buff[RD_SIZE];
  int		i;

  nb = 0;
  while ((rd = read(fd, buff, RD_SIZE)) > 0)
    {
      buff[rd + 1] = 0;
      if (rd + nb > MAX_SIZE)
	return (my_error(2, "Error: program size is too big.\n", -1));
      i = 0;
      while (i < rd)
	(*champion)->prog[nb++] = buff[i++];
    }
  if (nb != (*champion)->header->prog_size)
    return (my_error(2, "Error: wrong program size.\n", -1));
  return (0);
}

int		data_fighter(t_fight **champion, int fd)
{
  if (((*champion)->header = malloc(sizeof(header_t))) == NULL)
    return (my_error(2, ERROR_MALLOC, -1));
  if ((collect_data_header((*champion)->header, fd)) == -1)
    return (-1);
  if ((collect_data(champion, fd)) == -1)
    return (-1);
  return (0);
}

int		add_fighter_to_list(t_core *core, \
				    t_fight *new)
{
  t_fight	*tmp;

  tmp = core->champion;
  core->champion = new;
  new->next = tmp;
  new->prev = tmp->prev;
  tmp->prev = new;
  return (0);
}

int             fill_fighter(t_core *core, char **av, int *i, char **ok)
{
  t_fight       *tmp;
  int           fd;

  if ((tmp = malloc(sizeof(*tmp))) == NULL)
    return (-1);
  if ((tmp->number = load_nb(av, i, (*ok))) == -1)
    return (-1);
  (*ok)[tmp->number] = '1';
  tmp->address = load_address(av, i);
  if ((fd = open(av[*i], O_RDONLY)) == -1)
    {
      my_error(2, "Error: can't open ", 1);
      my_error(2, av[*i], 1);
      return (my_error(2, ".\n", -1));
    }
  if (data_fighter(&tmp, fd) == -1)
    return (-1);
  add_fighter_to_list(core, tmp);
  close(fd);
  return (0);
}

int             init_fighters(t_core *core, char **av, int i, int ac)
{
  int           nb;
  char          *ok;
  int           j;

  j = 0;
  if ((ok = malloc(sizeof(char) * 5)) == NULL)
    return (-1);
  while (j < 4)
    ok[j++] = '0';
  nb = 0;
  while (i < ac)
    {
      if (my_strcmp(av[i], "-dump") != 0 && \
          (av[i][0] < 0 || av[i][0] > 9))
        {
          if (fill_fighter(core, av, &i, &ok) == -1)
            return (-1);
          else
            nb++;
        }
      i++;
    }
  free(ok);
  return (nb);
}
