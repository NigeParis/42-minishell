/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_optional_new.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 18:06:55 by bgoulard          #+#    #+#             */
/*   Updated: 2024/08/16 14:03:49 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_optional.h"

#include <stdlib.h>

t_optional	*ft_optional_new(void)
{
	t_optional	*elem;

	elem = malloc(sizeof(*elem));
	if (!elem)
		return (NULL);
	elem->pres = OPT_NONE;
	elem->val = NULL;
	return (elem);
}

t_optional	*ft_optional_from_val(void *ptr)
{
	t_optional	*elem;

	elem = ft_optional_new();
	if (!elem)
		return (elem);
	elem->pres = OPT_SOME;
	elem->val = ptr;
	return (elem);
}

// As this function can fail it should never be called,
// the type t_optional is supposed to be ultra reliable.
// Carefull use is preconized.
t_optional	*ft_optional_dup(t_optional *org)
{
	t_optional	*ret;

	ret = ft_optional_new();
	if (!ret)
		return (NULL);
	ft_optional_copy(ret, org);
	return (ret);
}
