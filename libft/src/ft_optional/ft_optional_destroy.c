/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_optional_destroy.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 18:06:49 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/18 15:39:13 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_optional.h"
#include <stdbool.h>
#include <stdlib.h>

bool	ft_optional_destroy(t_optional *opt)
{
	if (!opt)
		return (false);
	if (opt->pres == OPT_NONE)
		return (free(opt), true);
	return (false);
}
