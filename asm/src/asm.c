#include	"asm.h"

void		*add_char_to_buff(char c, t_asm *info)
{
  char		*new_buf;
  int		i;

  info->nb_oct++;
  if ((new_buf = malloc(info->nb_oct * sizeof(char))) == NULL)
    return (error_malloc(ERROR_MALLOC));
  i = 0;
  while (i < info->nb_oct - 1)
    {
      new_buf[i] = info->buffer[i];
      i++;
    }
  new_buf[i] = c;
  free(info->buffer);
  info->buffer = new_buf;
  return (info);
}

char 		*get_line(char *str)
{
  int		i;
  char		*line;

  while ((*str == ' ' || *str == '\t') && *str != 0)
    str++;
  if ((line = malloc((my_strlen(str) + 1) * sizeof(*line))) == NULL)
    return (error_malloc(ERROR_MALLOC));
  i = 0;
  while (str[i] != 0 && str[i] != COMMENT_CHAR)
    {
      line[i] = str[i];
      i++;
    }
  line[i] = 0;
  return (line);
}

t_asm		*init_info(t_asm *info)
{
  info->nb_oct = 0;
  if ((info->buffer = malloc(sizeof(char))) == NULL)
    return (error_malloc(ERROR_MALLOC));
  info->buffer[0] = 0;
  return (info);
}

int		lets_write(t_inst *inst, t_asm *info, t_label *label, int i)
{
  if (inst->is_valid == 2)
    return (0);
  if (inst->is_valid == 1)
    {
      if (write_function(inst, info, label) == NULL)
	return (-1);
    }
  else
    {
      my_error(2, "Syntax error line ", 1);
      my_putnb_fd(i + 1, 2);
      return (my_error(2, "\n", -1));
    }
  return (0);
}

void		*assembleur(char **file, t_asm *info, t_label *label, int i)
{
  char		*clean_line;
  t_inst	*inst;

  info = init_info(info);
  while (file[i] != NULL)
    {
      info->line = i + 1;
      if (my_strlen(clean_line = get_line(file[i])) != 0 &&
	  my_strncmp(NAME_CMD_STRING, clean_line,
		     my_strlen(NAME_CMD_STRING)) != 0
	  && my_strncmp(COMMENT_CMD_STRING, clean_line,
			my_strlen(COMMENT_CMD_STRING)) != 0)
	{
	  inst = parse_line(eppur_line(clean_line, -1, 0, 1), -1);
	  inst->is_valid = verif_lbl(clean_line, inst->is_valid);
	  if (lets_write(inst, info, label, i) == -1)
	    return (NULL);
	}
      free(clean_line);
      i++;
    }
  return (file);
}
