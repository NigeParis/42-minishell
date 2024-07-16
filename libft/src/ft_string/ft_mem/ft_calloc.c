/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 20:28:30 by bgoulard          #+#    #+#             */
/*   Updated: 2024/07/16 12:58:24 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

#include <limits.h>
#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t weight)
{
	const size_t	tot = nmemb * weight;
	void			*ret;

	if (tot && tot / weight != nmemb)
		return (NULL);
	ret = malloc(tot);
	if (!ret)
		return (NULL);
	return (ft_memset(ret, 0, tot));
}
