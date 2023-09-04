#include <unistd.h>

void _putchar(char c)
{
    write(1, &c, 1);
}

void print_comb(char *prefix, int n, int last_digit, int level)
{
	int i;
	i = last_digit + 1;

	if (n == 0)
	{
		write(1, prefix, level);
		if (prefix[0] != '9' - level + 1)
			write(1, ", ", 2);
		return;
	}
	while (i <= 9)
	{
		prefix[level] = i + '0';
		print_comb(prefix, n - 1, i, level + 1);
		i++;
	}

}

void ft_print_combn(int n)
{
	char prefix[10];
	print_comb(prefix, n, -1, 0);
}

int main(void)
{
    ft_print_combn(4);
	_putchar('\n');
    return (0);
}
