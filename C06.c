#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_puts(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
}

int ft_str_cmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while ((s1[i] == s2[i]) && (s1[i] && s2[i]))
		i++;
	return (s1[i] - s2[i]);
}

int main(int argc, char *argv[])
{

	int		flag;
	int i;
	char *tmp;

	flag = 1;
	while (flag)
	{
		flag = 0;
		i = 0;
		while (++i < argc - 1)
		{
			if (ft_str_cmp(argv[i], argv[i + 1]) > 0) /* a b c*/
			{
				tmp = argv[i];
				argv[i] = argv[i + 1];
				argv[i + 1] = tmp;
				flag = 1;
			}
		}
	}
	i = 0;
	while (++i < argc)
		ft_puts(argv[i]), ft_putchar('\n');

	return (0);
}
