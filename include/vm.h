#ifndef		_VM_H_
# define	_VM_H_

#include	<stdio.h>

#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	<unistd.h>
#include	<stdlib.h>

#include	"op.h"
#include	"my.h"
#include	"write.h"

# define	MAX_SIZE 2048

typedef struct		s_fight
{
  header_t		*header;
  unsigned char		prog[MEM_SIZE];
  int			number;
  int			address;
  struct s_fight	*next;
  struct s_fight	*prev;
}			t_fight;

typedef struct		s_pc
{
  header_t		*header;
  int			debut;
  int			reg[REG_NUMBER];
  int			live;
  int			pos;
  int			cur_cycle;
  unsigned char		prog[MEM_SIZE];
  unsigned char		is_alive;
  unsigned char		carry;
  struct s_pc		*next;
  struct s_pc		*prev;
}			t_pc;

typedef struct		s_list_pc
{
  t_pc			*first;
  t_pc			*last;
  int			len;
}			t_list_pc;

typedef struct	s_core
{
  int		dump;
  int		mem_size;
  int		nb_fight;
  int		cycle_to_die;
  unsigned char	arena[MEM_SIZE];
  t_fight	*champion;
}		t_core;

int		my_error(int, char*, int);
void		my_putnb_fd(int, int);
int		check_opt(int, char**, int, int*);
int		init_core(t_core**, char**, int, int);
int		data_fighters(t_fight**);
int		add_fighter_to_list(t_core*, t_fight*);
int		fill_fighter(t_core*, char**, int*, char**);
int		init_fighters(t_core*, char**, int, int);
int		load_nb(char**, int*, char*);
int		load_address(char**, int*);
int		collect_data(t_fight**, int);
void		swap_octet(int*);
int		collect_data_header(header_t*, int);

void		init_item(t_pc*, t_core*, int);
t_list_pc	*init_list(t_core*);
t_list_pc	*init_arena(t_core*);

#endif
