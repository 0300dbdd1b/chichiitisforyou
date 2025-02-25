/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file-utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noaddino <noaddino@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:43:41 by noaddino          #+#    #+#             */
/*   Updated: 2025/02/25 15:44:57 by noaddino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <fcntl.h>

unsigned int	get_file_size(char *filepath)
{
	int				fd;
	long			x;
	unsigned int	file_size;
	char			buffer[BUFFER_SIZE];

	file_size = 0;
	x = 1;
	fd = open(filepath, O_RDONLY);
	if (fd == -1)
		return (0);
	while (x)
	{
		x = read(fd, buffer, BUFFER_SIZE);
		if (x < 0)
			return (0);
		file_size += x;
	}
	close(fd);
	return (file_size);
}

// WARN : Dynamic Allocation there -- must check
char	*get_raw_file(char *filepath)
{
	int				fd;
	long			x;
	unsigned int	file_size;
	char			*raw_map_file;

	file_size = get_file_size(filepath);
	printf("FILE SIZE : %d\n", file_size);
	fd = open(filepath, O_RDONLY);
	if (fd == -1)
		return (0);
	raw_map_file = (char *)malloc(sizeof(char) * (file_size + 1));
	if (!raw_map_file)
		return (NULL);
	x = read(fd, raw_map_file, file_size);
	if (x < 0)
		return (NULL);
	raw_map_file[file_size] = '\0';
	close(fd);
	return (raw_map_file);
}
