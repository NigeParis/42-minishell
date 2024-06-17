/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:43:05 by nrobinso          #+#    #+#             */
/*   Updated: 2024/06/17 17:46:38 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "ft_char.h"

int   put_echo(t_minishell_control *ctrl, t_cmd *cmd)
{
	(void)ctrl;
	int i;

	i = 1;

	while (ft_strcmp(cmd->args[i], "-n") == 0)
	{
		i++;	
	}

	
	while (cmd->args && cmd->args[i] != NULL)
	{
		ft_putstr_fd(cmd->args[i], STDOUT_FILENO);
		if (cmd->args && cmd->args[i + 1]!= NULL)
			ft_putchar_fd(' ', STDOUT_FILENO);
		i++;
	}


	
	if (ft_strcmp(cmd->args[1], "-n") != 0)
		ft_putchar_fd('\n', STDOUT_FILENO);	

	return (0);
}

