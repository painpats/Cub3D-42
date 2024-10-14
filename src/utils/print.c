#include "../../inc/cub.h"

void	print_sstr(char **sstr)
{
	int	i;

	i = 0;
	while (sstr[i] != NULL)
	{
		ft_putstr_fd(sstr[i], 1);
		ft_putchar_fd('\n', 1);
		i++;
	}
}
