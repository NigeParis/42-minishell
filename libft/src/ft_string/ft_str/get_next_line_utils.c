/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:16:01 by bgoulard          #+#    #+#             */
/*   Updated: 2023/12/06 15:13:44 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <stddef.h>

int	ft_strchr_index(const char *from, char c)
{
	int	i;

	i = 0;
	if (!from)
		return (-1);
	while (from[i] && from[i] != c)
		i++;
	if (from[i] == c)
		return (i);
	return (-1);
}

static int	mvstr(char *str, int nb, char delim)
{
	size_t	off;

	if (ft_strchr_index(str, delim) != -1)
		nb++;
	off = 0;
	while (off != BUFFER_SIZE)
	{
		if (off + nb < BUFFER_SIZE && str[off + nb])
			str[off] = str[off + nb];
		else
			str[off] = 0;
		off++;
	}
	return (0);
}

int	split_from(char **dst, char *from, int pos, char delim)
{
	char	*ret;
	size_t	or_len;
	size_t	len;
	size_t	i;

	or_len = 0;
	if (*dst)
		or_len += ft_strlen(*dst);
	len = or_len + pos + 1;
	ret = malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (-1);
	ret[len] = 0;
	i = 0;
	while (i != len)
	{
		if (i < or_len)
			ret[i] = (*dst)[i];
		else
			ret[i] = from[i - or_len];
		i++;
	}
	if (*dst)
		free(*dst);
	return (*dst = ret, (mvstr(from, pos, delim) || 0));
}
