#include "../includes/ft.h"

int file_read(char *file_path)
{
	int file;
	int size;
	char buf[BUF_SIZE];

	file = open(file_path, O_RDWR);
	if (file != -1)
	{
		while ((size = read(file, buf, BUF_SIZE)) != 0)
			ft_putstr_buf(buf, size);
		return (1);
	}
	else
		return (0);
}
