/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_exec_p.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 14:25:17 by bgoulard          #+#    #+#             */
/*   Updated: 2024/08/19 11:12:27 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "ft_addons.h"
#include "ft_args.h"
#include "minishell.h"

#include <signal.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

void	parent_exec(t_minishell_control *shell, t_cmd_to_exec *cmd, int pid,
		int *prev_pipe)
{
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	if (prev_pipe[1] != -1 || prev_pipe[0] != -1)
		(close(prev_pipe[0]), close(prev_pipe[1]));
	if (!(cmd->redir_to_do && has_pipe(cmd->redir_to_do)))
		waitpid(pid, &cmd->status, 0);
	if (WIFSIGNALED(cmd->status))
	{
		shell->exit = 128 + WTERMSIG(cmd->status);
		printf("%s : %d %s %s", ft_progname(), pid,
			ft_strsignal(WTERMSIG(cmd->status)), cmd->argv[0]);
		if (WCOREDUMP(cmd->status))
			printf("(core dumped)");
		printf("\n");
	}
	else
		shell->exit = WEXITSTATUS(cmd->status);
	buff_destroy_all();
	discard_cmd(cmd);
	signal_init();
}
