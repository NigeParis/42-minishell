/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_resize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:26:28 by bgoulard          #+#    #+#             */
/*   Updated: 2024/01/05 02:46:13 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int	ft_string_resize(t_string *str, size_t size)
{
	char	*new;

	new = ft_realloc(str->str, size, str->capacity);
	if (new == NULL)
		return (-1);
	str->str = new;
	str->capacity = size;
	return (0);
}
