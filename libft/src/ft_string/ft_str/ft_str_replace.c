/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_replace.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 18:35:51 by bgoulard          #+#    #+#             */
/*   Updated: 2024/01/01 16:54:51 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_str_replace(char *str, const char *to_replace,
		const char *replace_by)
{
	char	*new_str;
	char	*ptr;
	size_t	new_len;
	size_t	to_replace_len;
	size_t	replace_by_len;

	ptr = ft_strnstr(str, to_replace, ft_strlen(str));
	if (ptr == NULL || to_replace == NULL || replace_by == NULL)
		return (NULL);
	to_replace_len = ft_strlen(to_replace);
	replace_by_len = ft_strlen(replace_by);
	new_len = ft_strlen(str) - to_replace_len + replace_by_len;
	new_str = ft_calloc(new_len + 1, sizeof(char));
	if (new_str == NULL)
		return (NULL);
	ft_memcpy(new_str, str, ptr - str);
	ft_memcpy(new_str + (ptr - str), replace_by, replace_by_len);
	ft_memcpy(new_str + (ptr - str) + replace_by_len, ptr + to_replace_len,
		ft_strlen(ptr + to_replace_len));
	return (new_str);
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
