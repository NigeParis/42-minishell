/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_log.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 23:42:03 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/24 09:27:55 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

int	test_ft_log(void)
{
	int	x;

	x = 23;
	if (ft_log(x) != 1)
		return (1);
	x = 0;
	if (ft_log(x) != -1)
		return (2);
	x = 1;
	if (ft_log(x) != 0)
		return (3);
	x = 420;
	if (ft_log(x) != 2)
		return (4);
	x = -12;
	if (ft_log(x) != -1)
		return (5);
	return (0);
}

int	test_ft_llogof(void)
{
	if (ft_llogof(0, 2) != -1)
		return (1);
	if (ft_llogof(1, 2) != 0)
		return (2);
	if (ft_llogof(2, 2) != 1)
		return (3);
	if (ft_llogof(8, 2) != 3)
		return (4);
	if (ft_llogof(23, 3) != 2)
		return (5);
	return (0);
}

int	test_ft_ullogof(void)
{
	if (ft_ullogof(0, 2) != -1)
		return (1);
	if (ft_ullogof(1, 2) != 0)
		return (2);
	if (ft_ullogof(2, 2) != 1)
		return (3);
	return (0);
}

int	test_ft_logof(void)
{
	if (ft_logof(0, 2) != -1)
		return (1);
	if (ft_logof(1, 2) != 0)
		return (2);
	if (ft_logof(2, 2) != 1)
		return (3);
	if (ft_logof(8, 2) != 3)
		return (4);
	return (0);
}
