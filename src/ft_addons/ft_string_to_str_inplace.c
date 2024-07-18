/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_to_str_inplace.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:06:01 by bgoulard          #+#    #+#             */
/*   Updated: 2024/07/18 01:18:23 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_string_to_str_inplace(t_string **str)
{
	char	*new_str;

	new_str = ft_calloc((*str)->length + 1, sizeof(char));
	if (!new_str)
		return (NULL);
	ft_memcpy(new_str, (*str)->str, (*str)->length);
	new_str[(*str)->length] = '\0';
	ft_string_destroy(str);
	return (new_str);
}
