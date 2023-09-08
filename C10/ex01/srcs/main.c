#include "../includes/ft.h"

int main(int argc, char *argv[])
{
	int		i;

	if (argc == 1)
		no_args(argv);
	else
	{
		i = 0;
		while (++i < argc) /* ./a.out main.c .... invalid_file ....... ... */
			if (file_read(argv[i]) == 0)
			{
				ft_putstr(basename(argv[0]), 2);
				ft_putstr(": ", 2);
				ft_putstr(argv[i], 2);
				ft_putstr(": ", 2);
				ft_putstr(strerror(errno), 2);
				ft_putchar('\n', 2);
			}
			else
				ft_putchar('\n', 1);
	}
	return 0;
}
