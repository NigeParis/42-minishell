/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 21:48:50 by bgoulard          #+#    #+#             */
/*   Updated: 2024/01/01 17:38:21 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <stdlib.h>

static size_t	loc_get_nbwords(const char *str, const char *delim)
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
		if (ft_strchr(delim, str[i++]))
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

static void		*loc_free_prev_words(char **words, size_t offset_words)
{
	size_t	i;

	i = 0;
	while (i < offset_words)
		free(words[i++]);
	free(words);
	return (NULL);
}

char	**ft_splits(const char *str, const char *delim)
{
	char	*str_cpy;
	char	*s;
	size_t	offset_words;
	char	**words;

	words = ft_calloc(sizeof(char *), (loc_get_nbwords(str, delim) + 1));
	if (!words)
		return (NULL);
	offset_words = 0;
	str_cpy = ft_strdup(str);
	s = ft_strtok(str_cpy, delim);
	while (s)
	{
		words[offset_words++] = ft_strdup(s);
		if (!words[offset_words - 1])
			return (loc_free_prev_words(words, offset_words), NULL);
		s = ft_strtok(NULL, delim);
	}
	free(str_cpy);
	return (words);
}
