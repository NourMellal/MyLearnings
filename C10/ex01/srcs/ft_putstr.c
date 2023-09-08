#include "../includes/ft.h"

void ft_putstr(char *str, int std)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i], std);
		i++;
	}
}

void	ft_putstr_buf(char *str, int size)
{
	int i;

	i = -1;
	while (++i < size)
		ft_putchar(str[i], 1);
}
