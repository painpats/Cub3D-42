#include "../../inc/cub.h"

void	init_img(t_data *data)
{
	mlx_texture_t	*tmp;

	tmp = mlx_load_png(data->texture.path_texture_no);
	data->texture.txt_no = mlx_texture_to_image(data->cub.imlx, tmp);
	mlx_delete_texture(tmp);
	tmp = mlx_load_png(data->texture.path_texture_so);
	data->texture.txt_so = mlx_texture_to_image(data->cub.imlx, tmp);
	mlx_delete_texture(tmp);
	tmp = mlx_load_png(data->texture.path_texture_ea);
	data->texture.txt_ea = mlx_texture_to_image(data->cub.imlx, tmp);
	mlx_delete_texture(tmp);
	tmp = mlx_load_png(data->texture.path_texture_we);
	data->texture.txt_we = mlx_texture_to_image(data->cub.imlx, tmp);
	mlx_delete_texture(tmp);
	if (!data->texture.txt_we || !data->texture.txt_ea
		|| !data->texture.txt_so || !data->texture.txt_no)
	{
		mlx_terminate(data->cub.imlx);
		print_error_free("Error in texture", data);
		exit(ERROR);
	}
}

void	cub(t_data *data)
{
	data->cub.imlx = mlx_init(WIDTH, HEIGHT, "Cub3D", true);
	if (!data->cub.imlx)
	{
		puts(mlx_strerror(mlx_errno));
		exit(ERROR);
	}
	data->cub.img = mlx_new_image(data->cub.imlx, WIDTH, WIDTH);
	if (!data->cub.img)
	{
		mlx_close_window(data->cub.imlx);
		puts(mlx_strerror(mlx_errno));
		exit(ERROR);
	}
	if (mlx_image_to_window(data->cub.imlx, data->cub.img, 0, 0) == -1)
	{
		mlx_close_window(data->cub.imlx);
		puts(mlx_strerror(mlx_errno));
		exit(ERROR);
	}
	init_img(data);
	mlx_loop_hook(data->cub.imlx, display_img, data);
	mlx_loop_hook(data->cub.imlx, ft_hook, data);
}
