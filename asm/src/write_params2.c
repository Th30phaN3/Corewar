#include	"asm.h"

void            *case_registre_param(char *arg, t_asm *info)
{
  t_endian      nb;

  nb.integer = my_getnbr(arg);
  if (nb.integer < 1 || nb.integer > 16)
    {
      my_error(2, "no such register line ", 1);
      my_putnb_fd(info->line, 2);
      my_error(2, "\n", 1);
      return (NULL);
    }
  add_char_to_buff(nb.chara[0], info);
  return (arg);
}

void            *case_direct_param(char *arg, t_asm *info, t_label *label)
{
  int           i;
  t_endian      nb;

  if (arg[0] == LABEL_CHAR)
    return (case_label(arg, info, DIR_SIZE, label));
  if (check_arg(arg) == 1)
    {
      my_error(2, "Syntax error line ", 1);
      my_putnb_fd(info->line, 2);
      my_error(2, "\n", 1);
      return (NULL);
    }
  nb.integer = my_getnbr(arg);
  i = 1;
  while (i <= DIR_SIZE)
    {
      add_char_to_buff(nb.chara[DIR_SIZE - i], info);
      i++;
    }
  return (arg);
}
