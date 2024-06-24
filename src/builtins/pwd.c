/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 12:59:31 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/24 12:45:09 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <minishell_types.h>
#include "ft_char.h"
#include "ft_args.h"
#include "ft_string.h"
#include "parser_types.h"
#define PATH_MAX 1024

static void	put_builtin_msg_invalid_option(const char *progname, t_cmd_to_exec *cmd)
{
	ft_putstr_fd(&progname[2], STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(cmd->argv[0], STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putchar_fd(cmd->argv[1][0], STDERR_FILENO);
	ft_putchar_fd(cmd->argv[1][1], STDERR_FILENO);
	ft_putendl_fd(": invalid option", STDERR_FILENO);
	ft_putstr_fd(cmd->argv[0], STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd("usage: ", STDERR_FILENO);
	ft_putendl_fd(cmd->argv[0], STDERR_FILENO);
}

int	pwd_main(t_minishell_control *ctrl, t_cmd_to_exec *cmd)
{
	const char	*progname = ft_progname();
	char		buff[PATH_MAX];
	char		*res;

	(void) ctrl;
	if ((cmd->ac > 1) && (ft_strcmp(cmd->argv[1], "-") != 0) \
		&& (ft_strlen(cmd->argv[1]) > 1))
	{
		if (cmd->argv[1][0] != '-' || (ft_strlen(cmd->argv[1]) == 2 \
			&& cmd->argv[1][1] == '-'))
			;
		else
		{
			put_builtin_msg_invalid_option(progname, cmd);
			return (cmd->status = 1, EXIT_FAILURE);
		}
	}
	res = getcwd(buff, PATH_MAX);
	if (!res)
		return (cmd->status = 1, EXIT_FAILURE);
	ft_putendl_fd(res, 1);
	return (cmd->status = 0, EXIT_SUCCESS);
}
