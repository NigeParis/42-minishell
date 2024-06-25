/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strncmp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 12:23:03 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/26 12:23:05 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int	test_strncmp(void)
{
	const char	*str_buffs[] = {
		"none",
		"some",
		"nonethensome",
		"nonethensome",
		"!\0a",
		"!\0b",
		NULL
	};

	if (ft_strncmp(str_buffs[0], str_buffs[1], 4) >= 0)
		return (1);
	if (ft_strncmp(str_buffs[0], str_buffs[2], 4) != 0)
		return (2);
	if (ft_strncmp(str_buffs[2], str_buffs[3], 4) != 0)
		return (3);
	if (ft_strncmp(str_buffs[4], str_buffs[5], 4) != 0)
		return (4);
	if (ft_strncmp(str_buffs[5], str_buffs[0], 0) != 0)
		return (5);
	return (0);
}
