/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:43:05 by nrobinso          #+#    #+#             */
/*   Updated: 2024/06/19 10:16:42 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "ft_char.h"


static int is_echo_flag(t_cmd *cmd, int i)
{
	int y;

	y = 1;
	if (!cmd->args)
		return (0);
	if(cmd && cmd->args[i][0] == '-')
	{
		while(cmd->args[i] && cmd->args[i][y] == 'n')
		{		
			if (cmd->args[i][y] != 'n')	
				return (0);
			y++;
		}
		if (cmd->args[i][y] == '\0')
			return (1);
		y = 1;
	}
	
	return (0);
}


int   put_echo(t_minishell_control *ctrl, t_cmd *cmd)
{
	(void)ctrl;
	int i;

	i = 1;

	while (is_echo_flag(cmd, i))
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
	if (!is_echo_flag(cmd, 1))
		ft_putchar_fd('\n', STDOUT_FILENO);	

	return (0);
}

