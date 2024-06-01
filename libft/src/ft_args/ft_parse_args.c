/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 01:10:29 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/01 12:49:22 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_args.h"
#include "ft_args_types.h"
#include "ft_string.h"
#include "internal/args_helper.h"
#include <stdlib.h>
#include <sys/types.h>
#include <stdbool.h>

int	run_opt_func(const t_opt opt, void *usr_control_struct, const char **arg, \
				int *i)
{
	const char	*arg_ptr;
	void		(*func_arg)(void *, const char *);
	void		(*func_no_arg)(void *);

	func_arg = opt.func;
	func_no_arg = opt.func;
	if (opt.type & OPT_ARG && opt.type & OPT_EQSIGN)
		arg_ptr = ft_strchr(arg[*i], '=') + 1;
	else if (opt.type & OPT_ARG)
		arg_ptr = arg[*i + 1];
	else
		arg_ptr = NULL;
	if (checker_arg(opt.type, arg_ptr) != 0)
		return (arg_type_err(opt, arg_ptr));
	if (opt.type & OPT_ARG)
		func_arg(usr_control_struct, arg_ptr);
	else
		func_no_arg(usr_control_struct);
	*i += 1 + ((opt.type != 0) && (opt.type & OPT_EQSIGN) == 0);
	return (EXIT_SUCCESS);
}

int	ft_parse_args(const char **argv, void *usr_control_struct)
{
	const t_opt	*opt;
	ssize_t		opt_index;
	int			i;

	opt = ft_get_opt_list();
	i = 1;
	while (argv[i] && argv[i][0] == '-')
	{
		if (argv[i][1] == '-' && argv[i][2] == '\0')
			return (EXIT_SUCCESS);
		else if (argv[i][1] == '-')
			opt_index = parse_long_opt(argv[i] + 2, opt);
		else
			opt_index = parse_short_opt(argv[i] + 1, opt);
		if (opt_index == -1)
			return (arg_opt_err(argv[i]));
		if (run_opt_func(opt[opt_index], usr_control_struct, argv, &i) != 0)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
