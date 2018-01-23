#ifndef		MY_H
# define	MY_H

#include <stdarg.h>

# define READ_SIZE (2)

typedef struct	s_pf
{
  char		c;
  int		(*f)(va_list vl, char c);
}		t_pf;

typedef struct  s_print
{
  va_list       vl;
  t_pf          pf[12];
  int           nb_write;
}               t_print;

void		afftab(char **tab);
void		free_tab(char **tab);
void		my_putchar(char c);
void		my_putstr_to_fd(char *s, int fd);
void		my_putchar_to_fd(char c, int fd);
void		my_sort_int_tab(int *tab, int size);
void		*error_malloc(char *s);
int		my_putstr(char *s);
int		aff_c(va_list vl, char c);
int		aff_s(va_list vl, char c);
int		aff_i(va_list vl, char c);
int		aff_hex(va_list vl, char c);
int		aff_oct(va_list vl, char c);
int		aff_soct(va_list vl, char c);
int		aff_coct(va_list vl, char c);
int		aff_bin(va_list vl, char c);
int		aff_point(va_list vl, char c);
int		my_printf(const char *format, ...);
int		my_isope(char c);
int		my_isope_custom(char c, char *ops);
int		my_strlen(char *str);
int		my_find_prime_sup(int nb);
int		my_getnbr_base(char *str, char *base);
int		my_getnbr(char *str);
int		my_isneg(int n);
int		my_isprintable(char c);
int		my_is_prime(int nb);
int		my_power_rec(int nb, int power);
int		my_putnbr_base(int nb, char *base);
int		my_put_nbr(int nb);
int		my_square_root(int nb);
int		my_strcmp(char *s1, char *s2);
int		my_str_isalpha(char *str);
int		my_str_islower(char *str);
int		my_str_isnum(char *str);
int		my_str_isprintable(char *str);
int		my_str_isupper(char *str);
int		my_strncmp(char *s1, char *s2, int nb);
int		my_swap(int *a, int *b);
int		tablen(char **tab);
char		*my_putnbr_char(int nb);
char            *my_epurstr(char *s, char c);
char		*my_revstr(char *str);
char		*my_strcapitalize(char *str);
char		*my_strcat(char *dest, char *src);
char		*my_strcpy(char *dest, char *src);
char		*my_strdup(char *src);
char		*my_strlowcase(char *str);
char		*my_strncat(char *dest, char *src, int nb);
char		*my_strstr(char *str, char *to_find);
char		*my_strupcase(char *str);
char            *get_next_line(const int fd);
char		**add_to_tab(char *str, char **tab);
char		**my_str_to_wordtab(char *src, char c);
char		**tabcpy(char **src, char **tab);
char            **tabdup(char **src);

#endif
