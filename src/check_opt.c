#include	"vm.h"

int		check_prog_number(int ac, char **av, int *i, char **nbr)
{
  int		nb;

  nb = 0;
  if (my_strcmp(av[*i], "-n") == 0)
    {
      if (*i + 2 >= ac)
	return (my_error(2, "Error: file name is not a corewar " \
			 "executable.\n", -1));
      nb = my_getnbr(av[*i + 1]);
      if (nb <= 0 || nb > 4)
	return (my_error(2, "Error: prog_number must be between " \
			 "1 and 4.\n", -1));
      if ((*nbr)[nb - 1] == '1')
	{
	  my_error(2, "Error: prog_number ", 1);
	  my_putnb_fd(nb, 2);
	  return (my_error(2, " is already used.\n", -1));
	}
      else
	(*nbr)[nb - 1] = '1';
      *i = *i + 2;
    }
  return (0);
}

int		check_load_address(int ac, char **av, int *i)
{
  int		addr;

  addr = -1;
  if (my_strcmp("-a", av[*i]) == 0)
    {
      if (*i + 2 >= ac)
	return (my_error(2, "Error: file name is not a corewar " \
			 "executable.\n", -1));
      addr = my_getnbr(av[*i + 1]);
      if (addr < 0 || (addr > (MEM_SIZE - 1)))
	return (my_error(2, "Error: load_address must be" \
			 "between 0 and MEM_SIZE.\n", -1));
      (*i) += 2;
    }
  return (0);
}

int		check_prog_name(char *name, int *champ)
{
  int		len;

  len = my_strlen(name);
  if (len < 4 || my_strcmp(".cor", &name[len - 4]) != 0)
    {
      my_error(2, "Error: ", 1);
      my_error(2, name, 1);
      return (my_error(2, " is not a corewar executable.\n", -1));
    }
  (*champ)++;
  return (0);
}

int		check_dump(int ac, char **av, int *i, int *dump)
{
  int		nb;

  nb = 0;
  if (my_strcmp("-dump", av[*i]) == 0)
    {
      if (*i + 2 >= ac)
	return (my_error(2, "Error: file name is not a corewar " \
			 "executable.\n", -1));
      nb = my_getnbr(av[*i + 1]);
      if (nb <= 0)
	return (my_error(2, "Error: nbr_cycle must be strictly " \
			 "positive.\n", -1));
      *dump = nb;
      if (*dump > 0)
	(*i) += 2;
    }
  return (0);
}

int		check_opt(int ac, char **av, int i, int *dump)
{
  char		*nbr;
  int		champ;
  int		j;

  champ = 0;
  j = 0;
  if ((nbr = malloc(sizeof(char) * 4)) == NULL)
    return (my_error(2, ERROR_MALLOC, -1));
  while (j < 4)
    nbr[j++] = '0';
  while (++i < ac)
    {
      if (check_dump(ac, av, &i, dump) == -1)
	return (-1);
      if (check_prog_number(ac, av, &i, &nbr) == -1)
	return (-1);
      if (check_load_address(ac, av, &i) == -1)
	return (-1);
      if (check_prog_name(av[i], &champ) == -1)
	return (-1);
    }
  free(nbr);
  if (champ <= 0 || champ > 4)
    return (my_error(2, "Too many/few champions (1 to 4 needed).\n", -1));
  return (0);
}
