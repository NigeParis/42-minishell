/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 23:02:45 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/10 09:11:18 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

size_t	ft_strcspn(const char *str, const char *charset)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (ft_strchr(charset, str[i]))
			return (i);
		i++;
	}
	return (i);
}
