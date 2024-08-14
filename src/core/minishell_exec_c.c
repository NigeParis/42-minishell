/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_exec_c.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 14:23:27 by bgoulard          #+#    #+#             */
/*   Updated: 2024/08/14 09:23:04 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "ft_addons.h"
#include "ft_args.h"
#include "ft_list.h"
#include "ft_string.h"
#include "minishell.h"
#include "parser_types.h"
#include <errno.h>
#include <signal.h>
#include <sys/stat.h>
#include <unistd.h>

void	dd_cl(t_cmd_to_exec *cmd, t_minishell_control *shell, int code)
{
	destroy_buff(STDIN_FILENO);
	destroy_buff(STDOUT_FILENO);
	destroy_buff(STDERR_FILENO);
	discard_cmd(cmd);
	minishell_cleanup(shell);
}

static void	perr_cmd(t_cmd_to_exec *cmd, const char *msg)
{
	ft_putstr_fd(ft_progname(), STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(cmd->argv[0], STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(msg, STDERR_FILENO);
	if (msg[ft_strlen(msg) - 1] != '\n')
		ft_putstr_fd("\n", STDERR_FILENO);
}

static void	real_cmd(t_cmd_to_exec *cmd, t_minishell_control *shell, int *pp_fd,
		int *p_fd)
{
	struct stat	statbuf;

	if (cmd->cmd_path == NULL)
	{
		perr_cmd(cmd, "command not found\n");
		if (pp_fd[0] != -1 || pp_fd[1] != -1)
			(close(pp_fd[0]), close(pp_fd[1]));
		if (p_fd[0] != -1 || p_fd[1] != -1)
			(close(p_fd[0]), close(p_fd[1]));
		(discard_cmd(cmd), exec_cl(shell), minishell_cleanup(shell), exit(127));
	}
	if (stat(cmd->cmd_path, &statbuf) == 0 && S_ISDIR(statbuf.st_mode))
	{
		perr_cmd(cmd, "is a directory\n");
		(discard_cmd(cmd), exec_cl(shell), minishell_cleanup(shell), exit(126));
	}
	ft_ll_clear(&cmd->redir_to_do, free_rdr_node);
	execve(cmd->cmd_path, cmd->argv, cmd->env);
	perr_cmd(cmd, ft_strerror(errno));
	(discard_cmd(cmd), exec_cl(shell), minishell_cleanup(shell), exit(127));
}

void	child_exec(t_minishell_control *shell, t_cmd_to_exec *cmd,
		int *p_fd, int *pp_fd)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	if (cmd->redir_to_do && has_heredoc(cmd->redir_to_do))
		do_hdoc_cmd(cmd, shell);
	if (p_fd[STDOUT_FILENO] != -1)
		(dup2(p_fd[1], STDOUT_FILENO), close(p_fd[1]), close(p_fd[0]));
	if (pp_fd[0] != -1)
	{
		if (has_heredoc(cmd->redir_to_do) == false)
			dup2(pp_fd[0], STDIN_FILENO);
		(close(pp_fd[0]), close(pp_fd[1]));
	}
	if (cmd->redir_to_do && do_rdr_list(cmd->redir_to_do) == EXIT_FAILURE)
		dd_cl(cmd, shell, 1);
	if (cmd && cmd->ac >= 1 && get_builtin(cmd->argv[0]))
	{
		buff_print_all();
		///TODO no leaks if this is deactivated - need to see with baptiste ??
		// dd_cl(cmd, shell, cmd->status);
		exit(cmd->status);
	}
	return (real_cmd(cmd, shell, pp_fd, p_fd));
}
