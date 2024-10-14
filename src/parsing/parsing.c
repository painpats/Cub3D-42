#include "../../inc/cub.h"

int	check_open_files(char *file)
{
	int	fd;

	fd = open(file, O_DIRECTORY);
	if (fd != -1)
	{
		close(fd);
		print_error("Something's wrong with the file");
	}
	fd = open(file, O_RDONLY);
	if (fd == -1)
		print_error("Something's wrong with the file");
	return (fd);
}

void	check_ext(char *files_name, char *ext)
{
	int	i_file;
	int	i_ext;

	i_file = ft_strlen(files_name) - 1;
	i_ext = ft_strlen(ext) - 1;
	if (i_file <= i_ext)
		print_error("Something's wrong with the extension");
	while (i_file >= 0 && i_ext >= 0)
	{
		if (files_name[i_file] == ext[i_ext])
		{
			i_file--;
			i_ext--;
		}
		else if (files_name[i_file] != ext[i_ext])
			print_error("Something's wrong with the extension");
	}
}

int	check_map(char **content_file)
{
	int		i;
	int		check;
	char	*tmp;

	i = -1;
	check = 0;
	while (content_file[++i])
	{
		tmp = ft_strtrim(content_file[i], " \t");
		free(content_file[i]);
		content_file[i] = tmp;
		check = checkif_textures(content_file[i], i);
		if (check == ERROR)
			print_error_free_sstr("Something's wrong with file", content_file);
		else if (check == SUCCESS)
			break ;
	}
	while (content_file[++i])
		if (check_charinmap(content_file[i]) == ERROR)
			print_error_free_sstr("Map : invalid character(s)", content_file);
	return (0);
}

int	check_charinmap(char *content_map)
{
	int			i;
	static int	check_p;

	i = -1;
	while (content_map[++i])
	{
		if (content_map[i] != ' ' && content_map[i] != '1'
			&& content_map[i] != '0' && content_map[i] != '2'
			&& content_map[i] != 'N' && content_map[i] != 'S'
			&& content_map[i] != 'E' && content_map[i] != 'W')
			return (ERROR);
		if (content_map[i] == '\n' && content_map[i + 1] == '\0')
			return (ERROR);
		if (content_map[i] == 'N' || content_map[i] == 'S'
			|| content_map[i] == 'W' || content_map[i] == 'E')
			check_p++;
	}
	if (check_p > 1)
		return (ERROR);
	return (SUCCESS);
}
