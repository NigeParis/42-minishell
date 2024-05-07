/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:03:11 by bgoulard          #+#    #+#             */
/*   Updated: 2023/12/31 17:48:51 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <stdlib.h>

static int	ft_is_valid(const char *base)
{
	int	i;
	int	j;

	i = 0;
	if (ft_strlen(base) < 2)
		return (0);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || ft_isspace(base[i]))
			return (0);
		j = i + 1;
		while (base[j])
			if (base[i] == base[j++])
				return (0);
		i++;
	}
	return (1);
}

static int	loc_getlen(long long nbr, int blen)
{
	size_t	nbr_len;

	nbr_len = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
	{
		nbr *= -1;
		nbr_len++;
	}
	nbr_len += ft_llogof(nbr, blen) + 1;
	return (nbr_len);
}

char	*ft_itoa_base(int nbr, const char *base)
{
	char		*ret;
	size_t		off;
	long long	srcnbr;
	const int	blen = ft_strlen(base);
	const int	nbrlen = loc_getlen((long long)nbr, blen);

	srcnbr = (long long)nbr;
	if (!ft_is_valid(base))
		return (NULL);
	ret = ft_calloc(sizeof(char), (nbrlen + 1));
	if (!ret)
		return (NULL);
	if (srcnbr <= 0)
	{
		ret[0] = (srcnbr == 0) * '0' + (srcnbr < 0) * '-';
		srcnbr *= -1;
	}
	off = 0;
	while (srcnbr)
	{
		ret[nbrlen - ++off] = base[srcnbr % blen];
		srcnbr /= blen;
	}
	return (ret);
}
