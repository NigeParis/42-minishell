/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_apply_2d.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:05:28 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/31 15:59:40 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

static void	to_a(void *ptr)
{
	char	*sptr;

	sptr = (char *)ptr;
	while (*sptr)
	{
		*sptr = 'a';
		sptr++;
	}
}

int	test_apply_2d(void)
{
	char	*arr2d[4];
	size_t	i;

	i = 0;
	while (i < 3)
		arr2d[i++] = ft_strdup("Hello World");
	arr2d[i] = NULL;
	ft_apply_2d((void **)arr2d, to_a);
	if (ft_strcmp(arr2d[0], "aaaaaaaaaaa") != 0 || ft_strcmp(arr2d[1],
			"aaaaaaaaaaa") != 0 || ft_strcmp(arr2d[2], "aaaaaaaaaaa") != 0)
		return (1);
	return (ft_apply_2d((void **)arr2d, free), 0);
}
