/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 12:59:59 by bgoulard          #+#    #+#             */
/*   Updated: 2024/07/03 16:27:41 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "ft_string.h"
#include "minishell.h"
#include "minishell_types.h"
#include "parser_types.h"
#include <stdio.h>
#include <sys/param.h>

int	cd_main(t_minishell_control *ctrl, t_cmd_to_exec *cmd)
{
	char	*ptr[5];

	ptr[HOMEDIR] = get_env(ctrl->env, "HOME");
	ptr[OLDPWD] = get_env(ctrl->env, "OLDPWD");
	ptr[PWD] = get_env(ctrl->env, "PWD");
	if (cmd->ac > 2)
		return (ft_putstr_fd("cd: too many arguments\n", STDERR_FILENO),
			EXIT_FAILURE);
	if (cmd->ac == 1)
		ptr[TARGET] = ptr[HOMEDIR];
	else if (ft_strcmp(cmd->argv[1], "-") == 0)
		ptr[TARGET] = ptr[OLDPWD];
	else
		ptr[TARGET] = cmd->argv[1];
	if (chdir(ptr[TARGET]) == -1)
	{
		ft_putstr_fd("cd: ", STDERR_FILENO);
		return (perror(ptr[TARGET]), EXIT_FAILURE);
	}
	ptr[BUFF] = malloc(PATH_MAX);
	if (!ptr[BUFF])
		return (EXIT_FAILURE);
	set_env(&ctrl->env, "OLDPWD", ptr[PWD]);
	set_env(&ctrl->env, "PWD", getcwd(ptr[BUFF], PATH_MAX));
	return (free(ptr[BUFF]), EXIT_SUCCESS);
}
