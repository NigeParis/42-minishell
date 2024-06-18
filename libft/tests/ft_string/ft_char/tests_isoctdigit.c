/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_isoctdigit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 16:26:13 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/23 16:26:23 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_char.h"

static int	local_isoctdigit(int c)
{
	if (c >= '0' && c <= '7')
		return (1);
	return (0);
}

int	test_ft_isoctdigit(void)
{
	int	i;

	i = 0;
	while (i < 256)
	{
		if (ft_isoctdigit(i) != local_isoctdigit(i))
			return (1);
		i++;
	}
	return (0);
}
