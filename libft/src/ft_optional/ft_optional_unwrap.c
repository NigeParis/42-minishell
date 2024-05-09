/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_optional_unwrap.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 18:07:00 by bgoulard          #+#    #+#             */
/*   Updated: 2024/01/07 14:06:15 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_optional.h"

void *ft_optional_unwrap(t_optional opt)
{
	char *explose;

	explose = NULL;
	if (opt.pres != OPT_NONE)
		return (opt.val);
	explose[42] = explose[0];
	return (opt.val);
}

