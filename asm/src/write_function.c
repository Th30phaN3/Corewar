#include	"asm.h"

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

int     is_label_omg(char *s)
{
  if (s[my_strlen(s) - 1] == ':')
    return (1);
  return (0);
}

int     is_inst(char *s)
{
  int   i;

  i = 0;
  while (op_tab[i].mnemonique)
    {
      if (my_strcmp(s, op_tab[i].mnemonique) == 0)
        return (1);
      i++;
    }
  return (0);
}

void		write_opocode(t_inst *inst, t_asm *info)
{
  int		i;

  i = 0;
  while (op_tab[i].mnemonique != NULL)
    {
      if (my_strcmp(inst->name, op_tab[i].mnemonique) == 0)
	{
	  add_char_to_buff(op_tab[i].code, info);
	}
      i++;
    }
}

void		*write_function(t_inst *inst, t_asm *info, t_label *label)
{
  info->save_oct = info->nb_oct;
  write_opocode(inst, info);
  if (my_strcmp(inst->name, "live") != 0
      && my_strcmp(inst->name, "zjmp") != 0
      && my_strcmp(inst->name, "fork") != 0
      && my_strcmp(inst->name, "lfork") != 0)
    write_octet_codage(info, inst->args);
  if (write_params(inst, info, label) == NULL)
    return (NULL);
  return (info);
}
