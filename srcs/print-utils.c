#include "bsq.h"

int	is_printable(char c)
{
	if (!c)
		return (0);
	if (!(c <= 127 && c >= 32))
		return (0);
	return (1);
}

void	ft_putstr(char *str)
{
	unsigned int i;

	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
}

void	ft_putnbr(int nb)
{
	long long int	nb_cpy;
	char			c;

	nb_cpy = nb;
	if (nb_cpy < 0)
	{
		write(1, "-", 1);
		nb_cpy = nb_cpy * (-1);
	}
	if (nb_cpy >= 10)
	{
		ft_putnbr(nb_cpy / 10);
		ft_putnbr(nb_cpy % 10);
	}
	else
	{
		c = nb_cpy + '0';
		write(1, &c, 1);
	}
}

