/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strappend_c.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 12:02:19 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/10 12:04:14 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strappend_c(char **str, char c)
{
	size_t	len;

	if (!str)
		return (NULL);
	len = 0;
	if (*str)
		len = ft_strlen(*str);
	*str = ft_realloc(*str, len + 2, len);
	if (!*str)
		return (NULL);
	(*str)[len] = c;
	(*str)[len + 1] = '\0';
	return (*str);
}
