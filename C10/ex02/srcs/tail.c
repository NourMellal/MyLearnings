#include "../includes/ft.h"


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
		else if (len == -1)
			break;
		else if (len == 0);
			break;
	}
	return (content);
}

void ft_tail(int fd, int count)
{
	char *file_content;

	file_content = proc_file(fd);
	if (count > ft_strlen(file_content))
		count = ft_strlen(file_content);
	while (file_content[ft_strlen(file_content) - count])
		write(1, &file_content[ft_strlen(file_content) - count--], 1);
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