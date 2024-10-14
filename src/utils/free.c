#include "../../inc/cub.h"

void	free_sstr(char **sstr)
{
	int	i;

	i = 0;
	while (sstr[i] != NULL)
	{
		free(sstr[i]);
		i++;
	}
	free(sstr);
	sstr = NULL;
}

void	free_all(t_data *data)
{
	free_sstr(data->parse.filecontent);
	free_sstr(data->parse.map);
}
