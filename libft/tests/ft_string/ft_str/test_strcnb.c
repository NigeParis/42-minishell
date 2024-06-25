/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strcnb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 10:47:58 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/30 10:48:30 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int	test_strcnb(void)
{
	if (ft_strcnb("Hello World", 'o') != 2)
		return (1);
	if (ft_strcnb("Hello World", 'z') != 0)
		return (1);
	if (ft_strcnb("Hello World", 'H') != 1)
		return (1);
	if (ft_strcnb("Hello World", 'd') != 1)
		return (1);
	if (ft_strcnb("Hello World", ' ') != 1)
		return (1);
	return (0);
}
