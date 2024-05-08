/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_optional_chain.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 18:06:26 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/08 12:42:47 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_optional.h"
#include <stdbool.h>

bool	ft_optional_chain(t_optional *opt, void *(**f)(void *))
{
	size_t	i;

	if (!f)
		return (false);
	i = 0;
	while (f[i] && opt->pres != OPT_NONE)
	{
		opt->val = f[i](opt->val);
		if (!opt->val)
			opt->pres = OPT_NONE;
		i++;
	}
	if (opt->pres == OPT_NONE)
		return (false);
	return (true);
}

t_optional	ft_optional_map(t_optional *opt, void *(**f)(void *))
{
	t_optional	ret;

	ft_optional_copy(&ret, opt);
	if (ret.pres == OPT_NONE || !f)
		return (ret);
	ft_optional_chain(&ret, f);
	return (ret);
}
