#include "../../inc/cub.h"

int	len_sstr(char **sstr)
{
	int	i;

	i = 0;
	while (sstr[i] != NULL)
		i++;
	return (i);
}

size_t	len_longest_line(char **sstr)
{
	int		i;
	size_t	len_line;

	len_line = 0;
	i = 0;
	while (sstr[i] != NULL)
	{
		if (ft_strlen(sstr[i]) > len_line)
			len_line = ft_strlen(sstr[i]);
		i++;
	}
	return (len_line);
}
