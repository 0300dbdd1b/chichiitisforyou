#ifndef BSQ_H
#define BSQ_H

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define BUFFER_SIZE 1000
#define READ_SIZE 100


typedef struct s_pos
{
	unsigned int	x;
	unsigned int	y;
} t_pos;

typedef struct s_solution
{
	t_pos	pos;
	int		size;
} t_solution;

typedef struct s_map
{
	char			empty_char;
	char			obstacle_char;
	char			full_char;
	unsigned int	width;
	unsigned int	height;
	char			*raw_map;
	char			**map;
	unsigned int	first_line_length;
	unsigned char	is_valid;
} t_map;



t_map *get_map(char *filepath);
t_map	*create_map(void);
char	*get_raw_file(char *filepath);
void	free_map(t_map *map);
int		is_printable(char c);
void	ft_putstr(char *str);
void	ft_putnbr(int nb);
void	*ft_malloc(unsigned int size);

unsigned int ft_strlen(char *str);
char	**ft_split(char *str, char *charset);
void	free_split(char **tab);
t_solution ft_bsq(t_map *map);

#endif
