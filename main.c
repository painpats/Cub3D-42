#include "./inc/cub.h"

int	main(int ac, char **av)
{
	t_data	data;
	char	**map;
	int		fd;

	if (ac != 2)
		print_error("Wrong number of arguments");
	init_data(&data);
	data.parse.filename = av[1];
	check_ext(data.parse.filename, ".cub");
	fd = check_open_files(data.parse.filename);
	data.parse.filecontent = read_file(fd);
	if (data.parse.filecontent[0] == NULL)
		print_error_free_sstr("Map empty !", data.parse.filecontent);
	check_map(data.parse.filecontent);
	map = get_map(data.parse.filecontent);
	data.parse.map = get_map_cub(map);
	take_data(&data);
	check_walls(&data);
	map_reader(&data);
	cub(&data);
	mlx_loop(data.cub.imlx);
	free_all(&data);
	close(fd);
	mlx_terminate(data.cub.imlx);
	return (0);
}
