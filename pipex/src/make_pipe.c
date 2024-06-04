/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 11:54:14 by nrobinso          #+#    #+#             */
/*   Updated: 2024/06/04 17:29:50 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	make_pipe(t_pipex *pipex, t_cmd_to_exec *args, int i)
{
	pid_t	process;
	int		ret;

	printf("i = %d   <-----------------\n", i); // i incremented
	ret = pipe(pipex->pipe_fd);
	if (ret < 0)
		perror("pipe");
	process = fork();
	if (process == -1)
		perror("fork");
	if (!process)
	{
		child_process(pipex, args, i);
	}
	else
	{
		parent_process(pipex);
	}
	return (0);
}

void	child_process(t_pipex *pipex, t_cmd_to_exec *args, int i)
{
	close(pipex->pipe_fd[0]);
	
	if (i == 2)
		dup2(pipex->fdin, STDIN_FILENO);
	args->ac = args->ac + 1;									// need to find a way to test
	printf("args-ac = %d   <-----------------\n", args->ac);	// printout
	
	if (i == args->ac)
	{
		dup2(pipex->fdout, STDOUT_FILENO);
		close_fd(pipex, 1);
	}
	else
	{
		dup2(pipex->pipe_fd[1], STDOUT_FILENO);
		close(pipex->pipe_fd[0]);
	}
	close(pipex->fdout);
	close_fd(pipex, 10);
	close(pipex->pipe_fd[1]);
	exec_cmd(pipex, i, args);
}

void	parent_process(t_pipex *pipex)
{
	close(pipex->pipe_fd[1]);
	dup2(pipex->pipe_fd[0], STDIN_FILENO);
	close(pipex->pipe_fd[1]);
}

void	ft_pipes(t_pipex *pipex, t_cmd_to_exec *args, int i)
{
	make_pipe(pipex, args, i);
	close(pipex->pipe_fd[0]);
	close(pipex->pipe_fd[1]);
}
