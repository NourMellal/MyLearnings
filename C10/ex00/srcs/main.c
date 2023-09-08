#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUFF_SIZE 2048

int ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return(i);
}

void ft_pucthar(char c, int std)
{
	write(std, &c, 1);
}

void ft_putstr(char *s, int std, int len)
{
	int i;
	if (len == 0)
		len = ft_strlen(s);
	i = -1;
	while (++i < len)
		ft_pucthar(s[i], std);

}

void read_file(char *file_path)
{
	char buffer[BUFF_SIZE];
	int size;
	int file;

	file = open(file_path, O_RDONLY);

	if (file != -1)
	{
		while (1)
		{
			size = read(file, buffer, BUFF_SIZE);

			if (size <= 0)
			{
				ft_pucthar('\n', 1);
				close(file);
				break;
			}
			ft_putstr(buffer, 1, size);
		}
	}
	else
		ft_putstr("Cannot read file.\n", 2, 0);
}

int main(int argc, char *argv[])
{
	if (argc == 1)
		ft_putstr("File name missing.\n", 2, 0);
	else if (argc > 2)
		ft_putstr("Too many arguments.\n", 2, 0);
	else
		read_file(argv[1]);
	return 0;
}
