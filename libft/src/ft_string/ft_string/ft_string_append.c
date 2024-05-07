/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_append.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 22:24:43 by bgoulard          #+#    #+#             */
/*   Updated: 2024/01/07 10:24:13 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int	ft_string_append(t_string *str, char *append)
{
	size_t	len;

	len = ft_strlen(append);
	if (str->length + len >= str->capacity)
	{
		if (ft_string_resize(str, str->capacity + len) == -1)
			return (-1);
	}
	ft_memcpy(str->str + str->length, append, len);
	str->length += len;
	return (0);
}

int	ft_string_append_n(t_string *str, char *append, size_t n)
{
	if (str->length + n >= str->capacity)
	{
		if (ft_string_resize(str, str->capacity + n) == -1)
			return (-1);
	}
	ft_memcpy(str->str + str->length, append, n);
	str->length += n;
	return (0);
}

int	ft_string_append_c(t_string *str, char c)
{
	if (str->length + 1 >= str->capacity)
	{
		if (ft_string_resize(str, str->capacity + 1) == -1)
			return (-1);
	}
	str->str[str->length] = c;
	str->length += 1;
	return (0);
}

int	ft_string_append_s(t_string *str, t_string *append)
{
	if (str->length + append->length >= str->capacity)
	{
		if (ft_string_resize(str, str->capacity + append->length) == -1)
			return (-1);
	}
	ft_memcpy(str->str + str->length, append->str, append->length);
	str->length += append->length;
	return (0);
}

int	ft_string_append_s_n(t_string *str, t_string *append, size_t n)
{
	if (str->length + n >= str->capacity)
	{
		if (ft_string_resize(str, str->capacity + n) == -1)
			return (-1);
	}
	ft_memcpy(str->str + str->length, append->str, n);
	str->length += n;
	return (0);
}
