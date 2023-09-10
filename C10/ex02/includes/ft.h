#ifndef FT_H
#define FT_H


#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <libgen.h>
#include <stdio.h>

#define STDIN 0
#define STDOUT 1
#define STDERR 2


typedef struct tail_param
{
	int fileindex;
	int read_from_stdin;
	int byte_value;
} tail_param;


/* tools */
int ft_strcmp(char *s1, char *s2);
int ft_atoi(char *str);
void ft_putstr(char *str, int std);
void ft_putchar(char c, int std);
int ft_strlen(char *str);

/* main */
tail_param parse(int argc, char **argv);
void ft_tail(int fd, int count);
char *proc_file(int fd);
char *concat_realloc(char *dest, char *src, int n);

void print_err(char *filename, char *bianry);
void prnt_head(char *filename, int first_file_location, int idx, int ac);

#endif