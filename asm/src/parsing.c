#include	"asm.h"

char	**malloc_tab(char *s, char sep)
{
  int	i;
  int	count;
  char	**tab;

  count = 0;
  i = -1;
  while (s[++i])
    {
      if (s[i] == sep)
	count++;
    }
  count += 1;
  i = -1;
  if ((tab = malloc(sizeof(char *) * (count + 1))) == NULL)
    return (NULL);
  while (++i < count)
    {
      if ((tab[i] = malloc(sizeof(char) * (my_strlen(s) + 1))) == NULL)
	return (NULL);
    }
  tab[i] = NULL;
  return (tab);
}

char	*eppur_line(char *s, int i, int j, int last)
{
  char	*new;

  if ((new = malloc(sizeof(char) * my_strlen(s) + 1)) == NULL)
    return (NULL);
  while (s[++i])
    {
      if (s[i] == ' ' || s[i] == '\t')
	{
	  if (last == 0)
	    {
	      if (s[i + 1] != ',')
		new[j++] = ' ';
	      last = 1;
	    }
	}
      else
	{
	  last = 0;
	  if (s[i] == ',')
	    last = 1;
	  new[j++] = s[i];
	}
    }
  new[j] = 0;
  return (new);
}

int	get_required_args(char *s)
{
  int	i;

  i = 0;
  while (op_tab[i].mnemonique)
    {
      if (my_strcmp(s, op_tab[i].mnemonique) == 0)
	return ((int) op_tab[i].nbr_args);
      i++;
    }
  return (-1);
}

void	verify_inst(t_inst *inst, char **tab, int i)
{
  int	j;
  int	count;

  if (tab[i + 1] == NULL)
    return;
  j = 0;
  count = 0;
  while (tab[i + 1][j])
    {
      if (tab[i + 1][j] == SEPARATOR_CHAR)
	{
	  count++;
	}
      j++;
    }
  count++;
  if (count != inst->nb_args)
    return;
  inst->is_valid = 1;
}

t_inst		*parse_line(char *s, int i)
{
  char		**tab;
  t_inst	*inst;

  tab = my_str_to_wordtab(s, ' ');
  if ((inst = malloc(sizeof(t_inst))) == NULL)
    return (error_malloc(ERROR_MALLOC));
  inst->is_valid = 0;
  while (tab[++i])
    {
      if (is_label_omg(tab[i]) == 0)
	{
	  if (is_inst(tab[i]) == 1)
	    {
	      inst->name = my_strdup(tab[i]);
	      inst->nb_args = get_required_args(inst->name);
	      verify_inst(inst, tab, i);
	      if (inst->is_valid == 1)
		{
		  inst->args = my_str_to_wordtab(tab[i + 1], SEPARATOR_CHAR);
		  verify_args(inst);
		}
	    }
	}
    }
  return (inst);
}
