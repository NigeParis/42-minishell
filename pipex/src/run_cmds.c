/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_cmds.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 08:29:28 by nrobinso          #+#    #+#             */
/*   Updated: 2024/06/18 18:00:05 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"





void	exec_cmd(t_cmd_to_exec *args, t_pipex *pipex, t_redir *redir)
{
	int	ret;

	
	ret = -1;
	(void)pipex;
	(void)redir;
	

		if (ft_strcmp(args->argv[0], "pwd") == 0)
		{
			get_pwd(testminictrl(),test_cmd_pwd()); // testmin* to add test values
			exit (1);
		}
		if (ft_strcmp(args->argv[0], "echo") == 0)
		{
			put_echo(testminictrl(),test_cmd_echo()); // testmin* to add test values
			exit (1);
		}

	
		close_fd(&pipex->fdin);
		close_fd(&pipex->fdout);
		close(pipex->pipe_fd[0]);
		close(pipex->pipe_fd[1]);
		close(redir->std_src);               
        close(redir->std_dst); 
		ret = execve(args->cmd_path, args->argv, args->env);
		if (ret == -1)
		{
			ft_putstr_fd(args->argv[0], STDERR_FILENO);
			ft_putstr_fd(": ", STDERR_FILENO);
			ft_putendl_fd("command not found", STDERR_FILENO); 
			exit(127);
		}
		
}

