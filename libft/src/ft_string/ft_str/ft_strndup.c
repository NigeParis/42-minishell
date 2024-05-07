/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 18:16:47 by bgoulard          #+#    #+#             */
/*   Updated: 2023/12/04 15:33:23 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <stdlib.h>

char	*ft_strndup(const char *str, size_t n)
{
	char	*ret;
	size_t	index;

	ret = ft_calloc(sizeof(char), (n + 1));
	if (!ret)
		return (ret);
	index = 0;
	while (index < n && str[index])
	{
		ret[index] = str[index];
		index++;
	}
	return (ret);
}
