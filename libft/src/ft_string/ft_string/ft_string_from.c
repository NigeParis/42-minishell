/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_from.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:14:14 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/31 10:40:27 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_math.h"

// +1 for the null terminator
t_string	*ft_string_from(const char *str)
{
	t_string	*new;
	size_t		len;

	len = ft_strlen(str);
	new = ft_string_new(len + 1);
	if (new == NULL)
		return (NULL);
	ft_memcpy(new->str, str, len + 1);
	new->length = len;
	return (new);
}

t_string	*ft_string_from_n(const char *str, size_t n)
{
	t_string	*new;

	new = ft_string_new(n + 1);
	if (new == NULL)
		return (NULL);
	if (n == 0)
		return (new);
	ft_memcpy(new->str, str, n);
	new->str[n] = '\0';
	new->length = n;
	return (new);
}

t_string	*ft_string_from_c(char c)
{
	t_string	*new;

	new = ft_string_new(2);
	if (new == NULL)
		return (NULL);
	new->str[0] = c;
	new->str[1] = '\0';
	new->length = 1;
	return (new);
}

t_string	*ft_string_from_s(const t_string *str)
{
	t_string	*new;

	new = ft_string_new(str->length + 1);
	if (new == NULL)
		return (NULL);
	ft_memcpy(new->str, str->str, str->length + 1);
	new->length = str->length;
	return (new);
}

t_string	*ft_string_from_s_n(const t_string *str, size_t n)
{
	t_string	*new;
	size_t		len;

	len = ft_min(n, str->length);
	new = ft_string_new(len + 1);
	if (new == NULL)
		return (NULL);
	ft_memcpy(new->str, str->str, len);
	new->str[len] = '\0';
	new->length = len;
	return (new);
}
