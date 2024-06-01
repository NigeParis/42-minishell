/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 18:16:47 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/21 17:53:50 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

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
