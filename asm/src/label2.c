#include	"asm.h"

int             verif_lbl(char *s, int is_valid)
{
  int           i;

  i = 0;
  while (s[i])
    i++;
  if (s[i - 1] == ':')
    return (2);
  return (is_valid);
}

int             check_label_chars(char c)
{
  int           j;

  j = -1;
  while (++j < 37)
    {
      if (LABEL_CHARS[j] == c)
        return (1);
    }
  return (0);
}

void            *add_label_to_list(t_label **label, char *s, int position,
                                   int line)
{
  t_label       *new;
  int           i;

  if ((new = malloc(sizeof(t_label))) == NULL)
    {
      my_error(2, ERROR_MALLOC, 1);
      return (NULL);
    }
  s[my_strlen(s) - 1] = 0;
  i = -1;
  while (s[++i])
    if (check_label_chars(s[i]) == 0)
      {
	my_error(2, "Syntax error line ", 1);
        my_putnb_fd(line, 2);
	my_error(2, "\n", 1);
        return (NULL);
      }
  new->name = my_strdup(s);
  new->position = position;
  new->next = *label;
  *label = new;
  return (s);
}
