/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_isint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:47:57 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/31 18:29:16 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_char.h"
#include "ft_string.h"
#include <stdbool.h>

// 0 success, !0 failure
bool	ft_str_isint(const char *str)
{
	size_t	i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (false);
		i++;
	}
	if ((i == 10 && ft_strcmp(str, "2147483647") > 0) || (i == 11
			&& ft_strcmp(str, "-2147483648") > 0) || i > 11)
		return (false);
	if (i == 0 || (i == 1 && (str[0] == '-')))
		return (false);
	return (true);
}
