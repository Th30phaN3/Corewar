#ifndef		WRITE_H
# define	WRITE_H

# define	ERROR_MALLOC "Error: Can't perform malloc.\n"
# define	RD_SIZE 512

typedef union	u_endian
{
  char		chara[4];
  int		integer;
}		t_endian;

#endif
