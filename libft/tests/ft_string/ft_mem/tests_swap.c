/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 12:20:29 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/25 15:13:47 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

/*
	// ignore warning for memset args
	#pragma clang diagnostic pop
*/

int	test_swap(void)
{
	const int	pair_og[2] = {1, 2};
	const int	*pair[2];
	const int	*pair2[2] = {&pair_og[1], &pair_og[0]};

	pair[0] = &pair_og[0];
	pair[1] = &pair_og[1];
	ft_swap((void **)&pair[0], (void **)&pair[1]);
	if (pair[0] != pair2[0] || pair[1] != pair2[1])
		return (1);
	return (0);
}
