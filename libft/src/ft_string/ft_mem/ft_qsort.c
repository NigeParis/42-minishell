/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 11:31:15 by bgoulard          #+#    #+#             */
/*   Updated: 2023/12/30 12:37:00 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

void	ft_qsort(void *array, size_t nmb, size_t size, \
	int (*cmp)(const void *, const void *))
{
	size_t	i;
	size_t	j;
	size_t	pivot;

	if (nmb < 2)
		return ;
	i = 0;
	j = nmb - 1;
	pivot = nmb / 2;
	while (i < j)
	{
		while (cmp(array + (i * size), array + (pivot * size)) < 0)
			i++;
		while (cmp(array + (j * size), array + (pivot * size)) > 0)
			j--;
		if (i < j)
		{
			ft_swap(array + (i * size), array + (j * size));
			if (i == pivot || j == pivot)
				pivot = (i == pivot) * i + (j == pivot) * j;
		}
	}
	ft_qsort(array, pivot, size, cmp);
	ft_qsort(array + ((pivot + 1) * size), nmb - pivot - 1, size, cmp);
}
