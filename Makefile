COMP			=	gcc

RM			=	rm -f

ASM			=	./asm/asm
VM			=	./corewar/corewar

DIR_A			=	./asm/src/
DIR_V			=	./corewar/src/

SRC_A			=	$(DIR_A)main.c			\
				$(DIR_A)write_header.c		\
				$(DIR_A)asm.c			\
				$(DIR_A)parsing.c		\
				$(DIR_A)putnb_fd.c		\
				$(DIR_A)op.c			\
				$(DIR_A)write_function.c	\
				$(DIR_A)write_octet_codage.c	\
				$(DIR_A)check_args_parsing.c	\
				$(DIR_A)label.c			\
				$(DIR_A)label2.c		\
				$(DIR_A)write_params.c		\
				$(DIR_A)write_params2.c

SRC_V			=	$(DIR_V)main.c		\
				$(DIR_V)arena.c		\
				$(DIR_V)check_opt.c	\
				$(DIR_V)fighters.c	\
				$(DIR_V)func.c		\
				$(DIR_V)init.c		\
				$(DIR_V)load.c		\

OBJ_A			=	$(SRC_A:.c=.o)
OBJ_V			=	$(SRC_V:.c=.o)

LDFLAGS			=	-L ./lib/ -lmy

CFLAGS			+= 	-W -Wall -Werror -Wextra -W -I ./include/
CFLAGS			+=	$(LDFLAGS)

all:			$(ASM) $(VM)

$(ASM):			$(OBJ_A)
			$(COMP) -o $(ASM) $(OBJ_A) $(CFLAGS)

$(VM):			$(OBJ_V)
			$(COMP) -o $(VM) $(OBJ_V) $(CFLAGS)

clean:
			$(RM) $(OBJ_A)
			$(RM) $(OBJ_V)

fclean:			clean
			$(RM) $(ASM)
			$(RM) $(VM)

re:			fclean all

dbg: CFLAGS += -g -g3
dbg: re
