/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 20:28:30 by bgoulard          #+#    #+#             */
/*   Updated: 2023/12/05 10:21:52 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdlib.h>
#include "ft_string.h"

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
