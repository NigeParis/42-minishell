/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 12:59:31 by bgoulard          #+#    #+#             */
/*   Updated: 2024/07/16 12:57:36 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "ft_args.h"
#include "ft_string.h"
#include "parser_types.h"

#include <unistd.h>
#include <minishell_types.h>

static void	msg_invalid_option(t_cmd_to_exec *cmd)
{
	add_to_buff(ft_progname(), STDERR_FILENO);
	add_to_buff(": ", STDERR_FILENO);
	add_to_buff(cmd->argv[0], STDERR_FILENO);
	add_to_buff(": Does not support arguments\n", STDERR_FILENO);
}

int	pwd_main(t_minishell_control *ctrl, t_cmd_to_exec *cmd)
{
	char		buff[PATH_MAX + 1];
	char		*res;

	ft_bzero(buff, PATH_MAX + 1);
	res = getcwd(buff, PATH_MAX);
	if (cmd->ac > 1)
		return (msg_invalid_option(cmd), cmd->status = 1, EXIT_FAILURE);
	if (!res)
		return (cmd->status = 1, EXIT_FAILURE);
	add_to_buff(res, STDOUT_FILENO);
	add_to_buff("\n", STDOUT_FILENO);
	return (cmd->status = 0, EXIT_SUCCESS);
}
