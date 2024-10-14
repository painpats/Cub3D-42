#include "../../inc/cub.h"
#include "../../inc/data.h"

double	find_height(t_player *player, char name)
{
	if (name == 'e')
		return (player->yy - (int)player->yy);
	else if (name == 'w')
		return ((int)player->yy + 1 - player->yy);
	else if (name == 'n')
		return (player->xx - (int)player->xx);
	else
		return ((int)player->xx + 1 - player->xx);
}

double	find_width(double wall_h, int h, int i)
{
	if (wall_h > h)
		return ((wall_h / 2 - h / 2 + i) / wall_h);
	else
		return ((i - (h / 2 - wall_h / 2)) / wall_h);
}

int	get_color(t_data *data, mlx_image_t	*img, int x, int y)
{
	int		color;

	x = find_height(&data->player, data->face) * img->width;
	y = find_width(data->wall_h, data->width, y) * img->height;
	color = rgbint(img->pixels[(img->width * y + x) * 4],
			img->pixels[(img->width * y + x) * 4 + 1],
			img->pixels[(img->width * y + (x)) * 4 + 2], 255);
	return (color);
}

mlx_image_t	*what_wall(t_data *data)
{
	if ((int)(data->player.xx - 0.00001) != (int)(data->player.xx))
	{
		data->face = 'e';
		return (data->texture.txt_ea);
	}
	else if ((int)(data->player.xx + 0.00001) != (int)(data->player.xx))
	{
		data->face = 'w';
		return (data->texture.txt_we);
	}
	else if ((int)(data->player.yy - 0.00001) != (int)(data->player.yy))
	{
		data->face = 's';
		return (data->texture.txt_so);
	}
	else
	{
		data->face = 'n';
		return (data->texture.txt_no);
	}
}

void	pixel_to_img(t_data *data, int j, double ray_len, double angle)
{
	int			i;
	int			pixel;
	int			end;
	double		wal;
	mlx_image_t	*cur_w;

	wal = data->width / (ray_len * cos(data->player.player_facing - angle));
	i = -1;
	end = data->width / 2 + wal / 2;
	if (end > data->width)
		end = data->width;
	pixel = data->width / 2 - wal / 2;
	cur_w = what_wall(data);
	data->wall_h = wal;
	while (++i < data->width)
	{
		if (i > pixel && i <= end)
			mlx_put_pixel(data->cub.img, j, i, get_color(data, cur_w, j, i));
		else if (i <= pixel)
			mlx_put_pixel(data->cub.img, j, i, rgbint(data->texture.c_rgb[0], \
					data->texture.c_rgb[1], data->texture.c_rgb[2], 255));
		else
			mlx_put_pixel(data->cub.img, j, i, rgbint(data->texture.f_rgb[0], \
					data->texture.f_rgb[1], data->texture.f_rgb[2], 255));
	}
}
