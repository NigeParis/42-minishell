/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_round.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 23:24:56 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/23 23:25:46 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

int	test_ft_round(void)
{
	double	x;

	x = 42.42;
	if (ft_round(x) != 42)
		return (1);
	x = 42.52;
	if (ft_round(x) != 43)
		return (1);
	x = 42.499;
	if (ft_round(x) != 42)
		return (1);
	x = 42.5;
	if (ft_round(x) != 43)
		return (1);
	return (0);
}
