
#ifndef _FT_H
#define _FT_H


#define BUF_SIZE 2048

#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <libgen.h>
#include <string.h>


void ft_putstr(char *str, int std);
void ft_putchar(char c, int std);
void	ft_putstr_buf(char *str, int size);
void no_args(char **av);
int file_read(char *file_path);

#endif