/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 20:55:53 by bgoulard          #+#    #+#             */
/*   Updated: 2023/12/05 10:27:52 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	tot;
	size_t	off;
	char	*ret;

	tot = 0;
	if (s1)
		tot += ft_strlen(s1);
	if (s2)
		tot += ft_strlen(s2);
	ret = ft_calloc(sizeof(char), (tot + 1));
	if (ret == NULL)
		return (NULL);
	off = 0;
	tot = 0;
	while (s1 && s1[off])
	{
		ret[off] = s1[off];
		off++;
	}
	while (s2 && s2[tot])
		ret[off++] = s2[tot++];
	return (ret);
}
