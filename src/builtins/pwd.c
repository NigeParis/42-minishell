/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 12:59:31 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/14 11:25:04 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <minishell_types.h>
#include "ft_char.h"
#include "ft_args.h"
#include "ft_string.h"
#define PATH_MAX 1024

static void	put_builtin_msg_invalid_option(const char *progname, t_cmd *cmd)
{
	ft_putstr_fd(&progname[2], STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(cmd->args[0], STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putchar_fd(cmd->args[1][0], STDERR_FILENO);
	ft_putchar_fd(cmd->args[1][1], STDERR_FILENO);
	ft_putendl_fd(": invalid option", STDERR_FILENO);
	ft_putstr_fd(cmd->args[0], STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd("usage: ", STDERR_FILENO);
	ft_putendl_fd(cmd->args[0], STDERR_FILENO);
}

char	*get_pwd(t_minishell_control *ctrl, t_cmd *cmd)
{
	const char	*progname = ft_progname();
	char		buff[PATH_MAX];
	char		*res;

	(void) ctrl;
	if ((cmd->argc > 1) && (ft_strcmp(cmd->args[1], "-") != 0) \
		&& (ft_strlen(cmd->args[1]) > 1))
	{
		if (cmd->args[1][0] != '-' || (ft_strlen(cmd->args[1]) == 2 \
			&& cmd->args[1][1] == '-'))
			;
		else
		{
			put_builtin_msg_invalid_option(progname, cmd);
			return (NULL);
		}
	}
	res = getcwd(buff, PATH_MAX);
	if (!res)
		return (NULL);
	ft_putendl_fd(res, 1);
	return (res);
}
