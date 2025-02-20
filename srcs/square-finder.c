#include "bsq.h"

int	check_empty(t_map *map, t_pos start, t_pos end)
{
	unsigned int	row;
	unsigned int	col;

	col = start.y;
	row = start.x;
	while (row <= end.x)
	{
		while (col <= end.y)
		{
			if (map->map[row][col] != map->empty_char)
				return (0);
			col = col + 1;
		}
		row = row + 1;
	}
	return (1);
}

t_solution find_biggest_square(t_map *map, t_pos coord)
{
	t_pos	stop;
	t_solution solution;

	stop.y = coord.y + 1;
	stop.x = coord.x + 1;
	solution.size = 1;
	solution.pos = coord;
	if (map->map[coord.y][coord.x] != map->empty_char)
		return (solution); // FIXME: CANT DO THAT ISSOU
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


t_solution ft_bsq(t_map *map)
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
	return (solution);
}
