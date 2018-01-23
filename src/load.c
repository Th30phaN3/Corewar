#include	"vm.h"

int             load_nb(char **av, int *i, char *ok)
{
  int           nb;

  nb = 0;
  if (my_strcmp(av[*i], "-n") == 0)
    {
      nb = my_getnbr(av[*i + 1]);
      if (ok[nb - 1] == '1')
        return (my_error(2, "Error: prog_number already used.\n", -1));
      *i = *i + 2;
      return (nb);
    }
  while (ok[nb] == '1')
    ++nb;
  return (nb + 1);
}

int             load_address(char **av, int *i)
{
  int           addr;

  if (my_strcmp("-a", av[*i]) == 0)
    {
      addr = my_getnbr(av[*i + 1]) % MEM_SIZE;
      *i = *i + 2;
      return (addr);
    }
  return (-1);
}
