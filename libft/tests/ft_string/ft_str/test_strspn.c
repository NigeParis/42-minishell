/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strspn.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 10:48:32 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/30 11:05:30 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int	test_strspn(void)
{
	if (ft_strspn("Hello World", "o") != 0)
		return (1);
	if (ft_strspn("Hello World", "z") != 0)
		return (1);
	if (ft_strspn("Hello World", "H") != 1)
		return (1);
	if (ft_strspn("Hello World", "d") != 0)
		return (1);
	if (ft_strspn("Hello World", "Helo Wrd") != 11)
		return (1);
	return (0);
}
