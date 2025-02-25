/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdlib-utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noaddino <noaddino@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:54:39 by noaddino          #+#    #+#             */
/*   Updated: 2025/02/25 16:11:23 by noaddino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

unsigned int	ft_strlen_till_charset(char *str, char *charset)
{
	unsigned int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && !is_in_charset(str[i], charset))
		i++;
	return (i);
}
