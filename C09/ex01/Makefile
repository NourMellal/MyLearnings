
SRC = ft_putchar.c ft_strlen.c ft_putstr.c ft_swap.c ft_strcmp.c

RM = rm -f

NAME = libft.a

PATH = ./srcs/

SRCS = ${addprefix ${PATH}, ${SRC}}

IDX = ranlib

HEADER = ./includes/

AR = ar rcs

OBJ = ${SRCS:.c=.o}

GCC = gcc

FLAGS = -Wall -Wextra -Werror


all: ${NAME}

.c.o:
	${GCC} ${FLAGS} -c -I ${HEADER} $< -o ${<:.c=.o} 

${NAME} ${OBJ}:
	${AR} ${NAME} ${OBJ}
	${IDX} ${NAME}

clean:
	${RM} ${OBJ}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
