/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strstart_with.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 10:49:38 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/30 10:49:51 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int	test_strstart_with(void)
{
	if (ft_strstart_with("Hello World", "Hello") != 1)
		return (1);
	if (ft_strstart_with("Hello World", "Hello!") != 0)
		return (1);
	if (ft_strstart_with("Hello World", "World") != 0)
		return (1);
	if (ft_strstart_with("Hello World", "Hello World") != 1)
		return (1);
	if (ft_strstart_with("Hello World", "Hello World!") != 0)
		return (1);
	return (0);
}
