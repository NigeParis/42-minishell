/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_chr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:51:16 by bgoulard          #+#    #+#             */
/*   Updated: 2023/12/09 19:39:57 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_string_chr(t_string *str, char c)
{
	size_t	i;

	i = 0;
	while (i < str->length)
	{
		if (str->str[i] == c)
			return (str->str + i);
		i++;
	}
	if (c == '\0')
		return (str->str + i);
	return (NULL);
}

char	*ft_string_rchr(t_string *str, char c)
{
	size_t	i;

	i = str->length;
	while (i > 0)
	{
		if (str->str[i] == c)
			return (str->str + i);
		i--;
	}
	if (i == 0 && str->str[i] == c)
		return (str->str + i);
	return (NULL);
}

size_t	ft_string_offset(t_string *str, char c)
{
	char	*ptr;

	ptr = ft_string_chr(str, c);
	if (ptr)
		return (ptr - str->str);
	return (-1);
}

size_t	ft_string_roffset(t_string *str, char c)
{
	char	*ptr;

	ptr = ft_string_rchr(str, c);
	if (ptr)
		return (ptr - str->str);
	return (-1);
}
