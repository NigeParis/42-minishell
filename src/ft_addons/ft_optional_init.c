/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_optional_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 08:29:46 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/22 08:30:51 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_optional_types.h"

void	ft_optional_init(t_optional *opt_ptr, const void *v)
{
	opt_ptr->val = (void *)v;
	if (v == NULL)
		opt_ptr->pres = OPT_NONE;
	else
		opt_ptr->pres = OPT_SOME;
	return ;
}
