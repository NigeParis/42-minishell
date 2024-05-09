/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmp_pair.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 14:38:55 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/09 14:55:25 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pair.h"

static int	cmp_ptrs(void *ptr1, void *ptr2)
{
	if (ptr1 == ptr2)
		return (0);
	return (1);
}

int	pair_cmp(t_pair *pair1, t_pair *pair2)
{
	if (pair_cmpfirst(pair1, pair2) && pair_cmpsecond(pair1, pair2))
		return (0);
	return (1);
}

int	pair_cmpfirst(t_pair *first, t_pair *second)
{
	if (pair_fcmpfirst(first->first, second->first, cmp_ptrs) == 0)
		return (0);
	return (1);
}

int	pair_cmpsecond(t_pair *first, t_pair *second)
{
	if (pair_fcmpsecond(first->second, second->second, cmp_ptrs) == 0)
		return (0);
	return (1);
}
