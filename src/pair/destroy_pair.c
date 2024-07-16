/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_pair.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 13:19:30 by bgoulard          #+#    #+#             */
/*   Updated: 2024/07/09 13:25:58 by bgoulard         ###   ########.fr       */
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
	free(pair->first);
	free(pair->second);
	free(pair);
}
