/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_version.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 23:57:19 by bgoulard          #+#    #+#             */
/*   Updated: 2024/04/21 14:45:00 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_args.h"

#include <stddef.h>

static const char	*singleton_version(const char *version)
{
	static const char	*singleton_version = NULL;

	if (version)
		singleton_version = version;
	return (singleton_version);
}

void	ft_set_version(const char *version)
{
	if (version)
		singleton_version(version);
	else
		singleton_version(VERSION);
	return ;
}

const char	*ft_progversion(void)
{
	return (singleton_version(NULL));
}
