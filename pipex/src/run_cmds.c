/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmds.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 08:29:28 by nrobinso          #+#    #+#             */
/*   Updated: 2024/06/03 12:54:23 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"




void	exec_cmd(t_pipex *pipex, int i, char *argv[], char *env[])
{
	int	ret;
	t_cmd_to_exec *testargs;
	(void)argv;
	(void)i;
	ret = -1;
	

	testargs = cmd_to_exec_new();

	if (pipex->valid_cmd == 0)
	{
		pipex->valid_cmd = 1;
		ret = execve(testargs->cmd_path, testargs->argv, env);
	}
	if (ret == -1)
	{
		ft_exec_cmd_error(pipex, "pipex: command not found: ");
		exit(127);
	}
}

