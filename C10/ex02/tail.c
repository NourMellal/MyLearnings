#include "includes/ft.h"


/* my_tail: protected_file.txt: Permission denied */
/* my_tail: nonexistent_file.txt: No such file or directory */
void print_err(char *filename, char *bianry)
{
	write(STDERR, basename(bianry), ft_strlen(basename(bianry)));
	write(STDERR, ": ", 2);
	write(STDERR, filename, ft_strlen(filename));
	write(STDERR, ": ", 2);
	ft_putstr(strerror(errno), STDERR);
	write(STDERR, "\n", 1);
}

char *proc_file(int fd)
{
	int len;
	char *content;
	char buffer[1024];

	content = malloc(sizeof(char) * 1);
	if (!content)
		return (NULL);
	content[0] = '\0';
	len = 1;

	while (len > 0)
	{
		len = read(fd, buffer, 1024);
		if (len > 0)
			content = concat_realloc(content, buffer, len);
	}
	return (content);
}

void ft_tail(int fd, int count)
{
	char *file_content;
	int content_len;
	int i;

	file_content = proc_file(fd);
	content_len = ft_strlen(file_content);

	if (count > content_len)
		count = content_len;

	i = content_len - count;
	while (i < content_len)
	{
		write(STDOUT, &file_content[i], 1);
		i++;
	}
}


/* ==> main.c <== */
void prnt_head(char *filename, int first_file_location, int idx, int ac)
{
	if (idx != first_file_location)
		write(STDOUT, "\n", 1);
	if (first_file_location + 1 < ac)
	{
		write(STDOUT, "==> ", 4);
		ft_putstr(filename, STDOUT);
		write(STDOUT, " <==\n", 5);
	}
}