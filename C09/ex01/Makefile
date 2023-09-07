# List of source files
SRC = ft_putchar.c ft_strlen.c ft_putstr.c ft_swap.c ft_strcmp.c

# Add the path prefix to each source file
SRCS = ${addprefix ${SRC_PATH}, ${SRC}}

# Generate object file names from source file names
OBJ = ${SRCS:.c=.o}

# Path to the source files
SRC_PATH = ./srcs/

# Path to the header files
HEADER = ./includes/

# Name of the library to be created
NAME = libft.a

# Command to create an archive library
AR = ar rc

# Command to remove files
RM = rm -f

# Command to index the library
IDX = ranlib

# GCC compiler
GCC = gcc

# Compiler flags
FLAGS = -Wall -Wextra -Werror

# Default target 'all' to build the library
all: ${NAME}

# Rule to compile .c to .o
.c.o:
	${GCC} ${FLAGS} -c -I ${HEADER} $< -o ${<:.c=.o}

# Rule to create the library
${NAME}: ${OBJ}
	${AR} ${NAME} ${OBJ}
	${IDX} ${NAME}

# Rule to clean object files
clean:
	${RM} ${OBJ}

# Rule to clean object files and the library
fclean: clean
	${RM} ${NAME}

# Rule to recompile everything
re: fclean all

# Phony targets to ensure that make doesn't do anything with a file named clean, fclean, etc.
.PHONY: all clean fclean re
