/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 13:48:11 by nrobinso          #+#    #+#             */
/*   Updated: 2024/06/24 13:36:57 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "ft_addons.h"
#include "ft_string.h"
#include "pipex.h"

#include "ft_args.h"
//#include "minishell.h"
//#include "minishell_types.h"
//#include "parser_types.h"

static void  put_exit_error(const char *progname, t_cmd_to_exec *cmd, char *msg)
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
    const char *progname = ft_progname();
	ft_putstr_fd("exit\n", STDERR_FILENO);
	if (cmd->ac > 2)
	{
		ctrl->exit = 1;
        put_exit_error(progname, cmd, ": too many arguments");
		return (1);
	}
	cmd->status = 0;
	if (cmd->ac == 2)
	{
		if (ft_str_isdigit(cmd->argv[1]) == false)
		{
			cmd->status = 1;
            put_exit_error(progname, cmd, ": numeric argument required");
			return (1);
		}
		cmd->status = ft_atoi(cmd->argv[1]);
	}
	ctrl->exit = cmd->status;
	return (ctrl->exit);
}
