#include "bsq.h"

int	is_printable(char c)
{
#if 0
	/* NOTE(chichi): Why do you even check this ? */
	if (!c) 
		return (0);
    /*
	 * NOTE(chichi): 
	 *	Triggers warning on clang since it is 
	 *	always true (it's a `char` ...).
	 *	Also it's weird to do it this way
     */
	if (!(c <= 127 && c >= 32))
		return (0);
#endif
	if (c < 127 && c >= 32)
		return (1);
	return (0);
}

static inline size_t lol_strlen(char* str)
{
	size_t i;

	i = 0;
	while (str[i])
		i++;
	return i;
}

void	ft_putstr(char *str)
{
#if 0
	unsigned int i;

	i = 0;
	/* NOTE(chichi): 
	 * 	Why aren't you checking for NULL ?
	 * 	(monkey's logic).
	 */
	while (str[i])
		i++;
	/* NOTE(chichi): 
	 * 	Following these monkeys logic you check the
	 *	value of write (you can fuck people over)
	 */
	write(1, str, i);
#endif
	write(1, str, lol_strlen(str));
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
