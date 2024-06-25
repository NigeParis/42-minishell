/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strend_with.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 10:49:13 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/30 10:49:34 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int	test_strend_with(void)
{
	if (ft_strend_with("Hello World", "World") != 1)
		return (1);
	if (ft_strend_with("Hello World", "World!") != 0)
		return (1);
	if (ft_strend_with("Hello World", "Hello") != 0)
		return (1);
	if (ft_strend_with("Hello World", "Hello World") != 1)
		return (1);
	if (ft_strend_with("Hello World", "Hello World!") != 0)
		return (1);
	return (0);
}
