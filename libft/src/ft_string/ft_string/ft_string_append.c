/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_append.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 22:24:43 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/31 11:04:08 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int	ft_string_append(t_string *str, char *append)
{
	size_t	len;

	len = ft_strlen(append) + 1;
	if (str->length + len >= str->capacity)
	{
		if (ft_string_resize(str, str->capacity + len) == -1)
			return (-1);
	}
	ft_memcpy(str->str + str->length, append, len);
	str->length += len - 1;
	return (0);
}

int	ft_string_append_n(t_string *str, char *append, size_t n)
{
	if (str->length + n + 1 >= str->capacity)
	{
		if (ft_string_resize(str, str->capacity + n + 1) == -1)
			return (-1);
	}
	ft_memcpy(str->str + str->length, append, n);
	str->length += n;
	str->str[str->length] = '\0';
	return (0);
}

int	ft_string_append_c(t_string *str, char c)
{
	if (str->length + 2 >= str->capacity)
	{
		if (ft_string_resize(str, str->capacity + 2) == -1)
			return (-1);
	}
	str->str[str->length] = c;
	str->str[str->length + 1] = '\0';
	str->length += 1;
	return (0);
}

int	ft_string_append_s(t_string *str, t_string *append)
{
	if (str->length + append->length + 1 >= str->capacity)
	{
		if (ft_string_resize(str, str->capacity + append->length + 1) == -1)
			return (-1);
	}
	ft_memcpy(str->str + str->length, append->str, append->length + 1);
	str->length += append->length;
	str->str[str->length] = '\0';
	return (0);
}

int	ft_string_append_s_n(t_string *str, t_string *append, size_t n)
{
	if (str->length + n + 1 >= str->capacity)
	{
		if (ft_string_resize(str, str->capacity + n + 1) == -1)
			return (-1);
	}
	ft_memcpy(str->str + str->length, append->str, n);
	str->length += n;
	str->str[str->length] = '\0';
	return (0);
}
