/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_cmds.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 08:29:28 by nrobinso          #+#    #+#             */
/*   Updated: 2024/06/24 13:00:59 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"





void	exec_cmd(t_cmd_to_exec *argv, t_pipex *pipex, t_redir *redir)
{
	int	ret;

	
	ret = -1;
	(void)pipex;
	(void)redir;
	

		if (ft_strcmp(argv->argv[0], "pwd") == 0)
		{
			get_pwd(testminictrl(),test_cmd_pwd()); // testmin* to add test values
			exit (1);
		}
		if (ft_strcmp(argv->argv[0], "echo") == 0)
		{
			put_echo(testminictrl(),test_cmd_echo()); // testmin* to add test values
		
			exit (1) ;
		}

		if ((ft_strcmp(argv->argv[0], "exit") == 0) && (argv->lastcmd_index != FIRST_CMD))
		{
			exit (exit_main(testminictrl(),test_cmd_exit()));
			exit (1);
		}
	
		close_fd(&pipex->fdin);
		close_fd(&pipex->fdout);
		close(pipex->pipe_fd[0]);
		close(pipex->pipe_fd[1]);
		close(redir->std_src);               
        close(redir->std_dst); 
		ret = execve(argv->cmd_path, argv->argv, argv->env);
		if (ret == -1)
		{
			ft_putstr_fd(argv->argv[0], STDERR_FILENO);
			ft_putstr_fd(": ", STDERR_FILENO);
			ft_putendl_fd("command not found", STDERR_FILENO); 
			exit(127);
		}
		
}

