/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square-finder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noaddino <noaddino@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 18:18:46 by noaddino          #+#    #+#             */
/*   Updated: 2025/02/25 15:59:45 by noaddino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	check_empty(t_map *map, t_pos start, t_pos end)
{
	unsigned int	row;
	unsigned int	col;

	row = start.y;
	while (row <= end.y)
	{
		col = start.x;
		while (col <= end.x)
		{
			if (map->map[row][col] != map->empty_char)
				return (0);
			col = col + 1;
		}
		row = row + 1;
	}
	return (1);
}

t_solution	find_biggest_square(t_map *map, t_pos coord)
{
	t_pos		stop;
	t_solution	solution;

	stop.y = coord.y + 1;
	stop.x = coord.x + 1;
	solution.size = 1;
	solution.pos = coord;
	while (stop.x <= map->width && stop.y <= map->height)
	{
		if (!check_empty(map, coord, stop))
			return (solution);
		stop.y = stop.y + 1;
		stop.x = stop.x + 1;
		solution.size++;
	}
	return (solution);
}

t_solution	ft_find_solution(t_map *map)
{
	t_solution	solution;
	t_solution	tmp_solution;
	t_pos		pos;

	pos.y = 0;
	pos.x = 0;
	solution.pos.x = 0;
	solution.pos.y = 0;
	solution.size = 0;
	while (pos.y <= map->height)
	{
		pos.x = 0;
		while (pos.x <= map->width)
		{
			tmp_solution = find_biggest_square(map, pos);
			if (tmp_solution.size > solution.size)
				solution = tmp_solution;
			pos.x++;
		}
		pos.y++;
	}
	map->solution = solution;
	return (solution);
}

void	fill_square(t_map *map, t_solution solution)
{
	unsigned int	row;
	unsigned int	col;
	unsigned int	end_x;
	unsigned int	end_y;

	end_x = solution.pos.x + solution.size - 1;
	end_y = solution.pos.y + solution.size - 1;
	row = solution.pos.y;
	while (row <= end_y)
	{
		col = solution.pos.x;
		while (col <= end_x)
		{
			map->map[row][col] = map->full_char;
			col++;
		}
		row++;
	}
}
