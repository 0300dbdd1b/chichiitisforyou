#include "bsq.h"
#include <stddef.h>



void	ft_exit(char *error)
{
	ft_putstr(error);
	/* 
	 * NOTE(chichi):
	 * 	`exit(0)` means no error by convention...
	 */
#if 0
	exit(0);
#endif
	exit(1);
}

void	*ft_malloc(unsigned int size)
{
	void *ptr;


	ptr = malloc(size);
	if (!ptr)
		ft_exit("malloc failed\n");

	return (ptr);
}
