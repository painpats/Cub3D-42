#include "../../inc/cub.h"

void	init_parse(t_parse *parse)
{
	parse->map = NULL;
	parse->filename = NULL;
	parse->filecontent = NULL;
}

void	init_player(t_player *player)
{
	player->x = -1;
	player->y = -1;
	player->xx = -1;
	player->yy = -1;
	player->player_facing = -1;
}

void	init_texture(t_texture *texture)
{
	texture->path_texture_no = NULL;
	texture->path_texture_so = NULL;
	texture->path_texture_we = NULL;
	texture->path_texture_ea = NULL;
	texture->f_rgb[0] = -1;
	texture->f_rgb[1] = -1;
	texture->f_rgb[2] = -1;
	texture->c_rgb[0] = -1;
	texture->c_rgb[1] = -1;
	texture->c_rgb[2] = -1;
}

void	init_data(t_data *data)
{
	init_parse(&data->parse);
	init_texture(&data->texture);
	init_player(&data->player);
	data->width = WIDTH;
}
