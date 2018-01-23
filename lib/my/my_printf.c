#include <stdarg.h>
#include "my.h"

void		init_pf(t_pf pf[12])
{
  pf[0].c = 'c';
  pf[0].f = &aff_c;
  pf[1].c = 's';
  pf[1].f = &aff_s;
  pf[2].c = 'i';
  pf[2].f = &aff_i;
  pf[3].c = 'u';
  pf[3].f = &aff_i;
  pf[4].c = 'd';
  pf[4].f = &aff_i;
  pf[5].c = 'x';
  pf[5].f = &aff_hex;
  pf[6].c = 'X';
  pf[6].f = &aff_hex;
  pf[7].c = 'o';
  pf[7].f = &aff_oct;
  pf[8].c = 'S';
  pf[8].f = &aff_soct;
  pf[9].c = 'b';
  pf[9].f = &aff_bin;
  pf[10].c = 'C';
  pf[10].f = &aff_coct;
  pf[11].c = 'p';
  pf[11].f = &aff_point;
}

int		aff_n(t_print *pr)
{
  int		count;
  int		nb;

  count = 0;
  nb = pr->nb_write;
  my_put_nbr(nb);
  while (nb = nb / 10)
    count ++;
  count++;
  return (count);
}

int		search(t_print *pr, char c, int *j, const char *format)
{
  int		i;

  i = -1;
  while (++i < 12)
    if (c == pr->pf[i].c)
      {
	pr->nb_write += pr->pf[i].f(pr->vl, c);
	return (1);
      }
  if (c == 'n')
    pr->nb_write += aff_n(pr);
  else
    {
      pr->nb_write += 2;
      if (c != '%')
	my_putchar('%');
      if (format[*j - 1] == ' ')
	{
	  pr->nb_write += 1;
	  my_putchar(' ');
	}
      my_putchar(c);
    }
  return (0);
}

char		find_char(const char *format, int *i, t_print *pr)
{
  *i = *i + 1;
  while (format[*i] == ' ' || format[*i] == '\t')
    *i = *i + 1;
  return (format[*i]);
}

int		my_printf(const char *format, ...)
{
  t_print	pr;
  int		i;

  va_start(pr.vl, format);
  init_pf(pr.pf);
  i = 0;
  pr.nb_write = 0;
  while (format[i])
    {
      if (format[i] == '%')
	search(&pr, find_char(format, &i, &pr), &i, format);
      else
	{
	  my_putchar(format[i]);
	  pr.nb_write++;
	}
      if (format[i])
	i++;
    }
  va_end(pr.vl);
  return (pr.nb_write);
}
