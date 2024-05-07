/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_get.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:50:23 by bgoulard          #+#    #+#             */
/*   Updated: 2023/12/09 18:56:29 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

const char	*ft_string_get(t_string *str)
{
	return (str->str);
}

size_t	ft_string_length(t_string *str)
{
	return (str->length);
}

size_t	ft_string_cap(t_string *str)
{
	return (str->capacity);
}
