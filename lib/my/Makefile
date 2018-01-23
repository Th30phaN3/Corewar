CC = gcc

NAME = libmy.a

SRC = 	./add_to_tab.c		\
	./afftab.c		\
	./free_tab.c		\
	./my_find_prime_sup.c	\
	./my_power_rec.c	\
	./my_strlen.c		\
	./my_getnbr_base.c	\
	./my_getnbr.c		\
	./my_isneg.c		\
	./my_isprintable.c	\
	./my_is_prime.c		\
	./my_putchar.c		\
	./my_putchar_to_fd.c	\
	./my_putnbr_base.c	\
	./my_put_nbr.c		\
	./my_revstr.c		\
	./my_showstr.c		\
	./my_sort_int_tab.c	\
	./my_square_root.c	\
	./my_strcapitalize.c	\
	./my_strcat.c		\
	./my_strcmp.c		\
	./my_strcpy.c		\
	./my_strdup.c		\
	./my_str_isalpha.c	\
	./my_str_islower.c	\
	./my_str_isnum.c	\
	./my_str_isprintable.c	\
	./my_str_isupper.c	\
	./my_strlowcase.c	\
	./my_strncat.c		\
	./my_strncmp.c		\
	./my_strstr.c		\
	./my_str_to_wordtab.c	\
	./my_strupcase.c	\
	./my_swap.c		\
	./tabcpy.c		\
	./tabdup.c		\
	./tablen.c		\
	./my_putstr.c		\
	./my_epurstr.c		\
	./my_putstr_to_fd.c	\
	./my_putnbr_char.c	\
	./my_isope.c		\
	./my_isope_custom.c	\
	./my_printf.c		\
	./funct_printf.c	\
	./funct_printf2.c	\
	./get_next_line.c	\
	./error_malloc.c

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rc ../$(NAME) $(OBJS)
	cp ./my.h ../../include/my.h

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
