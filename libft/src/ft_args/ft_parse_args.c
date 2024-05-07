/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 01:10:29 by bgoulard          #+#    #+#             */
/*   Updated: 2024/04/21 14:47:44 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_args.h"
#include "ft_args_types.h"
#include "ft_string.h"
#include <sys/types.h>

// better idea: since core comparaison to OPT flags are the same,
//   get parse_long_opt and parse_short_opt to return the index of the matched
//   future problem:
//     problem: can we match -n <string> and a -n <number> ?
//     technically we can already do that with the flags but we need to get the
//     string after the concerned string_option...

ssize_t	parse_long_opt(char *str_op, const t_opt *opt_list)
{
	ssize_t	i;
	size_t	offset;

	i = 0;
	if (ft_strchr(str_op, '='))
		offset = ft_strchr(str_op, '=') - str_op;
	while (opt_list[i].func)
	{
		if (opt_list[i].long_name
			&& ft_strlen(opt_list[i].long_name) >= ft_strlen(str_op)
			&& ft_strncmp(opt_list[i].long_name, str_op, ft_max(offset,
					ft_strlen(str_op))) == 0)
			return (i);
		i++;
	}
	return (-1);
}

ssize_t	parse_short_opt(char *str_op, const t_opt *opt_list)
{
	ssize_t	i;

	i = 0;
	while (opt_list[i].func)
	{
		if (opt_list[i].short_name && opt_list[i].short_name == str_op[0] == 0)
			return (i);
		i++;
	}
	return (-1);
}

void	run_opt_func(const t_opt opt, void *usr_control_struct, char *arg,
		char *arg_nxt)
{
	if (opt.type & OPT_NOARG)
		opt.func(usr_control_struct, NULL);
	else if (opt.type & OPT_NXT)
		opt.func(usr_control_struct, arg_nxt);
	else if (opt.type & OPT_EQSIGN)
		opt.func(usr_control_struct, ft_strchr(arg, '='));
}

int	ft_parse_args(int argc, char **argv, void *usr_control_struct)
{
	const t_opt	*opt;
	ssize_t		opt_index;
	int			i;

	(void)argc;
	opt = ft_get_opt_list();
	ft_set_progname(argv[0]);
	ft_set_version(VERSION);
	i = 1;
	while (argv[i] && argv[i][0] == '-')
	{
		if (argv[i][1] == '-' && argv[i][2] == '\0') // aka --\0
			return (0);
		else if (argv[i][1] == '-') // aka --XXXXX
			opt_index = parse_long_opt(argv[i] + 2, opt);
		else
			opt_index = parse_short_opt(argv[i] + 1, opt);
		if (opt_index == -1)
			return (ft_putstr_fd("Unkown option\n", 2), 1);
		// todo reference the option and prog name ft_putstrerr idk?
		run_opt_func(opt[opt_index], usr_control_struct, argv[i], argv[i + 1]);
		i += ((opt[opt_index].type & OPT_NOARG) != 0) + 1;
	}
	return (0);
}
