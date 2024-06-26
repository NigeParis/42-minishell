/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_cmds.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 08:29:28 by nrobinso          #+#    #+#             */
/*   Updated: 2024/06/26 15:21:56 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"





void	exec_cmd(t_cmd_to_exec *argv, t_pipex *pipex)
{
	int	ret;
	dprintf(STDERR_FILENO, "---->ExEc_cmd \n");

	ret = -1;
	(void)pipex;
	

		if (ft_strcmp(argv->argv[0], "pwd") == 0)
		{
			pwd_main(testminictrl(),argv); // testmin* to add test values
			exit (1);
		}
		if (ft_strcmp(argv->argv[0], "echo") == 0)
		{
			
			echo_main(testminictrl(),argv); // testmin* to add test values
			exit (1) ;
		}

		if (ft_strcmp(argv->argv[0], "exit") == 0)
		{
			exit (exit_main(testminictrl(),argv));
			exit (1);
		}
	
		close_fd(&pipex->fdin);
		close_fd(&pipex->fdout);
		close(pipex->pipe_fd[0]);
		close(pipex->pipe_fd[1]);
		dprintf(STDERR_FILENO, "---->cmds path %s \n", argv->cmd_path);
		dprintf(STDERR_FILENO, "---->cmds %s \n", argv->argv[0]);
		ret = execve(argv->cmd_path, argv->argv, argv->env);
		if (ret == -1)
		{
			ft_putstr_fd(argv->argv[0], STDERR_FILENO);
			ft_putstr_fd(": ", STDERR_FILENO);
			ft_putendl_fd("command not found", STDERR_FILENO); 
			exit(127);
		}
		
}

