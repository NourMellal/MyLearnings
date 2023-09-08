#include "../includes/ft.h"

void no_args(char **av)
{
	char 	buf[BUF_SIZE];
	int bytesRead;

	while (1)
	{
		errno = 0;
		bytesRead = read(0, buf, BUF_SIZE);
		if (bytesRead > 0)
			write(1, buf, bytesRead);
		else if (bytesRead == 0)
			break;
		else
		{
			if (errno != 0)
			{
				ft_putstr(basename(av[0]), 2);
				ft_putstr(": stdin: ", 2);
				ft_putstr(strerror(errno), 2);
				ft_putchar('\n', 2);
			}
			break;
		}
	}
}
