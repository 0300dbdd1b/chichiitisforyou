#include "bsq.h"

unsigned int ft_strlen(char *str)
{
	unsigned int i;

#if 0
	/*
	 * NOTE(chichi): 
	 * 	Cringest thing you could have presented me
	 */
	if (!str)
		return (0);
#endif
	i = 0;
	while (str[i])
		i++;
	return (i);
}
