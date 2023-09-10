#include "../includes/ft.h"

int ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while ((s1[i] == s2[i]) && (s1[i] && s2[i]))
		i++;
	return (s1[i] - s2[i]);
}

int ft_atoi(char *str)
{
	int resault;
	int i;

	i = -1;
	resault = 0;
	while (str[++i])
		resault = (resault * 10) + str[i] - 48;
	return (resault);
}

void ft_putchar(char c, int std)
{
	write(std, &c, 1);
}

void ft_putstr(char *str, int std)
{
	int i;

	i = -1;
	while (str[++i])
		ft_putchar(str[i], std);
}

int ft_strlen(char *str)
{
	int i;
	i = -1;
	while (str[++i])
		;
	return (i);
}