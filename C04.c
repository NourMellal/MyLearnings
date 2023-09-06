/* ======================================================== */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


void ft_putchar(char c)
{
	write(1, &c , 1);
}
/* ======================================================== */

/* void ft_putnbr(int nb)
{
	int n;

	if (nb < 0)
	{
		n = -nb;
		ft_putchar('-'); -445
	}
	else
		n = nb;

	if (n > 9)
		ft_putnbr(n / 10);
	ft_putchar(n % 10 + 48);
}

int main(int argc, char const *argv[])
{
	ft_putnbr(-445);
	return 0;
}
 */

/* ======================================================== */


int is_space(char c)
{
	return (c == ' ' || c == '\n' || c == '\t' || c == '\r' || c == '\v');
}

int is_num(char c)
{
	return (c >= '0' && c <= '9');
}

int ft_atoi(char *str)
{
	int		i;
	int		res;
	int		sign;

	i = 0;
	res = 0;
	sign = 1;

	while (is_space(str[i]))
		i++;

	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}

	while (is_num(str[i]))
	{
		res = (res * 10) + str[i] - 48;
		i++;
	}
	return (res * sign);
}
/*
int main(int argc, char const *argv[])
{
	int r = ft_atoi(" ---+--+1234ab567");
	printf("%d\n", r);
	return 0;
}
*/

/* ======================================================== */



void ft_putnbr_base_helper(int nbr, char *base, int numbase)
{
	long n = nbr;

	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n >= numbase)
		ft_putnbr_base_helper(n / numbase, base, numbase);
	ft_putchar(base[n % numbase]);
}

int is_duplicated(char *s)
{
	int i;
	int j;

	i = 0;

	while (s[i])
	{
		j = i + 1;
		while (s[j])
		{
			if (s[i] == s[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void ft_putnbr_base(int nbr, char *base)
{
	int numbase;

	numbase = 0;
	while (base[numbase])
	{
		if (base[numbase] == '-' || base[numbase] == '+')
			return;
		numbase++;
	}
	if (numbase < 2)
		return;

	if (is_duplicated(base))
		return;

	ft_putnbr_base_helper(nbr, base, numbase);
}



int cheack_base(char *base)
{
	int		i;
	int		j;

	i = 0;
	while (base[i])
		i++;

	if (i < 2)
		return (0);

	i = 0;
	while (base[i])
	{
		if (base[i] == '-' || base[i] == '+' || base[i] == '\n' ||
		base [i] == '\t' || base[i] == ' ')
			return (0);

		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int is_in_base(char c, char *base)
{
	int 	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (1);
		i++;
	}
	return (0);

}

int get_int_from_base(char c, char *base)
{
	int 	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (i);

}

int skip_and_count(char *s, int *pointer_i)
{
	int 	i;
	int		minus_count;

	i = 0;
	while (s[i] == '\n' || s[i] == ' ' || s[i] == '\t' || s[i] == '\v')
		i++;

	minus_count = 0;
	while (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			minus_count++;
		i++;
	}

	*pointer_i = i;
	return (minus_count);
}

int ft_atoi_base(char *str, char *base)
{
	int i;
	int sign;
	int div;
	int res;

	res = 0;
	i = 0;
	if (!cheack_base(base))
		return (0);

	while (base[i])
		i++;
	div = i;

	sign = 1;
	if (skip_and_count(str, &i) % 2)
		sign *= -1;

	while (str[i] && is_in_base(str[i], base)) /* 1a == 26 div = 15*/
	{
		res *= div; /* res * 15 ==   0 x 15 == 0 */
		res += get_int_from_base(str[i], base);  /* 0123456789abcdef
												15 + 1 = 16 + 10 = 26 */
		i++;
	}
	return (res * sign); /* 1 = 15 + 10 = 26 */
}

int main()
{
    // Test 1: Convert "26" from base 16 to base 10. Expected output: 38
    int r1 = ft_atoi_base("26", "0123456789abcdef");
    printf("Test 1: %d (Expected: 38)\n", r1);

    // Test 2: Convert "1010" from base 2 to base 10. Expected output: 10
    int r2 = ft_atoi_base("1010", "01");
    printf("Test 2: %d (Expected: 10)\n", r2);

    // Test 3: Convert "111" from base 10 to base 10. Expected output: 111
    int r3 = ft_atoi_base("111", "0123456789");
    printf("Test 3: %d (Expected: 111)\n", r3);

    // Test 4: Convert "A" from base 16 to base 10. Expected output: 10
    int r4 = ft_atoi_base("A", "0123456789ABCDEF");
    printf("Test 4: %d (Expected: 10)\n", r4);

    // Test 5: Convert "7F" from base 16 to base 10. Expected output: 127
    int r5 = ft_atoi_base("7F", "0123456789ABCDEF");
    printf("Test 5: %d (Expected: 127)\n", r5);

    // Test 6: Convert "ZZ" from base 36 to base 10. Expected output: 1295
    int r6 = ft_atoi_base("ZZ", "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    printf("Test 6: %d (Expected: 1295)\n", r6);

    // Test 7: Invalid base (base is empty). Expected output: 0
    int r7 = ft_atoi_base("1010", "");
    printf("Test 7: %d (Expected: 0)\n", r7);

    // Test 8: Invalid base (base has size of 1). Expected output: 0
    int r8 = ft_atoi_base("1010", "0");
    printf("Test 8: %d (Expected: 0)\n", r8);

    return 0;
}

