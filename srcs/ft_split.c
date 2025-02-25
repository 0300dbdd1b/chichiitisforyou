/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noaddino <noaddino@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:35:00 by noaddino          #+#    #+#             */
/*   Updated: 2025/02/17 15:45:20 by noaddino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	is_in_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	count_words(char *str, char *charset)
{
	int	i;
	int	word_count;

	i = 0;
	word_count = 0;
	while (str[i])
	{
		if (!is_in_charset(str[i], charset) && \
			is_in_charset(str[i - 1], charset))
			word_count++;
		i++;
	}
	if (!is_in_charset(str[0], charset))
		word_count++;
	return (word_count);
}

int	get_word(char **dest, char *str, char *charset)
{
	int	i;
	int	j;
	int	src_len;

	i = 0;
	j = 0;
	src_len = 0;
	while (str[i] && is_in_charset(str[i], charset))
		i++;
	while (str[src_len + i] && !is_in_charset(str[src_len + i], charset))
		src_len++;
	*dest = (char *)malloc(sizeof(char) * (src_len + 1));
	if (!*dest)
		return (0);
	while (str[i] && !is_in_charset(str[i], charset))
	{
		(*dest)[j] = str[i];
		i++;
		j++;
	}
	(*dest)[i] = '\0';
	return (i + 1);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		offset;
	char	**tab;
	int		word_count;

	if (!str || !charset)
		return (NULL);
	i = 0;
	offset = 0;
	word_count = count_words(str, charset);
	tab = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!tab)
		return (NULL);
	while (i < word_count)
	{
		offset = get_word(&tab[i], str, charset);
		if (!offset)
			tab[i] = NULL;
		str += offset;
		i++;
	}
	tab[i] = (char *)0;
	return (tab);
}
