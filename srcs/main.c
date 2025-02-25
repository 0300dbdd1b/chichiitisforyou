/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noaddino <noaddino@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 16:00:02 by noaddino          #+#    #+#             */
/*   Updated: 2025/02/25 16:00:33 by noaddino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	print_map_params(t_map *map)
{
	ft_putstr("(empty character) = ");
	write(1, &map->empty_char, 1);
	ft_putstr("\n(obstacle character) = ");
	write(1, &map->obstacle_char, 1);
	ft_putstr("\n(full character) = ");
	write(1, &map->full_char, 1);
	ft_putstr("\n(map height) = ");
	ft_putnbr(map->height);
	ft_putstr("\n(map width) = ");
	ft_putnbr(map->width);
	write(1, "\n", 1);
}

void	handle_stdin(void)
{
	return ;
}

int	main(int argc, char **argv)
{
	int		i;
	t_map	*map;

	i = 1;
	if (argc == 1)
		handle_stdin();
	else
	{
		while (i < argc)
		{
			map = get_map(argv[i]);
			if (!map->is_valid)
				printf("NON VALID MAP\n");
			else
				printf("VALID MAP\n");
			print_map_params(map);
			ft_bsq(map);
			i++;
		}
	}
}
