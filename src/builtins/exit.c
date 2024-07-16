/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 12:59:51 by bgoulard          #+#    #+#             */
/*   Updated: 2024/07/16 11:43:04 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "ft_args.h"
#include "ft_char.h"
#include "ft_string.h"
#include "minishell_types.h"
#include "parser_types.h"
#include <stdio.h>

// todo: move to ft_addons
static long	ft_atol(const char *str)
{
	long	n;
	int		sign;

	n = 0;
	sign = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
		sign += *str++ == '-';
	while (ft_isdigit(*str))
		n = n * 10 + (*str++ - '0');
	if (sign)
		return (-n);
	return (n);
}

static void	print_err(t_cmd_to_exec *cmd, char *msg)
{
	add_to_buff(ft_progname(), STDERR_FILENO);
	add_to_buff(": exit :", STDERR_FILENO);
	add_to_buff(cmd->argv[1], STDERR_FILENO);
	add_to_buff(msg, STDERR_FILENO);
	add_to_buff("\n", STDERR_FILENO);
}

int	exit_main(t_minishell_control *ctrl, t_cmd_to_exec *cmd)
{
	long		user_input;

	if (cmd->ac > 2)
	{
		if (ft_str_islong(cmd->argv[1]) == false)
		{
			ctrl->shoulcontinue = false;
			return (print_err(cmd, ": numeric argument required"), \
			cmd->status = 2, 2);
		}
		return (print_err(cmd, ": too many arguments"), cmd->status = 1, 1);
	}
	ctrl->shoulcontinue = false;
	user_input = ctrl->exit;
	if (cmd->ac == 2)
	{
		if (ft_str_islong(cmd->argv[1]) == false)
			return (print_err(cmd, ": numeric argument required"), \
			cmd->status = 2, 2);
		user_input = ft_atol(cmd->argv[1]);
	}
	while (user_input < 0)
		user_input += 256;
	user_input %= 256;
	return (cmd->status = user_input, user_input);
}
