#include "../../inc/cub.h"

int	checkif_textures(char *content_file, int i)
{
	static int	tab_register[6];
	int			i_tab;

	i_tab = -1;
	if (ft_strncmp(content_file, "NO", 2) == 0
		|| ft_strncmp(content_file, "SO", 2) == 0
		|| ft_strncmp(content_file, "WE", 2) == 0
		|| ft_strncmp(content_file, "EA", 2) == 0
		|| ft_strncmp(content_file, "C", 1) == 0
		|| ft_strncmp(content_file, "F", 1) == 0)
	{
		if (tab_register[i] == 1)
			return (ERROR);
		tab_register[i] = 1;
	}
	else
		return (ERROR);
	if (i == 5)
	{
		while (++i_tab < 6)
			if (tab_register[i_tab] == 0)
				return (ERROR);
		return (SUCCESS);
	}
	return (0);
}

int	get_itextures(char *content_file, int i)
{
	static int	tab_register[6];
	int			index;

	index = -1;
	if (ft_strncmp(content_file, "NO", 2) == 0
		|| ft_strncmp(content_file, "SO", 2) == 0
		|| ft_strncmp(content_file, "WE", 2) == 0
		|| ft_strncmp(content_file, "EA", 2) == 0
		|| ft_strncmp(content_file, "C", 1) == 0
		|| ft_strncmp(content_file, "F", 1) == 0)
	{
		if (tab_register[i] == 1)
			return (-1);
		tab_register[i] = 1;
	}
	else
		return (-1);
	if (i == 5)
	{
		while (++index < 6)
			if (tab_register[index] == 0)
				return (-1);
		return (1);
	}
	return (0);
}

void	register_texture(char *str, t_data *data, char *cardinal_point)
{
	int	fd;

	str += 2;
	if (*str != ' ' && *str != '\t')
		print_error_free("There must be a space or \\t after texture(s)", data);
	while (*str && (*str == ' ' || *str == '\t'))
		str++;
	fd = open_file(str);
	if (fd == -1)
		print_error_free("Something's wrong with the texture(s)", data);
	if (ft_strncmp(cardinal_point, "NO", 2) == 0)
		data->texture.path_texture_no = str;
	else if (ft_strncmp(cardinal_point, "SO", 2) == 0)
		data->texture.path_texture_so = str;
	else if (ft_strncmp(cardinal_point, "WE", 2) == 0)
		data->texture.path_texture_we = str;
	else if (ft_strncmp(cardinal_point, "EA", 2) == 0)
		data->texture.path_texture_ea = str;
	close(fd);
}
