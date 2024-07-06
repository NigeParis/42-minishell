/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 14:43:26 by nrobinso          #+#    #+#             */
/*   Updated: 2024/07/06 15:33:10 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "ft_string_types.h"
#include "minishell_types.h"
#include "parser_types.h"
#include <stdbool.h>
#include <unistd.h>

static void	handl_opt(char *arg, bool *flag_n, bool *error)
{
	size_t	i;
	bool	loc_flag_n;
	bool	loc_error;

	i = 1;
	loc_flag_n = false;
	loc_error = false;
	while (arg[i])
	{
		if (arg[i++] == 'n')
			loc_flag_n = true;
		else
		{
			loc_error = true;
			break ;
		}
	}
	if (loc_flag_n == true && loc_error == false)
		*flag_n = true;
	else
		*error = true;
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
	if (cmd->ac <= 1)
		return (add_to_buff("\n", STDOUT_FILENO));
	while (cmd->argv[i] && cmd->argv[i][0] == '-' && cmd->argv[i][1] != '-')
	{
		handl_opt(cmd->argv[i], &flag_n, &error);
		if (error == true)
			break ;
		i++;
	}
	while (i < cmd->ac)
	{
		add_to_buff(cmd->argv[i++], STDOUT_FILENO);
		if (i != cmd->ac)
			add_to_buff(" ", STDOUT_FILENO);
	}
	if (flag_n == false)
			add_to_buff("\n", STDOUT_FILENO);
	return (0);
}
