/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_isfloat.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:45:19 by bgoulard          #+#    #+#             */
/*   Updated: 2024/07/16 12:59:28 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_char.h"

#include <stddef.h>
#include <stdbool.h>

// no value check like isint due to the fact that it's a floating point
bool	ft_str_isfloat(const char *str)
{
	size_t	i;
	bool	dot;

	i = 0;
	dot = false;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] == '.' && !dot)
			dot = true;
		else if (!ft_isdigit(str[i]))
			return (false);
		i++;
	}
	if (i == 0 || (i == 1 && (str[0] == '.' || str[0] == '-')) || \
	(i == 2 && str[0] == '-' && str[1] == '.') || \
	i > 20)
		return (false);
	return (true);
}
