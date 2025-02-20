#include "bsq.h"
#include <stddef.h>



void	ft_exit(char *error)
{
	ft_putstr(error);
	exit(0);
}

void	*ft_malloc(unsigned int size)
{
	void *ptr;


	ptr = malloc(size);
	if (!ptr)
		ft_exit("malloc failed\n");

	return (ptr);
}
