/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 14:43:26 by nrobinso          #+#    #+#             */
/*   Updated: 2024/07/05 15:28:53 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "minishell_types.h"
#include "parser_types.h"
#include <stdbool.h>
#include <unistd.h>

void	handl_opt(char *arg, bool *flag_n, bool *error)
{
	size_t i;

	i = 1;
	while (arg[i])
	{
		if (arg[i] == 'n')
			*flag_n = true;
		else
			*error = false;
		i++;
	}
	return ;
}

int	echo_main(t_minishell_control *ctrl, t_cmd_to_exec *cmd)
{
	int		i;
	bool	flag_n;
	bool	error;

	i = 1;
	flag_n = false;
	error = false;
	while (cmd->argv[i][0] == '-' && cmd->argv[i][1] != '-')
		handl_opt(cmd->argv[i++], &flag_n, &error);
	while (i < cmd->ac)
	{
		add_to_buff(cmd->argv[i++], STDOUT_FILENO);
		if (!flag_n)
			add_to_buff("\n", STDOUT_FILENO);
	}
	if (i == 1 && !flag_n)
			add_to_buff("\n", STDOUT_FILENO);
	return (0);
}
