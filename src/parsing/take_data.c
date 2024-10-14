#include "../../inc/cub.h"

void	take_data(t_data *data)
{
	if (!take_rgb(data))
		print_error_free("Something's wrong with the color(s)", data);
	if (!take_texture(data))
		print_error_free("Something's wrong with the texture(s)", data);
}

int	take_rgb(t_data *data)
{
	int	i;

	i = 0;
	while (data->parse.filecontent[i])
	{
		if (ft_strncmp(data->parse.filecontent[i], "C", 1) == 0)
			register_rgb(data->parse.filecontent[i], data);
		else if (ft_strncmp(data->parse.filecontent[i], "F", 1) == 0)
			register_rgb(data->parse.filecontent[i], data);
		i++;
	}
	check_rgb_values(data);
	return (SUCCESS);
}

void	check_error_data(t_data *data)
{
	if (data->texture.path_texture_ea == NULL
		|| data->texture.path_texture_no == NULL
		|| data->texture.path_texture_so == NULL
		|| data->texture.path_texture_we == NULL
		|| data->texture.path_texture_no == NULL)
		print_error_free("Something's wrong with the texture(s)", data);
	if (data->texture.c_rgb[0] == -1 || data->texture.c_rgb[1] == -1
		|| data->texture.c_rgb[2] == -1 || data->texture.f_rgb[0] == -1
		|| data->texture.f_rgb[1] == -1 || data->texture.f_rgb[2] == -1)
		print_error_free("Something's wrong with the color(s)", data);
}

int	take_texture(t_data *data)
{
	int	i;

	i = 0;
	while (data->parse.filecontent[i])
	{
		if (ft_strncmp(data->parse.filecontent[i], "NO", 2) == 0)
			register_texture(data->parse.filecontent[i], data, "NO");
		else if (ft_strncmp(data->parse.filecontent[i], "SO", 2) == 0)
			register_texture(data->parse.filecontent[i], data, "SO");
		else if (ft_strncmp(data->parse.filecontent[i], "WE", 2) == 0)
			register_texture(data->parse.filecontent[i], data, "WE");
		else if (ft_strncmp(data->parse.filecontent[i], "EA", 2) == 0)
			register_texture(data->parse.filecontent[i], data, "EA");
		i++;
	}
	check_error_data(data);
	return (SUCCESS);
}
