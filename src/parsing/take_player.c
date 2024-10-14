#include "../../inc/cub.h"

void	set_player_facing(t_data *data, char c)
{
	if (c == 'N')
		data->player.player_facing = M_PI_2 * 3;
	if (c == 'E')
		data->player.player_facing = 0;
	if (c == 'S')
		data->player.player_facing = M_PI_2;
	if (c == 'W')
		data->player.player_facing = M_PI;
}

int	is_player_pos(t_data *data, char *map_tab, int *x, int *y)
{
	int	i;

	i = 0;
	while (map_tab[i])
	{
		if (map_tab[i] == 'N' || map_tab[i] == 'E' || \
				map_tab[i] == 'W' || map_tab[i] == 'S')
		{
			if (data->player.x != -1)
				return (0);
			set_player_facing(data, map_tab[i]);
			data->player.x = (double)(*x) + 0.5;
			data->player.y = (double)(*y) + 0.5;
			map_tab[i] = '0';
		}
		i++;
		(*x)++;
	}
	return (1);
}

int	map_reader(t_data *data)
{
	int		x;
	int		y;
	int		i;

	i = 0;
	x = 0;
	y = 0;
	while (data->parse.map[i])
	{
		if (!(is_player_pos(data, data->parse.map[i], &x, &y)))
			return (0);
		y++;
		i++;
		x = 0;
	}
	return (1);
}
