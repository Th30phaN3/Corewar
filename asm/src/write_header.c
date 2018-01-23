#include	"asm.h"

int		add_name(header_t *head, char *s)
{
  int		i;
  int		j;
  int		count;

  i = 0;
  while (i < PROG_NAME_LENGTH + 1)
    head->prog_name[i++] = 0;
  i = 0;
  count = 0;
  while (s[i])
    if (s[i++] == '\"')
      count++;
  if (count != 2)
    return (1);
  i = 0;
  j = 0;
  while (s[i++] != '\"' && s[i]);
  while (s[i] != '\"' && s[i])
    head->prog_name[j++] = s[i++];
  return (1);
}

int             add_comment(header_t *head, char *s)
{
  int           i;
  int           j;
  int           count;

  i = 0;
  while (i < COMMENT_LENGTH + 1)
    head->comment[i++] = 0;
  i = 0;
  count = 0;
  while (s[i])
    if (s[i++] == '\"')
      count++;
  if (count != 2)
    return (1);
  i = 0;
  j = 0;
  while (s[i++] != '\"' && s[i]);
  while (s[i] != '\"' && s[i])
    {
      head->comment[j] = s[i];
      j++;
      i++;
    }
  return (1);
}

int		put_error_if_needed(int check_name, int check_comment)
{
  if (check_name == 0)
    return (my_error(2, "Error: No name specified.\n", 1));
  if (check_comment == 0)
    my_error(2, "Warning: No comment specified.\n", 1);
  return (0);
}

int		get_name_comment(header_t *head, char **file)
{
  int		i;
  char		*s;
  int		check_name;
  int		check_comment;

  check_name = 0;
  check_comment = 0;
  i = 0;
  while (i < PROG_NAME_LENGTH + 1)
    head->prog_name[i++] = 0;
  i = 0;
  while (i < COMMENT_LENGTH + 1)
    head->comment[i++] = 0;
  i = -1;
  while (file[++i] != NULL)
    {
      s = my_epurstr(file[i], ' ');
      if (my_strncmp(s, NAME_CMD_STRING, my_strlen(NAME_CMD_STRING)) == 0)
	check_name = add_name(head, file[i]);
      if (my_strncmp(s, COMMENT_CMD_STRING,
		     my_strlen(COMMENT_CMD_STRING)) == 0)
	check_comment = add_comment(head, file[i]);
      free(s);
    }
  return (put_error_if_needed(check_name, check_comment));
}

void		*get_header(char **file, t_asm info, int fd)
{
  header_t	head;
  t_endian	nb;
  char		save;

  nb.integer = COREWAR_EXEC_MAGIC;
  save = nb.chara[0];
  nb.chara[0] = nb.chara[3];
  nb.chara[3] = save;
  save = nb.chara[1];
  nb.chara[1] = nb.chara[2];
  nb.chara[2] = save;
  head.magic = nb.integer;
  if (get_name_comment(&head, file) == 1)
    return (NULL);
  nb.integer = info.nb_oct;
  save = nb.chara[0];
  nb.chara[0] = nb.chara[3];
  nb.chara[3] = save;
  save = nb.chara[1];
  nb.chara[1] = nb.chara[2];
  nb.chara[2] = save;
  head.prog_size = nb.integer;
  write(fd, &head, sizeof(head));
  return (file);
}
