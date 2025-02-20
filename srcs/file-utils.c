#include "bsq.h"
#include <fcntl.h>

unsigned int get_file_size(char *filepath)
{
	int fd;
	unsigned int	x;
	unsigned int	file_size;
	char	buffer[BUFFER_SIZE];

	file_size = 0;
	x = 0;
	fd = open(filepath, O_RDONLY);
	if (fd == -1)
		return (0);
	while ((x = read(fd, buffer, BUFFER_SIZE)))
		file_size += x;
	close(fd);
	return (file_size);
}

// WARN : Dynamic Allocation there -- must check
char	*get_raw_file(char *filepath)
{
	int		fd;
	unsigned int	file_size;
	char	*raw_map_file;

	file_size = get_file_size(filepath);
	fd = open(filepath, O_RDONLY);
	if (fd == -1)
		return (0);
	raw_map_file = (char *)malloc(sizeof(char) * (file_size + 1));
	if (!raw_map_file)
		return (NULL);
	read(fd, raw_map_file, file_size);
	raw_map_file[file_size] = '\0';
	close(fd);
	return (raw_map_file);
}
