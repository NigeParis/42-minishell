/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_pair.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 14:29:37 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/09 14:36:55 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pair.h"
#include <stdlib.h>

t_pair	*new_pair(void *first, void *second)
{
	t_pair	*pair;

	pair = (t_pair *)malloc(sizeof(t_pair));
	if (!pair)
		return (NULL);
	pair->first = first;
	pair->second = second;
	return (pair);
}
