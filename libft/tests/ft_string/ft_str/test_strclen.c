/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strclen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 10:47:16 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/30 11:05:38 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int	test_strclen(void)
{
	if (ft_strclen("Hello World", 'o') != 4)
		return (1);
	if (ft_strclen("Hello World", 'z') != 11)
		return (1);
	if (ft_strclen("Hello World", 'H') != 0)
		return (1);
	if (ft_strclen("Hello World", 'd') != 10)
		return (1);
	if (ft_strclen("Hello World", ' ') != 5)
		return (1);
	return (0);
}
