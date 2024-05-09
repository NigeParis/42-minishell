/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access_pair.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 14:36:07 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/09 14:36:41 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pair.h"

void	*pair_first(t_pair *pair)
{
	return (pair->first);
}

void	*pair_second(t_pair *pair)
{
	return (pair->second);
}
