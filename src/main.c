#include	"vm.h"

void		my_corewar(t_core *core)
{
  t_list_pc	*pcs;
  int		i;

  pcs = init_arena(core);
  i = 0;
  while (i < MEM_SIZE)
    {
      my_printf("%d", core->arena[i]);
      if (i % 80 == 0)
	my_putchar('\n');
      i++;
    }
  (void)pcs;
}

int		main(int ac, char **av)
{
  int		dump;
  t_core	*core;

  dump = -1;
  if (ac <= 1 || ac > 23)
    {
      my_printf("Usage: %s [-dump nbr_cycle] [[-n prog_number] " \
		"[-a load_address] prog_name] ...\n", av[0]);
      return (-1);
    }
  if (check_opt(ac, av, 0, &dump) == -1)
    return (-1);
  if (init_core(&core, av, dump, ac) == -1)
    return (-1);
  my_corewar(core);
  free(core);
  return (0);
}
