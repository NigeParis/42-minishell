/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 20:05:24 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/21 17:36:45 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_char.h"

int	ft_atoi(const char *str)
{
	int		ret;
	int		sign;
	size_t	offset;

	ret = 0;
	offset = 0;
	sign = 0;
	while (ft_isspace(str[offset]))
		offset++;
	while (str[offset] == '+' || str[offset] == '-')
	{
		if (str[offset] == '-')
			sign++;
		offset++;
	}
	while (ft_isdigit(str[offset]))
		ret = ret * 10 + str[offset++] - '0';
	if (sign % 2 == 1)
		return (-ret);
	return (ret);
}
