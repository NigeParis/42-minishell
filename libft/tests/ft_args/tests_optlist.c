/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_optlist.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:52:31 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/28 15:52:33 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_args.h"
#include "ft_args_types.h"
#include <stddef.h>

static void	empty(void *ar, char *arg)
{
	(void)ar;
	(void)arg;
}

int	getset_opt_list_test(void)
{
	const t_opt	*op2 = NULL;
	const t_opt	op1[] = {
	{"--test", 't', &empty, 0},
	};

	ft_set_opt_list(op1);
	if (ft_get_opt_list() != op1)
		return (1);
	ft_set_opt_list(op2);
	if (ft_get_opt_list() != op1)
		return (2);
	return (0);
}
