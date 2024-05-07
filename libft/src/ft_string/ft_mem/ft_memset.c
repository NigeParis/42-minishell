/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:07:20 by bgoulard          #+#    #+#             */
/*   Updated: 2023/12/30 14:41:33 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *s, int c, size_t n)
{
	char	*casted;

	casted = (char *)s;
	if (!n)
		return (s);
	while (n--)
	{
		*casted = c;
		casted++;
	}
	return (s);
}
