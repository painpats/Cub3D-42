#include "../../inc/cub.h"

void	print_error_free(char *str, t_data *data)
{
	free_sstr(data->parse.map);
	free_sstr(data->parse.filecontent);
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(str, 2);
	exit (EXIT_FAILURE);
}

int	open_file(char *file)
{
	int	fd;

	fd = open(file, O_DIRECTORY);
	if (fd != -1)
	{
		close(fd);
		return (ERROR);
	}
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (ERROR);
	return (fd);
}
