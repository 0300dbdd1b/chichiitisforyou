#include "bsq.h"

int	ft_strslen(int count, char **strs)
{
	int	i;
	int	total_len;

	i = 0;
	total_len = 0;
	while (i < count)
	{
		total_len += ft_strlen(strs[i]);
		i++;
	}
	return (total_len);
}

char	*ft_strcat(char *dest, char *src)
{
	unsigned int	dest_length;
	unsigned int	i;

	i = 0;
	if (!dest || !src)
		return (0);
	dest_length = ft_strlen(dest);
	while (src[i])
	{
		dest[dest_length + i] = src[i];
		i++;
	}
	dest[dest_length + i] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*str;
	int		total_strs_len;
	int		i;

	if (!size)
		return ((char *)malloc(sizeof(char) * 0));
	total_strs_len = ft_strslen(size, strs) + (size * ft_strlen(sep));
	str = (char*)malloc(sizeof(char) * total_strs_len);
	i = 0;
	while (i < size)
	{
		ft_strcat(str, strs[i]);
		if (i != size - 1)
			ft_strcat(str, sep);
		i++;
	}
	return (str);
}
