/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_cmds.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 08:29:28 by nrobinso          #+#    #+#             */
/*   Updated: 2024/06/04 16:43:08 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"




void	exec_cmd(t_pipex *pipex, int i, t_cmd_to_exec *args)
{
	(void)pipex;
	int	ret;
	(void)i;
	ret = -1;
	

	ret = execve(args->cmd_path, args->argv, args->env);
	if (ret == -1)
	{
		//ft_exec_cmd_error(pipex, "pipex: command not found: ");
		exit(127);
	}
}

