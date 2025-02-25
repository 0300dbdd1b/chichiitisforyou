/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map-checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noaddino <noaddino@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 16:01:32 by noaddino          #+#    #+#             */
/*   Updated: 2025/02/25 16:07:07 by noaddino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	check_map_params(t_map *map)
{
	if (!map->empty_char || !map->obstacle_char || !map->full_char)
		return (0);
	else if (map->empty_char == map->full_char)
		return (0);
	else if (map->obstacle_char == map->full_char)
		return (0);
	else if (map->obstacle_char == map->empty_char)
		return (0);
	return (1);
}

int	check_map_size(t_map *map)
{
	unsigned int	i;

	i = 0;
	while (i < map->height)
	{
		if (i == 0)
			map->width = ft_strlen(map->map[i]);
		else if (ft_strlen(map->map[i]) != map->width)
			return (0);
		i++;
	}
	return (1);
}

int	check_map_characters(t_map *map)
{
	unsigned int	i;

	i = 0;
	while (map->raw_map[i])
	{
		if (map->raw_map[i] == map->obstacle_char)
			i++;
		else if (map->raw_map[i] == map->empty_char)
			i++;
		else if (map->raw_map[i] == map->full_char)
			i++;
		else if (map->raw_map[i] == '\n')
			i++;
		else
			return (0);
	}
	return (1);
}

int	check_map(t_map *map)
{
	if (!check_map_size(map))
		map->is_valid = 0;
	if (!check_map_params(map))
		map->is_valid = 0;
	if (!check_map_characters(map))
		map->is_valid = 0;
	return (map->is_valid);
}
