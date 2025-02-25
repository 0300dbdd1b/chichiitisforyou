/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noaddino <noaddino@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:54:03 by noaddino          #+#    #+#             */
/*   Updated: 2025/02/25 15:54:04 by noaddino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	ft_fill_memory(char *memory, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		memory[i] = 0;
		i++;
	}
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*str;
	int		total_strs_len;
	int		i;

	if (!size)
	{
		str = (char *)malloc(sizeof(char) * 1);
		str[0] = '\0';
		return (str);
	}
	total_strs_len = ft_strslen(size, strs) + ((size - 1) * ft_strlen(sep));
	str = (char *)malloc(sizeof(char) * total_strs_len + 1);
	ft_fill_memory(str, total_strs_len + 1);
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
