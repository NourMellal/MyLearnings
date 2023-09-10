#include "../includes/ft.h"

char *concat_realloc(char *dest, char *src, int n)
{
	int i;
	int destlen;
	char *resault;

	resault = malloc((ft_strlen(dest) + ft_strlen(src) + 1) * sizeof(char));
	if (!resault)
		return (NULL);
	i = -1;
	while (dest[++i])
		resault[i] = dest[i];
	resault[i] = '\0';
	destlen = ft_strlen(dest);
	i = 0;
	while (src[i], i < n)
	{
		resault[destlen + i] = src[i];
		i++;
	}
	resault[destlen + i] = '\0';
	free(dest);
	return (resault);
}