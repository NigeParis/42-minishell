/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 12:59:59 by bgoulard          #+#    #+#             */
/*   Updated: 2024/07/08 14:43:32 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "ft_string.h"
#include "minishell.h"
#include "ft_addons.h"
#include "minishell_types.h"
#include "parser_types.h"
#include <errno.h>
#include <sys/param.h>
#include <unistd.h>

int	cd_main(t_minishell_control *ctrl, t_cmd_to_exec *cmd)
{
	char	*ptr[5];

	ptr[HOMEDIR] = get_env(ctrl->env, "HOME");
	ptr[OLDPWD] = get_env(ctrl->env, "OLDPWD");
	ptr[PWD] = get_env(ctrl->env, "PWD");
	if (cmd->ac > 2)
		return (add_to_buff("cd: too many arguments\n", STDERR_FILENO),
			EXIT_FAILURE);
	if (cmd->ac == 1)
		ptr[TARGET] = ptr[HOMEDIR];
	else if (ft_strcmp(cmd->argv[1], "-") == 0)
		ptr[TARGET] = (add_to_buff(ptr[OLDPWD], STDOUT_FILENO),
			add_to_buff("\n", STDOUT_FILENO), ptr[OLDPWD]);
	else
		ptr[TARGET] = cmd->argv[1];
	if (chdir(ptr[TARGET]) == -1)
	{
		add_to_buff("cd: ", STDERR_FILENO);
		add_to_buff(ptr[TARGET], STDERR_FILENO);
		add_to_buff(": ", STDERR_FILENO);
		add_to_buff(ft_strerror(errno), STDERR_FILENO);
	}
	ptr[BUFF] = malloc(PATH_MAX);
	if (!ptr[BUFF])
		return (EXIT_FAILURE);
	set_env(&ctrl->env, "OLDPWD", ptr[PWD]);
	set_env(&ctrl->env, "PWD", getcwd(ptr[BUFF], PATH_MAX));
	return (free(ptr[BUFF]), EXIT_SUCCESS);
}
