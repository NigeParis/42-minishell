/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fcmp_pair.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 14:40:32 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/09 18:06:41 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pair.h"

int	pair_fcmp(t_pair *pair1, t_pair *pair2, int (*f)(void *, void *))
{
	if (pair_fcmpfirst(pair1, pair2, f) && pair_fcmpsecond(pair1, pair2, f))
		return (0);
	return (1);
}

int	pair_fcmpfirst(t_pair *first, t_pair *second, int (*f)(void *, void *))
{
	if (f(first->first, second->first) == 0)
		return (0);
	return (1);
}

int	pair_fcmpsecond(t_pair *first, t_pair *second, int (*f)(void *, void *))
{
	if (f(first->second, second->second) == 0)
		return (0);
	return (1);
}
