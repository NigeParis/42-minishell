/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_str_isbool.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 08:22:20 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/29 15:00:22 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int	test_str_isbool(void)
{
	if (ft_str_isbool("1") != 1 || ft_str_isbool("true") != 1)
		return (1);
	if (ft_str_isbool("0") != 1 || ft_str_isbool("false") != 1)
		return (2);
	if (ft_str_isbool("true!") != 0)
		return (3);
	if (ft_str_isbool("falseeurt") != 0)
		return (4);
	if (ft_str_isbool("truetrue") != 0)
		return (5);
	if (ft_str_isbool("false42") != 0)
		return (6);
	if (ft_str_isbool("false\t") != 0)
		return (7);
	if (ft_str_isbool("") != 0)
		return (8);
	return (0);
}
