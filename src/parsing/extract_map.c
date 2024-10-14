#include "../../inc/cub.h"

char	**get_map_cub(char **map)
{
	char	**map_cub;
	size_t	size_sstr;
	size_t	len_str;
	size_t	i;

	i = 0;
	len_str = 0;
	size_sstr = len_sstr(map);
	map_cub = ft_calloc(sizeof(map_cub), size_sstr + 1);
	len_str = len_longest_line(map);
	while (i < size_sstr)
	{
		map_cub[i] = ft_salloc(sizeof(char *), len_str + 1);
		ft_strcpy_woz(&map_cub[i], map[i]);
		i++;
	}
	return (map_cub);
}

char	**get_map(char **file)
{
	int		i;
	int		check;

	i = -1;
	check = 0;
	while (file[++i])
	{
		check = get_itextures(file[i], i);
		if (check == 1)
		{
			i++;
			break ;
		}
	}
	return (file + i);
}
