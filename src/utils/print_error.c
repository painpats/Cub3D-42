#include "../../inc/cub.h"

void	print_error(char *str)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(str, 2);
	exit (EXIT_FAILURE);
}

void	print_error_free_str(char *str, char *clean)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(str, 2);
	free(clean);
	exit (EXIT_FAILURE);
}

void	print_error_free_sstr(char *str, char **content)
{
	free_sstr(content);
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(str, 2);
	exit (EXIT_FAILURE);
}
