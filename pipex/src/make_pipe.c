/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 11:54:14 by nrobinso          #+#    #+#             */
/*   Updated: 2024/06/13 15:39:52 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	make_pipe(t_pipex *pipex, t_cmd_to_exec *args, t_redir *redir, int i)
{
	pid_t	process;
	int		ret;


	ret = pipe(pipex->pipe_fd);
	if (ret < 0)
		perror("pipe");
	process = fork();
	if (process == -1)
		perror("fork");
	if (!process)
	{
		child_process(pipex, args, redir, i);
	}
	else
	{
		parent_process(pipex, redir);
		close(pipex->pipe_fd[1]);
		close(pipex->fdin);
		dup2(pipex->pipe_fd[0], STDIN_FILENO);
		close(pipex->pipe_fd[0]);
	}		
	return (0);
}

void	child_process(t_pipex *pipex, t_cmd_to_exec *args, t_redir *redir, int i)
{
	(void)i;

	
	if (args->lastcmd_index == FIRST_CMD) 
	{
		if(redir->src_flag)
		{
			dup2(pipex->fdin, STDIN_FILENO);
			close(pipex->fdin);
		}
		dup2(pipex->pipe_fd[1], STDOUT_FILENO);
		close(pipex->pipe_fd[1]);
	}
	else if (args->lastcmd_index == PIPE_CMD)
	{
		dup2(pipex->pipe_fd[1], STDOUT_FILENO);
		close(pipex->pipe_fd[1]);
	}
	else if (args->lastcmd_index == LAST_CMD) 
	{
		if(redir->dst_flag)
		{
			dup2(pipex->fdout, STDOUT_FILENO);
			close(pipex->fdout);
		}
	}
	
	exec_cmd(args, pipex);
}

void	parent_process(t_pipex *pipex, t_redir *redir)
{
	(void)redir;
	(void)pipex;
	
}

void	ft_pipes(t_pipex *pipex, t_cmd_to_exec *args, t_redir *redir, int i)
{
	make_pipe(pipex, args, redir, i);
}
