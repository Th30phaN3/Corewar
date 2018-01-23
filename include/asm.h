#ifndef		ASM_H
# define	ASM_H

#include	<stdlib.h>
#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	<unistd.h>
#include	<string.h>

#include	"op.h"
#include	"write.h"
#include	"my.h"

typedef struct		s_inst
{
  int			is_valid;
  char			*name;
  char			**args;
  int			nb_args;
}			t_inst;

typedef struct		s_label
{
  char			*name;
  int			position;
  struct s_label	*next;
}			t_label;

typedef struct		s_asm
{
  char			*buffer;
  int			nb_oct;
  int			save_oct;
  int			line;
}			t_asm;

void	*assembleur(char**, t_asm*, t_label*, int);
t_inst	*parse_line(char*, int);
void	*add_char_to_buff(char, t_asm*);
void	*write_function(t_inst*, t_asm*, t_label*);
void	write_octet_codage(t_asm*, char**);
void	verify_args(t_inst*);
void	*write_params(t_inst*, t_asm*, t_label*);
t_label	*get_label(t_label*, char**);
char	*eppur_line(char*, int, int, int);
char	*get_line(char*);
int	check_special_param(t_inst*, int);
int	check_label_chars(char);
void	*add_label_to_list(t_label**, char*, int, int);
void	*case_registre_param(char*, t_asm*);
void	*case_direct_param(char*, t_asm*, t_label*);
int	check_arg(char*);
void	*case_label(char*, t_asm*, int, t_label*);
void	*get_header(char**, t_asm, int);
int	is_label_omg(char*);
int	is_inst(char*);
int	verif_lbl(char*, int);
int	false_label(t_label*, char*, int);
void	my_putnb_fd(int, int);
int	my_error(int, char*, int);

#endif
