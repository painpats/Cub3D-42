#include "../../inc/cub.h"

void	ft_strcpy_woz(char **str, char *cpy)
{
	int		i;
	char	*tmp;

	tmp = *str;
	i = 0;
	while (cpy[i])
	{
		tmp[i] = cpy[i];
		i++;
	}
}
