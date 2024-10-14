#include "../../inc/cub.h"

int	fill_rgb(t_data *data, char *tmp, int *index, int id)
{
	if (id == 'C')
		data->texture.c_rgb[*index] = ft_atoi(tmp);
	else if (id == 'F')
		data->texture.f_rgb[*index] = ft_atoi(tmp);
	*index += 1;
	return (1);
}

void	check_last_arg_rgb(char *tmp, t_data *data, int count)
{
	int	i;

	i = 0;
	if (count != 3)
		return ;
	while (tmp[i] && (tmp[i] == ' ' || tmp[i] == '\t'))
		i++;
	if (tmp[i] != '\0')
		print_error_free("RGB -> Invalid parameter(s)", data);
}

void	check_rgb_parameters(char *str, t_data *data, char id)
{
	char	*tmp;
	int		check;
	int		index;
	int		count;

	index = 0;
	check = 0;
	tmp = str;
	count = 0;
	while (*tmp)
	{
		while (*tmp && *tmp != ',')
		{
			if (check++ == 0)
				count += fill_rgb(data, tmp, &index, id);
			if (!ft_isdigit(*tmp++))
				print_error_free("RGB -> Parameters must be numerics", data);
		}
		check = 0;
		check_last_arg_rgb(tmp, data, count);
		if (*(++tmp) == ',')
			print_error_free("RGB -> Invalid parameter(s)", data);
	}
	if (index != 3)
		print_error_free("RGB -> There must be three parameters", data);
}

void	check_rgb_values(t_data *data)
{
	if (data->texture.c_rgb[0] > 255 || data->texture.c_rgb[0] < 0)
		print_error_free("RGB_Ceiling -> Red is wrong", data);
	if (data->texture.c_rgb[1] > 255 || data->texture.c_rgb[1] < 0)
		print_error_free("RGB_Ceiling -> Green is wrong", data);
	if (data->texture.c_rgb[2] > 255 || data->texture.c_rgb[2] < 0)
		print_error_free("RGB_Ceiling -> Blue is wrong", data);
	if (data->texture.f_rgb[0] > 255 || data->texture.f_rgb[0] < 0)
		print_error_free("RGB_Floor -> Red is wrong", data);
	if (data->texture.f_rgb[1] > 255 || data->texture.f_rgb[1] < 0)
		print_error_free("RGB_Floor -> Green is wrong", data);
	if (data->texture.f_rgb[2] > 255 || data->texture.f_rgb[2] < 0)
		print_error_free("RGB_Floor -> Blue is wrong", data);
}

int	register_rgb(char *str, t_data *data)
{
	char	id;

	if (!ft_strncmp(str, "C", 1))
		id = 'C';
	else if (!ft_strncmp(str, "F", 1))
		id = 'F';
	str++;
	if (*str != ' ' && *str != '\t')
		print_error_free("Bad arguments !!!!!!!!!!!", data);
	while (*str && (*str == ' ' || *str == '\t'))
		str++;
	if (!ft_isdigit(*str))
		print_error_free("RGB -> Parameters must be numerics", data);
	check_rgb_parameters(str, data, id);
	ft_atoi(str);
	return (SUCCESS);
}
