#include	"asm.h"

int		add_count_param(int position, t_inst *inst)
{
  int           i;
  int		check;

  i = 0;
  check = 0;
  while (inst->args[i] != NULL)
    {
      if ((inst->args[i][0] != 'r' && inst->args[i][0] != DIRECT_CHAR)
          || (check = check_special_param(inst, i)) == 1)
	position += IND_SIZE;
      if (inst->args[i][0] == DIRECT_CHAR && check == 0)
	position += DIR_SIZE;
      if (inst->args[i][0] == 'r' && check == 0)
	position += 1;
      i++;
    }
  return (position);
}

int		add_oct_codage(t_inst *inst, int position)
{
  if (inst->is_valid == 1)
    {
      if (my_strcmp(inst->name, "live") != 0
	  && my_strcmp(inst->name, "zjmp") != 0
	  && my_strcmp(inst->name, "fork") != 0
	  && my_strcmp(inst->name, "lfork") != 0)
	position += 2;
      else
	position += 1;
      position = add_count_param(position, inst);
    }
  return (position);
}

int		check_charactere(char *s)
{
  int		i;

  i = 0;
  while (s[i])
    {
      if (s[i] != COMMENT_CHAR && s[i] != LABEL_CHAR && s[i] != DIRECT_CHAR
	  && s[i] != SEPARATOR_CHAR && s[i] != '-'
	  && (s[i] < 'a' || s[i] > 'z') && (s[i] < 'A' || s[i] > 'Z')
	  && s[i] != '_' && s[i] != ' ' && s[i] != '\t'
	  && (s[i] < '0' || s[i] > '9'))
	return (1);
      i++;
    }
  return (0);
}

int		count_position(char *s, int position, int line)
{
  char		*clean_line;
  t_inst        *inst;

  if (my_strlen(clean_line = get_line(s)) != 0 &&
      my_strncmp(NAME_CMD_STRING, clean_line,
		 my_strlen(NAME_CMD_STRING)) != 0
      && my_strncmp(COMMENT_CMD_STRING, clean_line,
		    my_strlen(COMMENT_CMD_STRING)) != 0)
    {
      if (check_charactere(clean_line) == 1)
	{
	  my_error(2, "Syntax error line ", 1);
	  my_putnb_fd(line, 2);
	  return (my_error(2, "\n", -1));
	}
      inst = parse_line(eppur_line(clean_line, -1, 0, 1), -1);
      position = add_oct_codage(inst, position);
    }
  free(clean_line);
  return (position);
}

t_label		*get_label(t_label *label, char **file)
{
  int		i;
  int		position;
  char		**tab;

  i = 0;
  position = 0;
  while (file[i] != NULL)
    {
      file[i] = eppur_line(file[i], -1, 0, 1);
      tab = my_str_to_wordtab(file[i], ' ');
      if (tab[0] != NULL)
	{
	  my_revstr(tab[0]);
	  if (tab[0][0] == ':')
	    {
	      my_revstr(tab[0]);
	      add_label_to_list(&label, tab[0], position, i);
	    }
	}
      free_tab(tab);
      if ((position = count_position(file[i], position, i)) == -1)
	exit(EXIT_FAILURE);
      i++;
    }
  return (label);
}
