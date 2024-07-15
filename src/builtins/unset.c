/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 12:59:42 by bgoulard          #+#    #+#             */
/*   Updated: 2024/07/15 12:40:18 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "ft_string.h"
#include "minishell.h"
#include "parser_types.h"
#include <unistd.h>

int	unset_main(t_minishell_control *ctrl, t_cmd_to_exec *cmd)
{
	int	i;

	i = 1;
	while (cmd->ac > i)
	{
		if (ft_strchr(cmd->argv[i], '='))
		{
			add_to_buff("unset: not a valid identifier\n", STDERR_FILENO);
			return (EXIT_FAILURE);
		}
		unset_env(ctrl->env, cmd->argv[i++]);
	}
	return (EXIT_SUCCESS);
}
