#include	"asm.h"

int		check_name_file(char *file_name)
{
  my_revstr(file_name);
  if (my_strncmp(file_name, "s.", 2) != 0)
    return (my_error(2, "Error : Only .s are expected\n", 1));
  else
    my_revstr(file_name);
  return (0);
}

char		**get_file(char *file_name)
{
  int		fd;
  char		*s;
  char		**tab;

  if ((tab = malloc(sizeof(char*))) == NULL)
    {
      my_error(2, ERROR_MALLOC, 1);
      return (NULL);
    }
  tab[0] = NULL;
  if (check_name_file(file_name) == 1)
    return (NULL);
  if ((fd = open(file_name, O_RDONLY)) == -1)
    {
      my_error(2, "File ", 1);
      my_error(2, file_name, 1);
      my_error(2, " not accessible\n", 1);
      return (NULL);
    }
  while ((s = get_next_line(fd)) != NULL)
    tab = add_to_tab(s, tab);
  close(fd);
  return (tab);
}

int		create_file_cor(char *file_name)
{
  int		fd;
  char		*name_file_cor;

  if ((name_file_cor = malloc(((my_strlen(file_name) + 1) + 2)
			      * sizeof(*name_file_cor))) == NULL)
    return (my_error(2, ERROR_MALLOC, -1));
  name_file_cor[0] = 0;
  name_file_cor = my_strncat(name_file_cor,
			     file_name, my_strlen(file_name) - 2);
  name_file_cor = my_strcat(name_file_cor, ".cor");
  if ((fd = open(name_file_cor, O_CREAT | O_TRUNC | O_RDWR, 00644)) == -1)
    {
      my_error(2, "File ", 1);
      my_error(2, file_name, 1);
      return (my_error(2, " not accessible\n", -1));
    }
  return (fd);
}

void            write_in_cor(t_asm info, int fd)
{
  int           i;

  i = 0;
  while (i < info.nb_oct)
    {
      my_putchar_to_fd(info.buffer[i], fd);
      i++;
    }
}

int		main(int ac, char **av)
{
  char		**file;
  int		fd_file_cor;
  t_asm		info;
  t_label	*label;

  if (ac == 2)
    {
      label = NULL;
      if ((file = get_file(av[1])) == NULL)
	return (1);
      if ((fd_file_cor = create_file_cor(av[1])) == -1)
      	return (1);
      label = get_label(label, file);
      if (assembleur(file, &info, label, 0) == NULL)
	return (1);
      if (get_header(file, info, fd_file_cor) == NULL)
	return (1);
      write_in_cor(info, fd_file_cor);
      free_tab(file);
    }
  else
    my_putstr("Usage: ./asm [FILE]\n");
  return (0);
}
