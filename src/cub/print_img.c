#include "../../inc/cub.h"

int	wall_finder(t_data *data, double ray_len, double angle, int j)
{
	double	xx;
	double	yy;

	(void)j;
	data->player.xx = data->player.x + ray_len * cos(angle);
	data->player.yy = data->player.y + ray_len * sin(angle);
	xx = data->player.xx;
	yy = data->player.yy;
	if (data->parse.map[(int)yy][(int)xx] == '1' \
			|| data->parse.map[(int)yy][(int)xx] == '\0' \
			|| data->parse.map[(int)yy][(int)xx] == ' ')
		return (1);
	return (0);
}

double	correct_angle(double angle)
{
	if (angle >= 2 * M_PI)
		return (angle - 2 * M_PI);
	else if (angle < 0)
		return (angle + 2 * M_PI);
	return (angle);
}

void	print_img(t_data *data)
{
	int		j;
	double	ray_len;
	double	angle;

	angle = data->player.player_facing - M_PI_2 / 3;
	j = 0;
	while (++j < WIDTH)
	{
		angle = angle + (M_PI / 3) / WIDTH;
		angle = correct_angle(angle);
		ray_len = 0.000001;
		while (!wall_finder(data, ray_len, angle, j))
			ray_casting(&ray_len, data->player.xx, data->player.yy, angle);
		pixel_to_img(data, j - 1, ray_len, angle);
	}
}

void	display_img(void *param)
{
	t_data	*data;

	data = param;
	print_img(data);
}
