#include	"asm.h"

int		case_indirect(int nb)
{
  nb = nb << 1;
  nb = nb | 1;
  nb = nb << 1;
  nb = nb | 1;
  return (nb);
}

int		case_direct(int nb)
{
  nb = nb << 1;
  nb = nb | 1;
  nb = nb << 1;
  return (nb);
}

int		case_registre(int nb)
{
  nb = nb << 1;
  nb = nb << 1;
  nb = nb | 1;
  return (nb);
}

void		write_octet_codage(t_asm *info, char **params)
{
  int		i;
  int		nb;

  nb = 0;
  i = 0;
  while (params[i] != NULL)
    {
      if (params[i][0] == 'r')
	nb = case_registre(nb);
      if (params[i][0] == DIRECT_CHAR)
	nb = case_direct(nb);
      if (params[i][0] != 'r' && params[i][0] != DIRECT_CHAR)
	nb = case_indirect(nb);
      i++;
    }
  while (i < 4)
    {
      nb = nb << 2;
      i++;
    }
  add_char_to_buff((char)nb, info);
}
