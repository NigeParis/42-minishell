/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_from.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:14:14 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/08 12:47:45 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

// +1 for the null terminator
t_string	*ft_string_from(char *str)
{
	t_string	*new;
	size_t		len;

	len = ft_strlen(str);
	new = ft_string_new(len);
	if (new == NULL)
		return (NULL);
	ft_memcpy(new->str, str, len);
	new->length = len;
	return (new);
}

t_string	*ft_string_from_n(char *str, size_t n)
{
	t_string	*new;

	new = ft_string_new(n);
	if (new == NULL)
		return (NULL);
	if (n == 0)
		return (new);
	ft_memcpy(new->str, str, n);
	new->length = n;
	return (new);
}

t_string	*ft_string_from_c(char c)
{
	t_string	*new;

	new = ft_string_new(1);
	if (new == NULL)
		return (NULL);
	new->str[0] = c;
	new->length = 1;
	return (new);
}

t_string	*ft_string_from_s(t_string *str)
{
	t_string	*new;

	new = ft_string_new(str->length);
	if (new == NULL)
		return (NULL);
	ft_memcpy(new->str, str->str, str->length);
	new->length = str->length;
	return (new);
}

t_string	*ft_string_from_s_n(t_string *str, size_t n)
{
	t_string	*new;

	new = ft_string_new(n);
	if (new == NULL)
		return (NULL);
	ft_memcpy(new->str, str->str, n);
	new->length = n;
	return (new);
}
