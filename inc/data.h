#ifndef DATA_H
# define DATA_H

# define ERROR -1
# define SUCCESS 1

# define WIDTH 1200
# define HEIGHT 800

# include <stddef.h>
# include "cub.h"
# include "../MLX42/include/MLX42/MLX42.h"

typedef struct s_parse
{
	char	**map;
	float	**tabmap;
	size_t	x_max;
	size_t	y_max;
	char	*filename;
	char	**filecontent;
}				t_parse;

typedef struct s_player
{
	double	x;
	double	y;
	double	xx;
	double	yy;
	double	player_facing;
}					t_player;

typedef struct s_texture
{
	char		*path_texture_no;
	char		*path_texture_so;
	char		*path_texture_we;
	char		*path_texture_ea;
	mlx_image_t	*txt_no;
	mlx_image_t	*txt_so;
	mlx_image_t	*txt_we;
	mlx_image_t	*txt_ea;
	int			f_rgb[3];
	int			c_rgb[3];
}				t_texture;

typedef struct s_cub
{
	mlx_t			*imlx;
	mlx_image_t		*img;
}				t_cub;

typedef struct s_data
{
	t_texture	texture;
	t_parse		parse;
	t_cub		cub;
	t_player	player;
	long		width;
	char		face;
	double		wall_h;
}				t_data;

#endif