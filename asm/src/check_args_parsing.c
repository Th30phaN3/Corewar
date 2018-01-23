#include	"asm.h"

op_t    get_op_from_name(char *name)
{
  int    i;

  i = 0;
  while (op_tab[i].mnemonique)
    {
      if (my_strcmp(name, op_tab[i].mnemonique) == 0)
        return (op_tab[i]);
      i++;
    }
  return (op_tab[0]);
}

int     is_valid_reg(char *s)
{
  if (my_strlen(s) < 2)
  return (0);
  if (s[0] == 'r' && ((s[1] >= '1' && s[1] <= '9') || s[1] == '-'))
    return (1);
  return (0);
}

int     is_valid_ind(char *s)
{
  if (my_strlen(s) < 1)
    return (0);
  if (s[1] >= '0' && s[1] <= '9')
    return (1);
  return (0);
}

int     is_valid_dir(char *s)
{
  if (my_strlen(s) < 2)
    return (0);
  if (s[0] == DIRECT_CHAR)
    {
      if ((s[1] >= '0' && s[1] <= '9') || s[1] == LABEL_CHAR || s[1] == '-')
        return (1);
    }
  return (0);
}

void    verify_args(t_inst *inst)
{
  int   i;
  op_t  op;
  int   count;

  op = get_op_from_name(inst->name);
  i = 0;
  while (inst->args[i])
    {
      count = 0;
      if ((op.type[i] & T_REG) && is_valid_reg(inst->args[i]) == 1)
        count++;
      if ((op.type[i] & T_IND) && is_valid_ind(inst->args[i]) == 1)
        count++;
      if ((op.type[i] & T_DIR) && is_valid_dir(inst->args[i]) == 1)
        count++;
      if (count == 0)
        {
          inst->is_valid = 0;
          return;
        }
      i++;
    }
}
