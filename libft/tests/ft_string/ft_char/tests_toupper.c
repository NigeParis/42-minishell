/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_toupper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 16:01:14 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/23 16:18:41 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_char.h"

static int	local_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

int	test_ft_toupper(void)
{
	int	i;

	i = 0;
	while (i < 256)
	{
		if (ft_toupper(i) != local_toupper(i))
			return (1);
		i++;
	}
	return (0);
}
