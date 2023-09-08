#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

int ft_iterative_factorial(int nb)
{
	int res;
	int fac;

	res = 1;
	fac = 1;

	if (nb == 0 || nb == 1)
		return (1);
	if (nb < 0 || nb > 12)
		return (0);

	while (fac <= nb)
	{
		res *= fac;
		fac++;
	}
	return (res);
}
/*
int main(int argc, char const *argv[])
{
	int res = ft_iterative_factorial(5);
	int res2 = ft_iterative_factorial(-5);
	int res3 = ft_iterative_factorial(13);
	int res4 = ft_iterative_factorial(0);

	printf("%d\n", res);
	printf("%d\n", res2);
	printf("%d\n", res3);
	printf("%d\n", res4);
	return 0;
}
*/

int ft_recursive_factorial(int nb)
{
	if (nb == 0 || nb == 1)
		return (1);
	if (nb < 0 || nb > 12)
		return (0);

	return (nb * ft_recursive_factorial(nb -1));
}
/*

int main(int argc, char const *argv[])
{
	int res = ft_recursive_factorial(5);
	int res2 = ft_recursive_factorial(-5);
	int res3 = ft_recursive_factorial(13);
	int res4 = ft_recursive_factorial(0);

	printf("%d\n", res);
	printf("%d\n", res2);
	printf("%d\n", res3);
	printf("%d\n", res4);
	return 0;
}
*/

int ft_iterative_power(int nb, int power)
{
	int res;

	res = 1;
	if (power < 0)
		return (0);

	if (nb == 0 && power == 0)
		return (1);

	while (power)
	{
		res = nb * res; /* 1 = 2 * 1 == 2 = 2 * 2 == 4 == 2 * 4 = 8  if pow 3 and nb = 2 */
		power--;
	}
	return (res);
}
/*
int main(int argc, char const *argv[])
{
	int r = ft_iterative_power(2, 8);
	printf("%d\n", r);
	return 0;
}
*/

int ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);

	/* base case */

	if (power == 0)
		return (1);

	if (nb == 0)
		return (0);

	return (nb * ft_iterative_power(nb, power - 1));
}
/*
int main(int argc, char const *argv[])
{
	int r = ft_iterative_power(5, 5);
	printf("%d\n", r);
	return 0;
}
*/

int ft_fibonacci(int index)
{
	if (index < 0)
		return (-1);

	if (index == 0)
		return (0);

	if (index == 1)
		return (1);

	return (ft_fibonacci(index - 1) + ft_fibonacci(index - 2));
}


int sqrt_helper(int sqrt, int nb)
{
	if (sqrt * sqrt == nb)
		return (sqrt);

	if (sqrt * sqrt > nb)
		return (-1);

	return(sqrt_helper(sqrt + 1, nb));
}

int ft_sqrt(int nb)
{
	int sqrt;

	sqrt = 1;

	if (nb == 0)
		return (0);
	if (nb < 0)
		return (-1);

	return (sqrt_helper(sqrt, nb));
}
/*
int main(int argc, char const *argv[])
{
	int r1 = ft_sqrt(9);
	int r2 = ft_sqrt(25);
	int r3 = ft_sqrt(17);
	int r4 = ft_sqrt(144);

	printf("%d\n", r1);
	printf("%d\n", r2);
	printf("%d\n", r3);
	printf("%d\n", r4);

	return 0;
}
*/
/*
bool *_memset(bool *arr, int val, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		arr[i] = val;
	}
	return (arr);
}

int SieveOfEratosthenes(int n)
{
	bool prime[n + 1];
	int p;
	int i;

	_memset(prime, 1, sizeof(prime));

	i = 0;
	p = 2;
	while (p * p <= n)
	{
		if (prime[p])
		{
			i = p * p;
			while (i <= n)
			{
				prime[i] = 0;
				i += p;
			}
		}
		p++;
	}


	p = 2;
	while (p <= n)
	{
		if (prime[p])
		{
			if (p == n)
				return (1);
		}
		p++;
	}
	return (0);
}
*/

/*
int main(int argc, char const *argv[])
{
	int r = SieveOfEratosthenes(47);
	int r2 = SieveOfEratosthenes(18);
	int r3 = SieveOfEratosthenes(0);
	int r4 = SieveOfEratosthenes(1);

	printf("%d\n", r);
	printf("%d\n", r2);
	printf("%d\n", r3);
	printf("%d\n", r4);
	return 0;
}
*/
int prime_helper(int nb, int i)
{
	if (i > nb / i)
		return (1);

	if (nb % i == 0)
		return (0);

	return (prime_helper(nb, i + 1)); /* 11 / 2 == 5 ==> 3 == 11 / 4 11 / 4*/
}

int ft_is_prime(int nb)
{
	if (nb <= 1)
		return (0);

	return (prime_helper(nb, 2));
}


/*
int main(int argc, char const *argv[])
{
	long r = ft_is_prime(__INT_MAX__);
	int r2 = ft_is_prime(17);
	int r3 = ft_is_prime(0);
	int r4 = ft_is_prime(1);

	printf("%ld\n", r);
	printf("%d\n", r2);
	printf("%d\n", r3);
	printf("%d\n", r4);
	return 0;
	return 0;
}
*/

int ft_find_next_prime(int nb)
{
	int		i;

	if (nb < 2)
		return (2);

	i = nb;

	while (1)
	{
		if (ft_is_prime(i))
			return (i);
		i++;
	}
}

int main()
{
	int r = ft_find_next_prime(-60);
	int r2 = ft_find_next_prime(18);
	int r3 = ft_find_next_prime(0);
	int r4 = ft_find_next_prime(1);

	printf("%d\n", r);
	printf("%d\n", r2);
	printf("%d\n", r3);
	printf("%d\n", r4);
	return 0;
}