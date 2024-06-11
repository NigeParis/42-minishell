/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_cmds.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 08:29:28 by nrobinso          #+#    #+#             */
/*   Updated: 2024/06/11 18:05:08 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"




void	exec_cmd(t_cmd_to_exec *args, t_pipex *pipex)
{
	int	ret;
	//char *ptr;
	ret = -1;
	(void)pipex;

	// if (ft_strcmp(args->argv[0], "pwd") == 0)
	// {
    //     ptr = get_pwd(pipex);
	// 	ft_putstr_fd("rrrrrrr", pipex->fdin);
	// 	exit (1);
	// }
	// else
	// {

		ret = execve(args->cmd_path, args->argv, args->env);
		if (ret == -1)
		{
		//ft_exec_cmd_error(pipex, "pipex: command not found: ");
		exit(127);
		}
	// }
}

