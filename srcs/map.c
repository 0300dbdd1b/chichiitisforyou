/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noaddino <noaddino@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 16:02:22 by noaddino          #+#    #+#             */
/*   Updated: 2025/02/25 16:12:51 by noaddino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

t_map	*create_map(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map) * 1);
	map->empty_char = 0;
	map->obstacle_char = 0;
	map->full_char = 0;
	map->height = 0;
	map->width = 0;
	map->raw_map = NULL;
	map->solved_map = NULL;
	map->first_line_length = 0;
	map->is_valid = 1;
	return (map);
}

void	get_map_params_from_first_line(t_map *map)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = ft_strlen_till_charset(map->raw_map, "\n");
	if (j == 3)
	{
		map->is_valid = 0;
		return ;
	}
	while (map->raw_map[i] >= '0' && map->raw_map[i] <= '9' && (i < j - 3))
	{
		map->height *= 10;
		map->height += map->raw_map[i] - 48;
		i++;
	}
	if (is_printable(map->raw_map[i]))
		map->empty_char = map->raw_map[i];
	if (is_printable(map->raw_map[i + 1]))
		map->obstacle_char = map->raw_map[i + 1];
	if (is_printable(map->raw_map[i + 2]))
		map->full_char = map->raw_map[i + 2];
	map->first_line_length = i + 2;
	map->raw_map = map->raw_map + map->first_line_length + 2;
}

t_map	*get_map(char *filepath)
{
	t_map	*map;

	map = create_map();
	map->raw_map = get_raw_file(filepath);
	get_map_params_from_first_line(map);
	map->map = ft_split(map->raw_map, "\n");
	map->is_valid = check_map(map);
	return (map);
}

void	free_map(t_map *map)
{
	unsigned int	i;

	i = 0;
	if (map->raw_map)
		free(map->raw_map);
	if (map->solved_map)
		free(map->solved_map);
	while (map->map[i])
	{
		free(map->map[i]);
		i++;
	}
	free(map->map);
}
