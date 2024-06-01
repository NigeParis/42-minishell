/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_replace.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 18:35:51 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/31 15:57:35 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

static bool	setup(char **res, const char *targ, size_t targ_len, size_t sub_len)
{
	char	*occurence;
	size_t	nb_occurence;

	occurence = ft_strnstr(*res, targ, ft_strlen(*res));
	nb_occurence = 0;
	while (occurence)
	{
		occurence = ft_strnstr(occurence + 1, targ, ft_strlen(occurence + 1));
		nb_occurence++;
	}
	*res = malloc(ft_strlen(*res) + (sub_len - targ_len) * nb_occurence + 1);
	if (!*res)
		return (false);
	return (true);
}

char	*ft_str_replace(const char *str, const char *target, \
					const char *substitute)
{
	char			*res;
	char			*ret;
	char			*occurence;
	const size_t	target_len = ft_strlen(target);
	const size_t	substitute_len = ft_strlen(substitute);

	occurence = ft_strnstr(str, target, ft_strlen(str));
	if (!occurence)
		return (ft_strdup(str));
	res = (char *)str;
	if (!setup(&res, target, target_len, substitute_len))
		return (NULL);
	ret = res;
	while (occurence)
	{
		ft_memcpy(res, str, occurence - str);
		res += occurence - str;
		ft_memcpy(res, substitute, substitute_len);
		res += substitute_len;
		str = occurence + target_len;
		occurence = ft_strnstr(str, target, ft_strlen(str));
	}
	return (ft_strlcpy(res, str, ft_strlen(str) + 1), ret);
}

char	*ft_str_replace_chr(char *str, char to_replace, char replace_by)
{
	char		*ptr;

	ptr = str;
	str = ft_strchr(str, to_replace);
	while (str && *str)
	{
		*str = replace_by;
		str++;
		str = ft_strchr(str, to_replace);
	}
	return (ptr);
}
