/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strcspn.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 10:48:32 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/30 11:03:55 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int	test_strcspn(void)
{
	if (ft_strcspn("Hello World", "o") != 4)
		return (1);
	if (ft_strcspn("Hello World", "z") != 11)
		return (1);
	if (ft_strcspn("Hello World", "H") != 0)
		return (1);
	if (ft_strcspn("Hello World", "d") != 10)
		return (1);
	if (ft_strcspn("Hello World", " ") != 5)
		return (1);
	return (0);
}
