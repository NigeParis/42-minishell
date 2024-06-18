/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_custom_checker.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 18:15:10 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/01 14:28:04 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_args.h"

static bool	loc_checker(const void *arg)
{
	const char	*str = (const char *)arg;

	if (str[0] == 'a')
		return (true);
	return (false);
}

int	getset_custom_checker_test(void)
{
	ft_arg_set_custom_checker(loc_checker);
	if (ft_arg_get_custom_checker() != loc_checker)
		return (-1);
	return (0);
}
