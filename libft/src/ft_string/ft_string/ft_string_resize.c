/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_resize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:26:28 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/18 12:40:03 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_string_types.h"

int	ft_string_resize(t_string *str, size_t size)
{
	char	*new;

	if (size <= str->capacity)
		return (0);
	if (size % BUFFER_SIZE != 0)
		size = size + BUFFER_SIZE - (size % BUFFER_SIZE);
	new = ft_realloc(str->str, size, str->capacity);
	if (new == NULL)
		return (-1);
	str->str = new;
	str->capacity = size;
	return (0);
}
