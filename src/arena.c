#include "vm.h"

void		init_item(t_pc *pc, t_core *core, int i)
{
  t_fight	*cur;
  int		j;

  j = 0;
  cur = core->champion;
  while (j < i)
    {
      cur = cur->next;
      j++;
    }
  pc->header = cur->header;
  pc->debut = 0;
  pc->live = 0;
  pc->pos = j;
  pc->cur_cycle = 0;
  pc->is_alive = 1;
  pc->carry = 0;
  j = 0;
  while (j < MEM_SIZE)
    {
      pc->prog[j] = cur->prog[j];
      j++;
    }
}

t_list_pc	*init_list(t_core *core)
{
  t_list_pc	*list;
  t_pc		*item;
  int		i;

  if ((list = malloc(sizeof(t_list_pc))) == NULL)
    return (NULL);
  list->first = NULL;
  list->last = NULL;
  list->len = 0;
  i = 0;
  while (i < core->nb_fight)
    {
      if ((item = malloc(sizeof(t_pc))) == NULL)
	return (NULL);
      init_item(item, core, i);
      item->next = list->first;
      list->first = item;
      if (list->last == NULL)
	list->last = item;
      item->prev = list->last;
      list->len++;
      i++;
    }
  return (list);
}

t_list_pc	*init_arena(t_core *core)
{
  int	i;
  t_list_pc	*list;

  list = init_list(core);
  i = 0;
  while (i < MEM_SIZE)
    core->arena[i++] = 0;
  i = 0;
  while (i < list->first->header->prog_size)
    {
      core->arena[i] = list->first->prog[i];
      i++;
    }
  return (list);
}
