/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ishexdigit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 16:25:47 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/23 16:26:01 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_char.h"

static int	local_ishexdigit(int c)
{
	if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'f')
		|| (c >= 'A' && c <= 'F'))
		return (1);
	return (0);
}

int	test_ft_ishexdigit(void)
{
	int	i;

	i = 0;
	while (i < 256)
	{
		if (ft_ishexdigit(i) != local_ishexdigit(i))
			return (1);
		i++;
	}
	return (0);
}
