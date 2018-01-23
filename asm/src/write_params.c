#include	"asm.h"

int		check_arg(char *s)
{
  int		i;

  i = 0;
  if (s[i] == '-')
    i++;
  while (s[i])
    {
      if (s[i] > '9' || s[i] < '0')
	return (1);
      i++;
    }
  return (0);
}

void		*case_label(char *arg, t_asm *info, int nb_octet,
			    t_label *label)
{
  int		i;
  t_endian	nb;
  int		pos;

  pos = -1;
  arg++;
  while (label != NULL && pos == -1)
    {
      if (my_strcmp(arg, label->name) == 0)
	pos = label->position;
      if (pos == -1)
	label = label->next;
    }
  if (false_label(label, arg, info->line) == -1)
    return (NULL);
  i = 0;
  nb.integer = pos - info->save_oct;
  while (++i <= nb_octet)
    add_char_to_buff(nb.chara[nb_octet - i], info);
  return (arg);
}

void		*case_indirect_param(char *arg, t_asm *info, t_label *label, int i)
{
  t_endian	nb;

  if (arg[0] == LABEL_CHAR)
    return (case_label(arg, info, IND_SIZE, label));
  if (check_arg(arg) == 1)
    {
      my_error(2, "Syntax error line ", 1);
      my_putnb_fd(info->line, 2);
      my_error(2, "\n", 1);
      return (NULL);
    }
  nb.integer = my_getnbr(arg);
  if (nb.integer > IDX_MOD)
    {
      my_error(2, "Warning Indirection to far line ", 1);
      my_putnb_fd(info->line, 2);
      my_error(2, "\n", 1);
      nb.integer %= IDX_MOD;
    }
  while (++i <= IND_SIZE)
    add_char_to_buff(nb.chara[IND_SIZE - i], info);
  return (arg);

}

int		check_special_param(t_inst *inst, int i)
{
  if (my_strcmp(inst->name, "ldi") == 0
      && (i == 0 || (i == 1 && inst->args[i][0] == DIRECT_CHAR)))
    return (1);
  if (((my_strcmp(inst->name, "sti") == 0 && inst->args[i][0] != 'r'))
      && (i == 1 || i == 2))
    return (1);
  if ((my_strcmp(inst->name, "zjmp") == 0
       || my_strcmp(inst->name, "fork") == 0) && i == 0)
     return (1);
  return (0);
}

void		*write_params(t_inst *inst, t_asm *info, t_label *label)
{
  int		i;
  int		check;

  i = -1;
  check = 0;
  while (inst->args[++i] != NULL)
    {
      if ((inst->args[i][0] != 'r' && inst->args[i][0] != DIRECT_CHAR)
	  || (check = check_special_param(inst, i)) == 1)
	if (case_indirect_param(inst->args[i] + check, info, label, 0) == NULL)
	  return (NULL);
      if (inst->args[i][0] == DIRECT_CHAR && check == 0)
	if (case_direct_param(inst->args[i] + 1, info, label) == NULL)
	  return (NULL);
      if (inst->args[i][0] == 'r' && check == 0)
	if (case_registre_param(inst->args[i] + 1, info) == NULL)
	  return (NULL);
    }
  return (info);
}
