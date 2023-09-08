NAME 		= 		ft_display_file

GCC			=		gcc

OBJS		=		${SRCS:.c=.o}

CFLAG 		=		-Wall -Werror -Wextra

MAIN_SRC 	=		srcs/

SRCS 		=		${MAIN_SRC}main.c

RM			=		rm -f




${NAME}: ${OBJS}
	${GCC} -o ${NAME} ${OBJS} ${CFLAG}

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re:	fclean all

.PHONY: all clean fclean re
