/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_free_2d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 23:42:53 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/28 23:55:41 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

// we assume that free_2d is working,
// checking if memory is freed properly is not possible in this context
int	test_free_2d(void)
{
	char	**tab;

	tab = ft_split("Hello World", ' ');
	ft_free_2d((void **)tab);
	return (0);
}
