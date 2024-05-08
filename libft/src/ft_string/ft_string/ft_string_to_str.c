/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_to_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:47:29 by bgoulard          #+#    #+#             */
/*   Updated: 2023/12/09 17:49:12 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_string_to_str(t_string *str)
{
	char	*new;

	new = ft_calloc(str->length + 1, sizeof(char));
	if (!new)
		return (NULL);
	ft_memcpy(new, str->str, str->length);
	return (new);
}
