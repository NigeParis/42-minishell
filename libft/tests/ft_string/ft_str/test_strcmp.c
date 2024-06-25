/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strcmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 11:12:10 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/26 14:17:14 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int	test_strcmp(void)
{
	const char	*buffs[] = {
		"none",
		"some",
		"nonethensome",
		"nonethensome",
		"!\0a",
		"!\0b",
	};

	if (ft_strcmp(buffs[0], buffs[1]) >= 0)
		return (1);
	if (ft_strcmp(buffs[0], buffs[2]) >= 0)
		return (2);
	if (ft_strcmp(buffs[2], buffs[3]) != 0)
		return (3);
	if (ft_strcmp(buffs[4], buffs[5]) != 0)
		return (4);
	return (0);
}
