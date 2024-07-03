/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 14:43:26 by nrobinso          #+#    #+#             */
/*   Updated: 2024/07/03 15:55:31 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "minishell_types.h"
#include "parser_types.h"
#include "ft_char.h"

static int	is_echo_flag(t_cmd_to_exec *cmd, int i)
{
	int	y;

	y = 1;
	if (!cmd->argv)
		return (0);
	if (cmd && cmd->argv[i][0] == '-')
	{
		while (cmd->argv[i] && cmd->argv[i][y] == 'n')
		{
			if (cmd->argv[i][y] != 'n')
				return (0);
			y++;
		}
		if (cmd->argv[i][y] == '\0')
			return (1);
		y = 1;
	}
	return (0);
}

int	echo_main(t_minishell_control *ctrl, t_cmd_to_exec *cmd)
{
	int	i;

	(void)ctrl;
	i = 1;
	while (is_echo_flag(cmd, i))
		i++;
	while (cmd->argv && cmd->argv[i] != NULL)
	{
		ft_putstr_fd(cmd->argv[i], STDOUT_FILENO);
		if (cmd->argv && cmd->argv[i + 1] != NULL)
			ft_putchar_fd(' ', STDOUT_FILENO);
		i++;
	}
	if (!is_echo_flag(cmd, 1))
		ft_putchar_fd('\n', STDOUT_FILENO);
	return (0);
}
