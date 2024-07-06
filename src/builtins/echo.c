/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 14:43:26 by nrobinso          #+#    #+#             */
/*   Updated: 2024/07/06 13:09:20 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "minishell_types.h"
#include "parser_types.h"
#include "ft_string.h"
#include <stdbool.h>
#include <unistd.h>

static void	handl_opt(char *arg, bool *flag_n, bool *error)
{
	size_t	i;

	i = 1;
	while (arg[i])
	{
		if (arg[i] == 'n')
		{
			*flag_n = true;
			*error = false;
		}
		else
		{
			*flag_n = false;
			*error = true;
			break ;
		}
		i++;
	}
	return ;
}

static int	option_checker(t_cmd_to_exec *cmd, bool *flag_n, bool *error)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	while (cmd->argv[i] && cmd->argv[i][0] == '-' && cmd->argv[i][1] != '-')
	{
		{
			handl_opt(cmd->argv[i++], flag_n, error);
			if (*error == true)
			{
				j == i - 1;
				break ;
			}
			else
				j++;
		}
	}
	i = j;
	return (i);
}

static void	add_newline(int i, bool *flag_n)
{
	if (i == 1 && !*flag_n)
		add_to_buff("\n", STDOUT_FILENO);
}

int	echo_main(t_minishell_control *ctrl, t_cmd_to_exec *cmd)
{
	int		i;
	bool	flag_n;
	bool	error;

	i = 1;
	flag_n = false;
	error = false;
	if (cmd->ac > 1 && cmd->argv[1] != NULL)
	{
		i = option_checker(cmd, &flag_n, &error);
		while (i < cmd->ac)
		{
			add_to_buff(cmd->argv[i++], STDOUT_FILENO);
			if (i != cmd->ac)
				add_to_buff(" ", STDOUT_FILENO);
			if (i == cmd->ac)
			{
				if (cmd->argv[1][0] == '-' && cmd->argv[1][1] != '-')
					handl_opt(cmd->argv[1], &flag_n, &error);
				if ((!flag_n && error) || (!flag_n && !error))
					add_to_buff("\n", STDOUT_FILENO);
			}
		}
	}
	return (add_newline(i, &flag_n), EXIT_SUCCESS);
}
