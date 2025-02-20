#include "bsq.h"

unsigned int ft_strlen(char *str)
{
	unsigned int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}
