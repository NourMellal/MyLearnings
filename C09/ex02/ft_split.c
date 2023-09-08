#include <stdlib.h>
#include <stdio.h>

int ft_is_sperator(char c, char *charset)
{
	int i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	if (c == '\0')
		return (1);
	return (0);
}

int ft_count_words(char *str, char *charset)
{
	int i;
	int words;

	i = 0;
	words = 0;

	while (str[i])
	{
		if (ft_is_sperator(str[i + 1], charset) == 1 /* Hello, World! == " ,!"*/
			&& ft_is_sperator(str[i], charset) == 0)
				words++;
		i++;
	}
	return (words);
}

void write_in_grid(char *dest, char *src, char *charset)
{
	int i;

	i = 0;
	while (ft_is_sperator(src[i], charset) == 0)  /* Hello, World! == " ,!" */
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

int grid_define(char **grid, char *str, char *charset) /* Hello, World! == " ,!" */
{
	int i;
	int j;
	int word;

	word = 0;
	i = 0;
	while (str[i])
	{
		if (ft_is_sperator(str[i], charset) == 1)
			i++;
		else /* Hello, World! == " ,!" */
		{
			j = 0;
			while (ft_is_sperator(str[i + j], charset) == 0)
				j++;
			grid[word] = malloc(sizeof(char) * (j + 1));
			if (!grid[word])
				return (-1);
			write_in_grid(grid[word], str + i, charset);
			i += j;
			word++;
		}
	}
	return (0);
}

char **ft_split(char *str, char *charset)
{
	char **grid;
	int words;
	int i;

	words = ft_count_words(str, charset);
	grid = malloc(sizeof(char *) * (words + 1));
	if (!grid)
		return (NULL);
	grid[words] = 0;
	if (grid_define(grid, str, charset) != 0)
	{
		i = 0;
		while (i < words)
		{
			if (grid[i])
				free(grid[i]);
			i++;
		}
		free(grid);
		return (NULL);
	}
	return (grid);
}


/*
// Assuming ft_split is defined somewhere
char **ft_split(char *str, char *charset);

int main() {
    char **result;

    // Test 1: Splitting by space
    result = ft_split("Hello world!", " !");
    // Expected output: "Hello", "world!"
    printf("Test 1:\n");
    for (int i = 0; result[i] != 0; i++) {
        printf("%s\n", result[i]);
    }
    printf("\n");

    // Test 2: Splitting by comma and space
    result = ft_split("apple, orange, banana", ", ");
    // Expected output: "apple", "orange", "banana"
    printf("Test 2:\n");
    for (int i = 0; result[i] != 0; i++) {
        printf("%s\n", result[i]);
    }
    printf("\n");

    // Test 3: Splitting by a character not in the string
    result = ft_split("Hello world!", "z");
    // Expected output: "Hello world!"
    printf("Test 3:\n");
    for (int i = 0; result[i] != 0; i++) {
        printf("%s\n", result[i]);
    }
    printf("\n");

    // Test 4: Splitting by multiple characters
    result = ft_split("a::b::c::d::e", ":");
    // Expected output: "a", "b", "c", "d", "e"
    printf("Test 4:\n");
    for (int i = 0; result[i] != 0; i++) {
        printf("%s\n", result[i]);
    }
    printf("\n");

    // Test 5: Splitting an empty string
    result = ft_split("", " ");
    // Expected output: (nothing, array should be empty)
    printf("Test 5:\n");
    for (int i = 0; result[i] != 0; i++) {
        printf("%s\n", result[i]);
    }
    printf("\n");

    return 0;
}
*/