#include "../../inc/cub.h"

void	step_forward(t_data *data)
{
	if (data->parse.map[(int)(data->player.y + 0.2 * \
		sin(data->player.player_facing))] \
		[(int)(data->player.x + 0.2 * \
		cos(data->player.player_facing))] == '1' || \
		data->parse.map[(int)(data->player.y + 0.2 * \
		sin(data->player.player_facing))] \
		[(int)(data->player.x + 0.2 * \
		cos(data->player.player_facing))] == ' ' || \
		data->parse.map[(int)(data->player.y + 0.2 * \
		sin(data->player.player_facing))] \
		[(int)(data->player.x + 0.2 * \
		cos(data->player.player_facing))] == '\0')
		return ;
	data->player.y += 0.03 * sin(data->player.player_facing);
	data->player.x += 0.03 * cos(data->player.player_facing);
	print_img(data);
}

void	step_backward(t_data *data)
{
	if (data->parse.map[(int)(data->player.y + 0.1 * \
		sin(data->player.player_facing + M_PI))] \
		[(int)(data->player.x + 0.1 * \
		cos(data->player.player_facing + M_PI))] == '1' || \
		data->parse.map[(int)(data->player.y + 0.1 * \
		sin(data->player.player_facing + M_PI))] \
		[(int)(data->player.x + 0.1 * \
		cos(data->player.player_facing + M_PI))] == ' ' || \
		data->parse.map[(int)(data->player.y + 0.1 * \
		sin(data->player.player_facing + M_PI))] \
		[(int)(data->player.x + 0.1 * \
		cos(data->player.player_facing + M_PI))] == '\0')
		return ;
	data->player.y += 0.03 * sin(data->player.player_facing + M_PI);
	data->player.x += 0.03 * cos(data->player.player_facing + M_PI);
	print_img(data);
}

void	step_left(t_data *data)
{
	double	x;
	double	y;

	y = data->player.y + 0.1 * sin(data->player.player_facing - M_PI_2);
	x = data->player.x + 0.1 * cos(data->player.player_facing - M_PI_2);
	if ((data->parse.map[(int)y][(int)x] == '1' || \
		data->parse.map[(int)y][(int)x] == '\0' || \
		data->parse.map[(int)y][(int)x] == ' '))
		return ;
	y = data->player.y + 0.2 * sin(data->player.player_facing - M_PI_2);
	x = data->player.x + 0.2 * cos(data->player.player_facing - M_PI_2);
	if ((data->parse.map[(int)y][(int)x] == '1' || \
		data->parse.map[(int)y][(int)x] == '\0' || \
		data->parse.map[(int)y][(int)x] == ' '))
		return ;
	data->player.y += 0.03 * sin(data->player.player_facing - M_PI_2);
	data->player.x += 0.03 * cos(data->player.player_facing - M_PI_2);
	print_img(data);
}

void	step_right(t_data *data)
{
	double	y;
	double	x;

	y = data->player.y + 0.1 * sin(data->player.player_facing + M_PI_2);
	x = data->player.x + 0.1 * cos(data->player.player_facing + M_PI_2);
	if (data->parse.map[(int)y][(int)x] == '1' || \
		data->parse.map[(int)y][(int)x] == '\0' || \
		data->parse.map[(int)y][(int)x] == ' ')
		return ;
	y = data->player.y + 0.2 * sin(data->player.player_facing + M_PI_2);
	x = data->player.x + 0.2 * cos(data->player.player_facing + M_PI_2);
	if (data->parse.map[(int)y][(int)x] == '1' || \
		data->parse.map[(int)y][(int)x] == '\0' || \
		data->parse.map[(int)y][(int)x] == ' ')
		return ;
	data->player.y += 0.03 * sin(data->player.player_facing + M_PI_2);
	data->player.x += 0.03 * cos(data->player.player_facing + M_PI_2);
	print_img(data);
}

void	ft_hook(void *param)
{
	t_data	*data;
	mlx_t	*mlx;

	data = param;
	mlx = data->cub.imlx;
	if (mlx_is_key_down(mlx, MLX_KEY_W))
		step_forward(data);
	if (mlx_is_key_down(mlx, MLX_KEY_S))
		step_backward(data);
	if (mlx_is_key_down(mlx, MLX_KEY_D))
		step_right(data);
	if (mlx_is_key_down(mlx, MLX_KEY_A))
		step_left(data);
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
	{
		data->player.player_facing = \
			correct_angle(data->player.player_facing + 0.02);
	}
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
		data->player.player_facing = \
			correct_angle(data->player.player_facing - 0.02);
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
}
