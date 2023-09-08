#include "../includes/ft.h"

void ft_putchar(char c, int std)
{
	write(std, &c, 1);
}