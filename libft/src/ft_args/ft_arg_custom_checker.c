/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_custom_checker.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:13:26 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/01 14:10:35 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_defs.h"
#include <stddef.h>

static t_data_is	singleton_custom_checker(t_data_is custom_checker)
{
	static t_data_is	custom_checker_ptr = NULL;

	if (custom_checker)
		custom_checker_ptr = custom_checker;
	return (custom_checker_ptr);
}

void	ft_arg_set_custom_checker(t_data_is custom_checker)
{
	singleton_custom_checker(custom_checker);
}

t_data_is	ft_arg_get_custom_checker(void)
{
	return (singleton_custom_checker(NULL));
}
