/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 11:09:02 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/26 16:37:16 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_char.h"

static int	loc_forward(const char *str, int *i)
{
	bool	neg;

	neg = false;
	*i = 0;
	while (ft_isspace(str[*i]) || str[*i] == '-' || str[*i] == '+' || \
		ft_isdigit(str[*i]))
	{
		if (str[*i] == '-')
			neg = true;
		(*i)++;
	}
	return (neg);
}

double	ft_atof(const char *str)
{
	int			whole;
	bool		neg;
	double		decimal;
	int			i;
	int			j;

	j = 1;
	decimal = 0;
	whole = ft_atoi(str);
	neg = loc_forward(str, &i);
	if (str[i] == '.')
	{
		i++;
		while (ft_isdigit(str[i]))
		{
			decimal = decimal * 10 + str[i] - '0';
			i++;
			j *= 10;
		}
	}
	if (neg == true)
		decimal *= -1;
	return ((double)whole + (double)decimal / j);
}
