/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_reserve.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:26:02 by bgoulard          #+#    #+#             */
/*   Updated: 2023/12/30 12:27:08 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int	ft_string_reserve(t_string *str, size_t size)
{
	char	*new;

	if (size <= str->capacity)
		return (0);
	new = ft_realloc(str->str, str->capacity, size);
	if (!new)
		return (-1);
	str->str = new;
	str->capacity = size;
	return (0);
}
