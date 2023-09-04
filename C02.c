#include <stdio.h>
#include <unistd.h>
#include <string.h>
char *ft_strcpy(char *dest, char *src, size_t n)
{
	int i;

	i = 0;

	while (src[i] && i <= n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}
/*

\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
    	////////////////////////////////////////////////////////
		/////////////////////strcpy main//////////////////
int main()
{
	char dest[90] = "Hello, ";
	char src[] = "World!";
	char *ptr = ft_strcpy(dest, src);
	printf("%s\n", ptr);
	printf("%s\n", src);
	printf("%s\n", dest);
	return 0;
}
*/

int ft_str_is_alpha(char *str)
{
	int i;

	i = 0;

	while (str[i])
	{
		/* number is less than 'a' but not greater than 'z' sor we should use || not && :D */
		if ((str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
			return (0);
		i++;
	}
	return (1);
}
/*


\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
 ////////////////////////ft_str_is_alpha main//////////////////////////
///////////////////////////////////////
int main(int argc, char const *argv[])
{
	int n = ft_str_is_alpha("Hello");
	printf("%d\n", n);
	return 0;
}
*/

int ft_str_is_numeric(char *str)
{
	int i = 0;

	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}
/*

////////////////////////////////////// ft_str_is_numeric mian ////////////////////////////
int main(int argc, char const *argv[])
{
	int n = ft_str_is_numeric("1234567");
	printf("%d\n", n);
	return 0;
}
*/

int ft_str_is_lowercase(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] < 'a' || str[i] > 'z')
			return (0);
		i++;
	}
	return (1);
}

/*
///////////////////ft_str_is_lowercase main////////////////////
int main(int argc, char const *argv[])
{
	int n = ft_str_is_lowercase("abcds");
	printf("%d\n", n);
	return 0;
}
*/

int ft_str_is_printable(char *str)
{
	int i = 0;


	while (str[i])
	{
		if (str[i] < 32 || str[i] > 126)
			return (0);
		i++;
	}
	return (1);
}

char *ft_strlowercase(char *str)
{
	int i = 0;

	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
	return (str);
}
/*
///////////////// ft_strupcase main //////////////////
int main(int argc, char const *argv[])
{
	char str[] = "HELLO world!";
	char *ptr = ft_strupcase(str);
	printf("%s\n", ptr);
	return 0;
}
*/

int is_alpha(char c)
{
	return (c >= 'a' && c <= 'z');
}

int is_num(char c)
{
	return (c >= '0' && c <= '9');
}

char *ft_strcapitalize(char *str)
{
	int i = 0;
	int flag = 0;

	ft_strlowercase(str);
	while (str[i])
	{
		if (is_alpha(str[i]) || is_num(str[i]))
		{
			if (flag == 0)
			{
				if (is_alpha(str[i]))
					str[i] -= 32;
				flag = 1;
			}
		}
		else
			flag = 0;
		i++;
	}

	return (str);
}

////////////////////// ft_strcapitalize main //////////////////
/*
int main(int argc, char const *argv[])
{
	char str[] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";
	char *ptr = ft_strcapitalize(str);
	printf("%s\n", ptr);
	return 0;
}
*/


unsigned int ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int i = 0;
	unsigned int len = 0;

	while (src[len])
		len++;

	if (size == 0)
		return (len);

	while (src[i] && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (len);
}

/* ===================================================== */

void print_hex(int n)
{
	char *hex;

	hex = "012345789abcdef";

	if (n > 16)
	{
		print_hex(n / 10);
		print_hex(n % 10);
	}
	else
		write(1, &hex[n], 1);
}

void ft_putstr_non_printable(char *str)
{
	int i;

	i = 0;
	while (str[i]) /* Coucou\ntu vas bien  */
	{
		if (str[i] <= 31 && str[i] >= 0 || str[i] == 127)
		{
			write(1, "\\", 1);
			if (str[i] < 16)
				write(1, "0", 1);
			print_hex(str[i]);
		}
		else
			write(1, &str[i], 1);
		i++;
	}
}
/*
int main(int argc, char const *argv[])
{
	ft_putstr_non_printable("Coucou\ntu vas bien");
	putchar('\n');
	return 0;
}
*/
/* ========================================================== */

/* ========================================================== */

/*
int ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2)
	{
		if (!*s1)
			return (0);
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int main(int argc, char const *argv[])
{
	char *s1 = "Hello";
	char *s2 = "Hello";
	int n = ft_strcmp(s1, s2);
	printf("%d\n", n);
	return 0;
}
*/

/* ======================================================== */

/*
int ft_strncmp(char *s1, char *s2, unsigned int n)
{
	int i;

	i = 0;
	while (s1[i] && s2[i] && i < n)
	{
		if (s1[i] != s2[i])
			return((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	if (i < n)
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (0);
}
*/

/* ======================================================== */

/*
char *ft_strstr(char *str, char *to_find)
{
	char *to_finde_ptr;
	char *pt_str;

	if (!to_find)
		return (str);

	while (*str)
	{
		if (*str == *to_find)
		{
			pt_str = str;
			to_finde_ptr = to_find;

			while (1)
			{
				if (!*to_finde_ptr)
					return (str);
				if (*to_finde_ptr != *pt_str)
					break;
				to_finde_ptr++;
				pt_str++;
			}
		}
		str++;
	}
	return ('\0');
}

int main(int argc, char const *argv[])
{
	char *ptr = ft_strstr("hello this is a test for sevkir", "test");
	printf("%s\n", ptr);
	return 0;
}
*/

/* ======================================================== */

/*

unsigned int _strlen(char *str)
{
	unsigned int i = 0;

	while (str[i])
		i++;
	return (i);
}

unsigned int ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int len1 = 0;
	unsigned int len2 = 0;
	unsigned int i = 0;

	len1 = _strlen(src);
	len2 = _strlen(dest);

	if (size == 0 || len2 >= size)
		return (len1 + size);
	while (src[i] && (len2 + i) < size - 1)
	{
		dest[len2 + i] = src[i];
		i++;
	}
	dest[len2 + i] = '\0';
	return (len1 + len2);
}

int main()
{
    char first[] = "This is ";
    char last[] = "a potentially long string";
    int r;
    int size = 60;
    char buffer[size];

    strcpy(buffer,first);
    r = ft_strlcat(buffer,last,size);

    puts(buffer);
    printf("Value returned: %d\n",r);
    if( r > size )
        puts("String truncated");
    else
        puts("String was fully copied");

    return(0);
}
*/

/* ======================================================== */