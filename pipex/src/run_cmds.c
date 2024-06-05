/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_cmds.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 08:29:28 by nrobinso          #+#    #+#             */
/*   Updated: 2024/06/05 15:27:40 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"




void	exec_cmd(t_cmd_to_exec *args)
{
	int	ret;
	ret = -1;
	

	ret = execve(args->cmd_path, args->argv, args->env);
	if (ret == -1)
	{
		//ft_exec_cmd_error(pipex, "pipex: command not found: ");
		exit(127);
	}
}

