/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_execute.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 13:22:15 by bgoulard          #+#    #+#             */
/*   Updated: 2024/08/14 12:33:22 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "ft_addons.h"
#include "minishell.h"
#include "minishell_types.h"
#include "parser.h"
#include "parser_types.h"
#include "ft_string.h"

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>

static int	end_it_all(t_minishell_control *shell, t_cmd_to_exec *cmd, \
			int status, int *pp_fd)
{
	print_buff(STDIN_FILENO);
	print_buff(STDOUT_FILENO);
	print_buff(STDERR_FILENO);
	if (cmd && status != 0)
		discard_cmd(cmd);
	if (pp_fd[0] != -1 || pp_fd[1] != -1)
		(close(pp_fd[0]), close(pp_fd[1]));
	return (exec_cl(shell), EXIT_SUCCESS);
}

int	dispatcher(int pid, t_minishell_control *sh, t_cmd_to_exec *cmd,
		int *p_infos)
{
	int	p_fd[2];
	int	pp_fd[2];

	set_pipe(p_fd, p_infos[0], p_infos[1]);
	set_pipe(pp_fd, p_infos[2], p_infos[3]);
	if (pid == -1)
		return (ft_perror("fork"), exec_cl(sh), EXIT_FAILURE);
	if (pid == 0)
		child_exec(sh, cmd, p_fd, (int *)pp_fd);
	else
		parent_exec(sh, cmd, pid, pp_fd);
	return (EXIT_SUCCESS);
}

void	waitpds(int pid, int status, t_minishell_control *shell)
{
	int	i;

	i = 0;
	while (i < pid)
	{
		waitpid(shell->pids[i], &status, 0);
		if (WIFEXITED(status))
			status = WEXITSTATUS(status);
		i++;
	}	
}

void	waitpid_init(int *status, int *pid, t_cmd_to_exec *cmd)
{
	*status = 0;
	*pid = 0;
	if (cmd != NULL)
		cmd->nbr_cmds = 1;
}

void	update_exe_loopbody(int **pipes_vals, t_cmd_to_exec **cmd, int *status,
		t_minishell_control *shell)
{
	int	*p_fd;
	int	*pp_fd;

	p_fd = pipes_vals[0];
	pp_fd = pipes_vals[1];
	set_pipe(pp_fd, p_fd[0], p_fd[1]);
	set_pipe(p_fd, -1, -1);
	*status = shell->exit;
	*cmd = parser_get_cmd(shell->preparsed, shell);
}

int	minishell_execute(t_minishell_control *shell)
{
	t_cmd_to_exec	*cmd;
	int				status;
	int				pp_fd[2];
	int				p_fd[2];
	int				pid;

	(set_pipe(pp_fd, -1, -1), set_pipe(p_fd, -1, -1));
	cmd = parser_get_cmd(shell->preparsed, shell);
	waitpid_init(&status, &pid, cmd);
	while (cmd && (status == 0 || status == 127))
	{
		set_pipe(p_fd, -1, -1);
		if (cmd->redir_to_do && has_pipe(cmd->redir_to_do) && pipe(p_fd) == -1)
			ft_perror("pipe"); // todo : do better aka clean up and return
		if (cmd && cmd->ac >= 1 && get_builtin(cmd->argv[0]))
			call_bin(shell, cmd);
		if ((ft_strcmp(cmd->argv[0], "exit") == 0) && (cmd->nbr_cmds == 0))
			return (end_it_all(shell, cmd, status, pp_fd));
		shell->pids[pid] = fork();
		dispatcher(shell->pids[pid++], shell, cmd, \
		(int []){p_fd[0], p_fd[1], pp_fd[0], pp_fd[1]});
		update_exe_loopbody((int *[]){p_fd, pp_fd}, &cmd, &status, shell);
	}
	return (waitpds(pid, status, shell), end_it_all(shell, cmd, status, pp_fd));
}
