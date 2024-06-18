/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_progname.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 22:37:47 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/23 22:38:23 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_args.h"
#include "ft_string.h"

int	getset_program_name_test(void)
{
	char	*s1;
	char	*s2;

	s1 = "toto";
	s2 = 0;
	ft_set_progname(s1);
	if (ft_progname() != s1)
		return (ft_putstr_fd(ft_progname(), 2), 1);
	ft_set_progname(s2);
	if (ft_progname() == s2)
		return (2);
	return (0);
}
