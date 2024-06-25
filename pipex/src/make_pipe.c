/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 11:54:14 by nrobinso          #+#    #+#             */
/*   Updated: 2024/06/25 09:10:03 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <signal.h>

int make_pipe(t_pipex *pipex, t_cmd_to_exec *argv, t_redir *redir)
{
	int ret;
	if (!argv->status)
	{
		signal(SIGQUIT, backslash_handler);
    	signal(SIGINT, Ctrl_C_child_handler);   /* Ctrl-c handler*/

	}
	ret = pipe(pipex->pipe_fd);
	if (ret < 0)
		perror("pipe");

	pipex->child_pid = fork();
	if (pipex->child_pid == -1)
		perror("fork");
	
	if (!pipex->child_pid)
	{
		
		child_process(pipex, argv, redir);
	}
	else
	{	
		parent_process(pipex, redir, argv);
	}
	return (0);
}

void child_process(t_pipex *pipex, t_cmd_to_exec *argv, t_redir *redir)
{
	close(pipex->pipe_fd[0]);
	if (argv->lastcmd_index == FIRST_CMD)
	{
		dup2(pipex->pipe_fd[1], STDOUT_FILENO);
		if (redir->flag && redir->redir_type == RDIR_FILE)
		{
			dup2(pipex->fdin, STDIN_FILENO);
			close_fd(&pipex->fdin);
		}
	}
	else if (argv->lastcmd_index == PIPE_CMD)
	{
		dup2(pipex->pipe_fd[1], STDOUT_FILENO);
		close(pipex->pipe_fd[1]);
	}
	else if (argv->lastcmd_index == LAST_CMD)
	{
		if (redir->flag == RDIR_FILE && redir->redir_type == RDIR_TRUNC)
		{
			dup2(pipex->fdout, STDOUT_FILENO);
			close_fd(&pipex->fdout);
		}
	}
	close(pipex->pipe_fd[1]);

	exec_cmd(argv, pipex, redir);
	
	
}

void parent_process(t_pipex *pipex, t_redir *redir, t_cmd_to_exec *argv)
{
	(void)redir;
	(void)pipex;
	(void)argv;
	
	close(pipex->pipe_fd[1]);
	dup2(pipex->pipe_fd[0], STDIN_FILENO);
	close(pipex->pipe_fd[0]);
	
}

void ft_pipes(t_pipex *pipex, t_cmd_to_exec *argv, t_redir *redir)
{

	make_pipe(pipex, argv, redir);
	close(pipex->pipe_fd[0]);
	close(pipex->pipe_fd[1]);
}
