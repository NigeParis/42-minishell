/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 09:39:40 by bgoulard          #+#    #+#             */
/*   Updated: 2023/12/04 15:33:02 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_string.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*ret;
	unsigned int	index;

	index = 0;
	if (!f || !s)
		return (NULL);
	ret = ft_calloc(sizeof(char), (ft_strlen(s) + 1));
	if (!ret)
		return (ret);
	while (s[index++])
		ret[index - 1] = f(index - 1, s[index - 1]);
	return (ret);
}
