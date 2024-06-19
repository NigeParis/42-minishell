/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 13:48:11 by nrobinso          #+#    #+#             */
/*   Updated: 2024/06/19 14:22:01 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "ft_addons.h"
#include "ft_string.h"
#include "pipex.h"

static void  put_exit_error(const char *progname, t_cmd *cmd, char *msg)
{
    ft_putstr_fd(&progname[2], STDERR_FILENO);
    ft_putstr_fd(": ", STDERR_FILENO);
    ft_putstr_fd(cmd->args[0], STDERR_FILENO);
    ft_putstr_fd(": ", STDERR_FILENO);
    ft_putstr_fd(cmd->args[1], STDERR_FILENO);
    ft_putendl_fd(msg, STDERR_FILENO);    
}

int	exit_main(t_minishell_control *ctrl, t_cmd *cmd)
{
    const char *progname = ft_progname();
	ft_putstr_fd("exit\n", STDERR_FILENO);
	if (cmd->argc > 2)
	{
		ctrl->exit = 1;
        put_exit_error(progname, cmd, ": too many arguments");
		return (1);
	}
	cmd->ret = 0;
	if (cmd->argc == 2)
	{
		if (ft_str_isdigit(cmd->args[1]) == false)
		{
			cmd->ret = 1;
            put_exit_error(progname, cmd, ": numeric argument required");
			return (1);
		}
		cmd->ret = ft_atoi(cmd->args[1]);
	}
	ctrl->exit = cmd->ret;
	return (ctrl->exit);
}
