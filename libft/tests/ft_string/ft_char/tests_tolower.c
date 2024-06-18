/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_tolower.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 15:59:59 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/23 16:00:44 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_char.h"

static int	local_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}

int	test_ft_tolower(void)
{
	int	i;

	i = 0;
	while (i < 256)
	{
		if (ft_tolower(i) != local_tolower(i))
			return (1);
		i++;
	}
	return (0);
}
