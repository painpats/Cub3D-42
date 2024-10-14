#include "../../inc/cub.h"

int	check_walls_error(t_data *data, char c, size_t y_col, size_t x_lin)
{
	if ((y_col == data->parse.y_max || y_col == 0
			|| x_lin == data->parse.x_max || x_lin == 0)
		&& (c == '0' || c == 'N' || c == 'E' || c == 'W'
			|| c == 'S'))
		return (1);
	return (0);
}

void	check_walls(t_data *data)
{
	char	**nmap;
	size_t	x_lin;
	size_t	y_col;

	nmap = data->parse.map;
	y_col = 0;
	if (nmap[0] == NULL)
		print_error_free("MAP -> Where are the walls ?", data);
	data->parse.x_max = ft_strlen(nmap[0]) - 1;
	data->parse.y_max = len_sstr(nmap) - 1;
	while (nmap[y_col])
	{
		x_lin = 0;
		while (nmap[y_col][x_lin])
		{
			if (check_walls_error(data, nmap[y_col][x_lin], y_col, x_lin))
				print_error_free("MAP -> Where are the walls ?", data);
			else
				check_surrounding(data, y_col, x_lin);
			x_lin++;
		}
		y_col++;
	}
}

int	map_empty(char **nmap)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (nmap[i])
	{
		while (nmap[i][j])
		{
			if (nmap[i][j] == 'N' || nmap[i][j] == 'E'
				|| nmap[i][j] == 'S' || nmap[i][j] == 'W')
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

void	check_surrounding(t_data *data, int y_pos, int x_pos)
{
	char	**nmap;

	nmap = data->parse.map;
	if (check_case(nmap[y_pos][x_pos]))
	{
		if (!check_case_wall(nmap[y_pos - 1][x_pos]))
			print_error_free("MAP -> Map must be surrounding by walls", data);
		else if (!check_case_wall(nmap[y_pos + 1][x_pos]))
			print_error_free("MAP -> Map must be surrounding by walls", data);
		else if (!check_case_wall(nmap[y_pos][x_pos - 1]))
			print_error_free("MAP -> Map must be surrounding by walls", data);
		else if (!check_case_wall(nmap[y_pos][x_pos + 1]))
			print_error_free("MAP -> Map must be surrounding by walls", data);
	}
	if (map_empty(nmap))
		print_error_free("MAP -> Map need player", data);
}
