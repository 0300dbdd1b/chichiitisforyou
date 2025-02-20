#include "bsq.h"

void	*ft_memset (void *dest, int val, size_t len)
{
  unsigned char *ptr = (unsigned char*)dest;
  while (len > 0)
  {
	  *ptr++ = val;
	  len--;
  }
  return dest;
}

t_map *create_map(void)
{
#if 0
	t_map *map;
	/*
	 * NOTE(chichi): 
	 *	Not checking NULL now?
	 */ 
	map = malloc(sizeof(t_map) * 1);
	/* 
	 * NOTE(chichi):
	 * 	Just memset bro.. It's ok.
	 */
	map->empty_char = 0;
	map->obstacle_char = 0;
	map->full_char = 0;
	map->height = 0;
	map->width = 0;
	map->raw_map = 0;
	map->first_line_length = 0;
	return (map);
#endif
	/*
	 * NOTE(chichi): stupid oneliner xd
	 */
	return ft_memset(malloc(sizeof(t_map)), 0, sizeof(t_map));
}

void	get_map_params_from_first_line(t_map *map)
{
	unsigned int	i;

	i = 0;
	while(map->raw_map[i] >= '0' && map->raw_map[i] <= '9')
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

int		check_map(t_map *map)
{
	unsigned int i;

	i = 0;
	while (map->map[i])
	{
		if (i == 0)
			map->width = ft_strlen(map->map[i]);
		else if (ft_strlen(map->map[i]) != map->width)
			return (0);
		i++;
	}
	return (1);
}

t_map *get_map(char *filepath)
{
	t_map *map = create_map();
	map->raw_map = get_raw_file(filepath);
	get_map_params_from_first_line(map);
	map->map = ft_split(map->raw_map, "\n");
	map->is_valid = check_map(map);
	return (map);
}

void	free_map(t_map *map)
{
	while (map->width)
	{
		free(map->map[map->width]);
		map->width--;
	}
	free(map->map);
}
