/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_version.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 22:37:13 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/23 22:38:27 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_args.h"
#include "ft_string.h"

#include <unistd.h>

int	getset_version_test(void)
{
	char	*s1;
	char	*s2;

	s1 = "toto";
	s2 = 0;
	ft_set_version(s1);
	if (ft_progversion() != s1)
		return (ft_putstr_fd(ft_progversion(), STDERR_FILENO), 1);
	ft_set_version(s2);
	if (ft_progversion() == s2)
		return (2);
	return (0);
}
