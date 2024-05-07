/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:54:49 by bgoulard          #+#    #+#             */
/*   Updated: 2023/12/04 17:43:32 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <stdlib.h>

static int	loc_getlen(unsigned long long nbr)
{
	size_t	nbr_len;

	nbr_len = 0;
	if (nbr == 0)
		return (1);
	while (nbr)
	{
		nbr_len++;
		nbr /= 10;
	}
	return (nbr_len);
}

char	*ft_utoa(unsigned int nbr)
{
	char				*ret;
	size_t				off;
	unsigned long long	srcnbr;
	const int			nbrlen = loc_getlen((unsigned long long)nbr);

	srcnbr = (unsigned long long)nbr;
	ret = ft_calloc(sizeof(char), (nbrlen + 1));
	if (!ret)
		return (NULL);
	if (srcnbr == 0)
		if (srcnbr == 0)
			ret[0] = '0';
	off = 0;
	while (srcnbr)
	{
		ret[nbrlen - ++off] = "0123456789"[srcnbr % 10];
		srcnbr /= 10;
	}
	return (ret);
}
