#include "../../inc/cub.h"

int	check_case(char c)
{
	if (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (SUCCESS);
	return (0);
}

int	check_case_wall(char c)
{
	if (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W'
		|| c == '1')
		return (SUCCESS);
	return (0);
}
