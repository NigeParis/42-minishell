/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 12:59:51 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/27 16:49:20 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_args.h"
#include "ft_string.h"
#include "minishell.h"
#include "minishell_types.h"
#include "parser_types.h"

static void	put_exit_error(const char *progname, t_cmd_to_exec *cmd, char *msg)
{
	ft_putstr_fd(&progname[2], STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(cmd->argv[0], STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	//ft_putstr_fd(cmd->argv[1], STDERR_FILENO); // en trop
	ft_putendl_fd(msg, STDERR_FILENO);
}

int	exit_main(t_minishell_control *ctrl, t_cmd_to_exec *cmd)
{
	const char	*progname = ft_progname();

	ft_putstr_fd("exit\n", STDERR_FILENO);
	cmd->status = 0;
	if ((cmd->ac > 2) && (ft_str_isnum(cmd->argv[1]) == true))
	{
		cmd->status = 0;
		put_exit_error(progname, cmd, ": too many arguments");
		ctrl->exit = 0;
		return (1);
	}
	if (cmd->ac >= 2)
	{
		if (ft_str_isnum(cmd->argv[1]) == false)
		{
			cmd->status = 1;
			put_exit_error(progname, cmd, ": numeric argument required");
			return (ctrl->exit = 2, ctrl->exit);
		}
		else if ((ft_strcmp(cmd->argv[1], "1") == 0) && (cmd->ac == 2))
			return (cmd->status = 1, ctrl->exit = 1, 1);
		cmd->status = ft_atoi(cmd->argv[1]);
	}
	ctrl->exit = cmd->status;
	return (ctrl->exit);
}
