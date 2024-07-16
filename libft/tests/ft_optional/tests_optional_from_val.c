/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_optional_from_val.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 22:30:45 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/23 22:32:41 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_optional.h"
#include "ft_optional_types.h"

#include <stdlib.h>

int	test_optional_from_val(void)
{
	int			*ptr;
	t_optional	*opt;

	ptr = malloc(sizeof(int));
	*ptr = 42;
	opt = ft_optional_from_val(ptr);
	if (opt == NULL)
		return (1);
	if (opt->pres != OPT_SOME)
		return (2);
	if (opt->val != ptr)
		return (3);
	opt->pres = OPT_NONE;
	ft_optional_destroy(opt);
	free(ptr);
	return (0);
}
