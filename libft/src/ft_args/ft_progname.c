/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_progname.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 00:00:49 by bgoulard          #+#    #+#             */
/*   Updated: 2024/04/21 14:44:46 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_args.h"
#include <stddef.h>

static const char	*singleton_progname(const char *progname)
{
	static const char	*singleton_progname = NULL;

	if (progname)
		singleton_progname = progname;
	return (singleton_progname);
}

void	ft_set_progname(const char *progname)
{
	if (progname)
		singleton_progname(progname);
	else
		singleton_progname("a.out");
}

const char	*ft_progname(void)
{
	return (singleton_progname(NULL));
}
