#include "bsq.h"

int	check_map_params(t_map *map)
{
	if (map->empty_char == 0	||
	 	map->obstacle_char == 0 ||
	 	map->full_char	== 0)
		return (0);
	return (1);
}

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

// FIXME: Must check each allocation and free the allocated parts if malloc fails.
// Might use an allocator

int	map_allocator(int fd, t_map *map)
{
	unsigned int	i;

	i 	= 0;
	(void)fd;
	char buffer[READ_SIZE];
	read(fd, buffer, READ_SIZE);
	while (buffer[map->width] && buffer[map->width] != '\n')
		map->width++;
	map->map = ft_malloc(sizeof(char *) * map->height); while (i < map->height)
	{
		map->map[i] = ft_malloc(sizeof(char) * map->width);
		i++;
	}
	return (0);
}

void handle_stdin(void)
{
}

int main(int argc, char **argv)
{
	int i;
	t_map *map;
	t_solution solution;

	i = 1;
	if (argc == 1)
		handle_stdin();
	else
	{
		while (i < argc)
		{
			map = get_map(argv[i]);
			print_map_params(map);
			ft_putstr(map->raw_map);
			solution = ft_bsq(map);
			printf("Solution => x :%d, y :%d -- size : %d\n", solution.pos.x, solution.pos.y, solution.size);
			free_split(map->map);
			free(map);
			i++;
		}
	}
}
