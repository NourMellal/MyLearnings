DIRSRC	 	=		srcs/

SRC 		=       file_read.c ft_putchar.c ft_putstr.c handle_args_error.c main.c

SRCS		=		${addprefix ${DIRSRC}, ${SRC}}

OBJS		=		${SRCS:.c=.o}

NAME		=		ft_cat

GCC			=		gcc

RM			=		rm -f

CFLAGS		=		-Wall -Werror -Wextra

${NAME}:		${OBJS}
	${GCC} -o ${NAME} ${OBJS} ${FLAGS}

all:			${NAME}

clean:
	${RM} ${OBJS}

fclean:			clean
	${RM} ${NAME}

re:				fclean all

.PHONY:			fclean all clean re