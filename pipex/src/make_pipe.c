/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 11:54:14 by nrobinso          #+#    #+#             */
/*   Updated: 2024/06/10 16:41:50 by nrobinso         ###   ########.fr       */
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
	(void)i;


	close(pipex->pipe_fd[0]);
	
	if (args->lastcmd_index == FIRST_CMD) 
	{
		if(redir->src_flag)
		{
			dup2(pipex->fdin, redir->std_src);
		}
		dup2(pipex->pipe_fd[1], STDOUT_FILENO);
	}
	else if (args->lastcmd_index == PIPE_CMD)
	{
		dup2(pipex->pipe_fd[1], redir->std_dst);
		close(pipex->pipe_fd[0]);
	}
	else if (args->lastcmd_index == LAST_CMD) 
	{
		if(redir->dst_flag)
			dup2(pipex->fdout, redir->std_dst);
		close_fdout(pipex);
	}
	close(pipex->fdout);
	close_fdout(pipex);
	close(pipex->pipe_fd[1]);
	
	exec_cmd(args);
}

void	parent_process(t_pipex *pipex)
{
	close(pipex->pipe_fd[1]);
		///. BAPTISTES c'est pas bon cett dup2 ici pour MINISHELL
		/// Il doit etre dans l'enfant
		dup2(pipex->pipe_fd[0], STDIN_FILENO);  
	close(pipex->pipe_fd[1]);
}

void	ft_pipes(t_pipex *pipex, t_cmd_to_exec *args, t_redir *redir, int i)
{
	make_pipe(pipex, args, redir, i);
	close(pipex->pipe_fd[0]);
	close(pipex->pipe_fd[1]);
}
