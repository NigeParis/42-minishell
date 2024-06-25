/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 12:59:42 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/23 11:30:43 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "minishell.h"
#include "parser_types.h"
#include <stdio.h>

int unset_main(t_minishell_control *ctrl, t_cmd_to_exec *cmd)
{
	int i;

	i = 1;
	while (cmd->ac > i)
	{
		if (ft_strchr(cmd->argv[i], '='))
		{
			printf("unset: not a valid identifier\n");
			return (EXIT_FAILURE);
		}
		unset_env(ctrl->env, cmd->argv[i++]);
	}
	return (EXIT_SUCCESS);
}
