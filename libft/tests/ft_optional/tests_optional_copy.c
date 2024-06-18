/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_optional_copy.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 22:29:49 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/30 12:08:07 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_optional.h"
#include "ft_optional_types.h"
#include <stdlib.h>

int	test_optional_copy(void)
{
	int			*ptr;
	t_optional	opt_a;
	t_optional	opt_b;

	ptr = malloc(sizeof(int));
	*ptr = 42;
	opt_a.pres = OPT_SOME;
	opt_a.val = ptr;
	ft_optional_copy(&opt_b, &opt_a);
	if (opt_b.pres != OPT_SOME)
		return (1);
	if (*(int *)opt_b.val != 42)
		return (2);
	free(ptr);
	return (0);
}
