/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_optional_dup.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 22:30:28 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/23 22:32:45 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_optional.h"
#include "ft_optional_types.h"

int	test_optional_dup(void)
{
	t_optional	opt_a;
	t_optional	*opt_b;

	opt_a.pres = OPT_SOME;
	opt_a.val = (void *)42;
	opt_b = ft_optional_dup(&opt_a);
	if (opt_b == NULL)
		return (1);
	if (opt_b->pres != OPT_SOME)
		return (2);
	if (opt_b->val != (void *)42)
		return (3);
	opt_b->pres = OPT_NONE;
	ft_optional_destroy(opt_b);
	return (0);
}
