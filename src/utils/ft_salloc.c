#include "../../inc/cub.h"

void	*ft_salloc(size_t lines, size_t lenght)
{
	void	*p;

	if (lines >= 65535 && lenght >= 65535)
		return (NULL);
	p = (void *)malloc(lines * lenght);
	if (p == NULL)
		return (NULL);
	ft_bzero(p, (lines * lenght));
	p = ft_memset(p, ' ', lenght - 1);
	return (p);
}
