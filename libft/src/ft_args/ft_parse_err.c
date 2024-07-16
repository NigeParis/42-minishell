/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_err.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:23:49 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/31 18:22:04 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_args_types.h"
#include "ft_args.h"
#include "ft_char.h"
#include "ft_string.h"

#include <unistd.h>
#include <stdlib.h>

// 0 success, !0 failure
int	checker_arg(t_opt_type type, const char *arg)
{
	if (!arg || arg == (char *)0x1)
		return (type);
	if ((type & ARG_MASK_ATYPE) == OPT_INT)
		return (!ft_str_isint(arg));
	else if ((type & ARG_MASK_ATYPE) == OPT_STRING)
		return (EXIT_SUCCESS);
	else if ((type & ARG_MASK_ATYPE) == OPT_BOOL)
		return (!ft_str_isbool(arg));
	else if ((type & ARG_MASK_ATYPE) == OPT_FLOAT)
		return (!ft_str_isfloat(arg));
	else if ((type & ARG_MASK_ATYPE) == OPT_LONG)
		return (!ft_str_islong(arg));
	else if ((type & ARG_MASK_ATYPE) == OPT_DOUBLE)
		return (!ft_str_isdouble(arg));
	else if ((type & ARG_MASK_ATYPE) == OPT_ALPHANUM)
		return (!ft_str_isvalid(arg, ft_isalnum));
	else if ((type & ARG_MASK_ATYPE) == OPT_HEX)
		return (!ft_str_ishex(arg));
	else if ((type & ARG_MASK_ATYPE) == OPT_OCT)
		return (!ft_str_isoct(arg));
	else if ((type & ARG_MASK_ATYPE) == OPT_OTHER
		&& ft_arg_get_custom_checker())
		return (!ft_arg_get_custom_checker()(arg));
	return (EXIT_SUCCESS);
}

int	arg_type_err(t_opt opt, const char *arg)
{
	const char	*progname;

	progname = ft_progname();
	if (progname)
	{
		ft_putstr_fd(progname, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
	}
	ft_putstr_fd("Error: invalid argument for option: ", STDERR_FILENO);
	if (opt.long_name)
		ft_putstr_fd(opt.long_name, STDERR_FILENO);
	else
		ft_putchar_fd(opt.short_name, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	if (!arg || arg == (char *)1)
		ft_putstr_fd("NULL", STDERR_FILENO);
	else
		ft_putstr_fd(arg, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	return (EXIT_FAILURE);
}

int	arg_opt_err(const char *arg)
{
	const char	*progname;

	progname = ft_progname();
	if (progname)
	{
		ft_putstr_fd(progname, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
	}
	ft_putstr_fd("Error: invalid option: ", STDERR_FILENO);
	ft_putstr_fd(arg, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	return (EXIT_FAILURE);
}
