/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_optional_destroy.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 22:30:05 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/23 22:32:48 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_optional.h"
#include "ft_optional_types.h"

int	test_optional_destroy(void)
{
	t_optional	*opt_a;

	opt_a = ft_optional_new();
	opt_a->val = (void *)42;
	opt_a->pres = OPT_SOME;
	if (ft_optional_destroy(opt_a) != false)
		return (1);
	if (opt_a->pres != OPT_SOME)
		return (2);
	if (opt_a->val != (void *)42)
		return (3);
	opt_a->pres = OPT_NONE;
	if (ft_optional_destroy(opt_a) != true)
		return (4);
	if (ft_optional_destroy(NULL) != false)
		return (5);
	return (0);
}
