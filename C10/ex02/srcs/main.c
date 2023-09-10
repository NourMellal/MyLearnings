#include "../includes/ft.h"

tail_param parse(int argc, char **argv)
{
	tail_param param;

	param.byte_value = 0;
	param.fileindex = -1;
	param.read_from_stdin = 0;

	if (argc < 3 || (ft_strcmp(argv[1], "-c") == 0 && argc < 4))
	{
		param.read_from_stdin = 1;
		if (argc == 2)
			param.byte_value = ft_atoi(argv[1] + 2);
		else
			param.byte_value = ft_atoi(argv[2]);
		return (param);
	}
	if (ft_strcmp(argv[1], "-c") == 0)
	{
		param.fileindex = 3;
		param.byte_value = ft_atoi(argv[2]);
	}
	else
	{
		param.fileindex = 2;
		param.byte_value = ft_atoi(argv[1] + 2);
	}
	return (param);
}

int main(int argc, char *argv[])
{
	tail_param param;
	int file_index;
	int fd;

	param = parse(argc, argv);
	file_index = param.fileindex;
	if (param.read_from_stdin)
		ft_tail(0, param.byte_value);
	while (file_index < argc && file_index != -1)
	{
		fd = open(argv[file_index], O_RDONLY);
		if (fd != -1)
		{
			prnt_head(argv[file_index], param.fileindex, file_index, argc);
			ft_tail(fd, param.byte_value);
			close(fd);
		}
		else
		{
			print_err(argv[file_index], argv[0]);
			close(fd);
		}
		file_index++;
	}
	return (0);
}
