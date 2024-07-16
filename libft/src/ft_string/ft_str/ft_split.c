/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 21:48:50 by bgoulard          #+#    #+#             */
/*   Updated: 2024/07/15 15:49:13 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

#include <stdlib.h>

static size_t	loc_get_nbwords(const char *str, char delim)
{
	size_t	ret;
	size_t	i;
	size_t	inword;

	ret = 0;
	i = 0;
	inword = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i++] == delim)
		{
			if (inword == 1)
				ret++;
			inword = 0;
		}
		else
			inword = 1;
	}
	if (inword == 1)
		ret++;
	return (ret);
}

static char	*loc_cpy_til(const char *str, char delim, size_t *offset_str)
{
	size_t	len;
	char	*ret;

	len = 0;
	while (str[*offset_str + len] != delim && str[*offset_str + len])
		len++;
	if (len == 0)
		return (NULL);
	ret = ft_calloc(sizeof(char), (len + 1));
	if (!ret)
		return (NULL);
	len = 0;
	while (str[*offset_str + len] != delim && str[*offset_str + len])
	{
		ret[len] = str[*offset_str + len];
		len++;
	}
	*offset_str += len;
	return (ret);
}

static void	loc_tbfree(void **tb, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
		free(tb[i++]);
	free(tb);
}

char	**ft_split(const char *str, char delim)
{
	size_t	offset_str;
	size_t	offset_words;
	char	**words;

	words = ft_calloc(sizeof(char *), (loc_get_nbwords(str, delim) + 1));
	if (!words)
		return (words);
	offset_words = 0;
	offset_str = 0;
	while (str && str[offset_str] == delim && delim != 0)
		offset_str++;
	while (str && str[offset_str])
	{
		words[offset_words++] = loc_cpy_til(str, delim, &offset_str);
		if (!words[offset_words - 1])
			return (loc_tbfree((void **)words, offset_words - 1), NULL);
		while (str[offset_str] == delim && str[offset_str])
			offset_str++;
	}
	return (words);
}
