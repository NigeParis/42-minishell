/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_helper.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 17:47:15 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/01 12:48:21 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARGS_HELPER_H
# define ARGS_HELPER_H

# include "ft_args_types.h"
# include <stddef.h>
# include <sys/types.h>

// Parser opt
//
// Parse long option
ssize_t	parse_long_opt(const char *str_op, const t_opt *opt_list);
// Parse short option
ssize_t	parse_short_opt(const char *str_op, const t_opt *opt_list);

// Checker
//
// Check if the argument is valid
int		checker_arg(t_opt_type type, const char *arg);

// Run
//
// Run the function associated with the option
int		run_opt_func(const t_opt opt, void *usr_control_struct, \
		const char **arg, int *i);

// Error
//
// Print error message for option
int		arg_opt_err(const char *opt);
// Print error message for argument type
int		arg_type_err(const t_opt opt, const char *arg);

#endif
