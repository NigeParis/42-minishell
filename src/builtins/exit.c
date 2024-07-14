/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 12:59:51 by bgoulard          #+#    #+#             */
/*   Updated: 2024/07/14 10:30:46 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_args.h"
#include "ft_char.h"
#include "ft_string.h"
#include "minishell_types.h"
#include "parser_types.h"

static long	ft_atol(const char *str)
{
	long	n;
	int		sign;

	n = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
		sign = *str++ == '-';
	while (ft_isdigit(*str))
		n = n * 10 + (*str++ - '0');
	return (n * sign);
}

static void	put_exit_error(const char *progname, t_cmd_to_exec *cmd, char *msg)
{
	ft_putstr_fd(&progname[2], STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(cmd->argv[0], STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(cmd->argv[1], STDERR_FILENO);
	ft_putendl_fd(msg, STDERR_FILENO);
}

int	exit_main(t_minishell_control *ctrl, t_cmd_to_exec *cmd)
{
	const char	*progname = ft_progname();
	long		user_input;

	ft_putstr_fd("exit\n", STDERR_FILENO);
	if (cmd->ac > 2)
	{
		ctrl->shoulcontinue = true;
		put_exit_error(progname, cmd, ": too many arguments");
		return (cmd->status = 1, 1);
	}
	ctrl->shoulcontinue = false;
	cmd->status = ctrl->exit;
	user_input = ctrl->exit;
	if (cmd->ac == 2)
	{
		if (ft_str_islong(cmd->argv[1]) == false)
		{
			put_exit_error(progname, cmd, ": numeric argument required");
			return (cmd->status = 1, 1);
		}
		user_input = ft_atol(cmd->argv[1]);
	}
	if (user_input < 0)
		user_input += 256;
	cmd->status = user_input % 256;
	ctrl->exit = cmd->status;
	return (cmd->status);
}
