#include	"vm.h"

int             init_core(t_core **core, char **av, int dump, int ac)
{
  int		i;

  i = 0;
  if (((*core) = (t_core*)malloc(sizeof(**core))) == NULL)
    return (my_error(2, ERROR_MALLOC, -1));
  (*core)->dump = dump;
  (*core)->mem_size = MEM_SIZE;
  (*core)->cycle_to_die = CYCLE_TO_DIE;
  while (i <= MEM_SIZE)
    (*core)->arena[i++] = 0;
  if (((*core)->champion = malloc(sizeof(*(*core)->champion))) == NULL)
    return (my_error(2, ERROR_MALLOC, -1));
  (*core)->champion->prev = (*core)->champion;
  (*core)->champion->next = (*core)->champion;
  if ((i = init_fighters((*core), av, 1, ac)) == -1)
    return (-1);
  (*core)->nb_fight = i;
  return (0);
}
