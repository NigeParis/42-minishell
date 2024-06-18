/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lambdas_for_tests.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 11:08:37 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/29 00:03:50 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>

void	**creat_tb(void)
{
	static int	a;
	static int	b;
	static int	c;
	static int	*tab[3] = {0};

	a = 42;
	b = 43;
	c = 44;
	tab[0] = &a;
	tab[1] = &b;
	tab[2] = &c;
	return ((void **)tab);
}

void	add42(void *data)
{
	int	*ptr;

	ptr = (int *)data;
	*ptr += 42;
}

bool	is42(const void *data)
{
	if (!data)
		return (false);
	return (*(int *)data == 42);
}

void	*add42_ret(const void *data)
{
	int	*ret;

	ret = malloc(sizeof(int));
	*ret = *(int *)data;
	*ret += 42;
	return ((void *)ret);
}

int	cmp_int(const void *a, const void *b)
{
	return (*(int *)a - *(int *)b);
}
