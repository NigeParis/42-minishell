/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_setup_prog.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:55:09 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/28 16:04:22 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_args.h"
#include "ft_string.h"

int	tests_setup_prog(void)
{
	const char	*argv[] = {"dummy_prog", "--test", NULL};

	ft_setup_prog(argv);
	if (ft_progname() != argv[0])
		return (1);
	if (ft_strcmp(ft_progversion(), VERSION) != 0)
		return (2);
	return (0);
}
