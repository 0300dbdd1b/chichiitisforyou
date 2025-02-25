/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noaddino <noaddino@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:53:54 by noaddino          #+#    #+#             */
/*   Updated: 2025/02/25 16:07:33 by noaddino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	ft_bsq(t_map *map)
{
	t_solution	solution;

	solution = ft_find_solution(map);
	fill_square(map, solution);
	map->solved_map = ft_strjoin(map->height, map->map, "\n");
	ft_putstr(map->solved_map);
	free_map(map);
	return (0);
}
