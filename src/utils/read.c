#include "../../inc/cub.h"

char	**read_file(int fd)
{
	char	**content_file;
	char	buff[5];
	char	*str;
	char	*tmp;
	int		size;

	size = read(fd, buff, 5);
	buff[size] = '\0';
	str = ft_strdup(buff);
	while (size)
	{
		size = read(fd, buff, 5);
		if (!size)
			break ;
		buff[size] = '\0';
		tmp = ft_strjoin(str, buff);
		str = ft_strdup(tmp);
		free(tmp);
	}
	close(fd);
	tmp = ft_strtrim(str, " \n");
	free(str);
	content_file = check_and_split(tmp);
	free(tmp);
	return (content_file);
}

int	rgbint(int red, int green, int blue, int a)
{
	return (red << 24 | green << 16 | blue << 8 | a);
}

int	check_id(char *str, int i)
{
	while (*(str + i) == '\t' || *(str + i) == ' ')
		i++;
	if (!ft_strncmp(str + i, "NO", 2) || !ft_strncmp(str + i, "SO", 2)
		|| !ft_strncmp(str + i, "WE", 2) || !ft_strncmp(str + i, "EA", 2)
		|| !ft_strncmp(str + i, "C", 1) || !ft_strncmp(str + i, "F", 1))
		return (1);
	return (0);
}

char	**check_and_split(char *str)
{
	char	**content_file;
	int		i;
	int		count;
	char	*tmp;

	count = 0;
	i = 0;
	tmp = str;
	while (*tmp)
	{
		if (*(++tmp) == '\n')
		{
			if (check_id(str, i))
				count++;
			if (count == 6)
				check_double_n(&str, &i);
			while (str[i])
				if (str[i++] == '\n')
					break ;
		}
	}
	content_file = ft_split(str, '\n');
	return (content_file);
}

void	check_double_n(char **str, int *i)
{
	char	*tmp;

	tmp = *str;
	while (tmp[*i] && tmp[*i] != '\n')
		*i += 1;
	while (tmp[*i])
	{
		if (tmp[*i] == '1' || tmp[*i] == ' ')
			break ;
		*i += 1;
	}
	while (tmp[*i])
	{
		if (tmp[*i] == '\n' && tmp[*i + 1] == '\n')
			print_error_free_str("Oioioi, bad arguments !", *str);
		*i += 1;
	}
}
