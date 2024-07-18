/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_pair.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 13:19:30 by bgoulard          #+#    #+#             */
/*   Updated: 2024/07/18 02:09:28 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pair.h"

#include <stdlib.h>

void	destroy_pair(t_pair *pair)
{
	free(pair);
}

void	destroy_pair_deep(t_pair *pair)
{
	if (pair == NULL)
		return ;
	if (pair->first)
		free(pair->first);
	if (pair->second)
		free(pair->second);
	free(pair);
}
