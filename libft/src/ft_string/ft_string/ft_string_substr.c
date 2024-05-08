/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_substr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:42:41 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/08 12:48:23 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

t_string	*ft_string_substr(t_string *str, size_t start, size_t len)
{
	t_string	*new;

	if (start > str->length)
		return (NULL);
	if (len > str->length - start)
		len = str->length - start;
	new = ft_string_new(len);
	if (new == NULL)
		return (NULL);
	if (ft_string_cap(new) != len)
		return (ft_string_destroy(&new), NULL);
	ft_memcpy(new->str, str->str + start, len);
	new->length = len - 1;
	new->str[new->length] = '\0';
	return (new);
}
