/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strend_with.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:05:34 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/18 20:05:12 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int	ft_strend_with(const char *str, const char *end)
{
	int	i;
	int	j;

	i = ft_strlen(str) - 1;
	j = ft_strlen(end) - 1;
	if (j > i)
		return (0);
	while (j >= 0)
	{
		if (str[i] != end[j])
			return (0);
		i--;
		j--;
	}
	return (1);
}
