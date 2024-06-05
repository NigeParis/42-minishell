/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 11:54:14 by nrobinso          #+#    #+#             */
/*   Updated: 2024/06/05 17:08:23 by nrobinso         ###   ########.fr       */
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
		parent_process(pipex);
	}
	return (0);
}

void	child_process(t_pipex *pipex, t_cmd_to_exec *args, t_redir *redir, int i)
{
	close(pipex->pipe_fd[0]);
	

	
	if (i == args->lastcmd_index) // nbr cmds called - lastcmd important for sortie
	{
		if(redir->flag == 1)
			dup2(pipex->fdout, redir->src);
		close_fd(pipex);
	}
	else
	{
		dup2(pipex->pipe_fd[1], redir->src);
		close(pipex->pipe_fd[0]);
	}
	close(pipex->fdout);
	close_fd(pipex);
	close(pipex->pipe_fd[1]);
	exec_cmd(args);
}

void	parent_process(t_pipex *pipex)
{
	close(pipex->pipe_fd[1]);
	dup2(pipex->pipe_fd[0], STDIN_FILENO);
	close(pipex->pipe_fd[1]);
}

void	ft_pipes(t_pipex *pipex, t_cmd_to_exec *args, t_redir *redir, int i)
{
	make_pipe(pipex, args, redir, i);
	close(pipex->pipe_fd[0]);
	close(pipex->pipe_fd[1]);
}
