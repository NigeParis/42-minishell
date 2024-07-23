/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 12:59:59 by bgoulard          #+#    #+#             */
/*   Updated: 2024/07/23 12:52:23 by bgoulard         ###   ########.fr       */
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

static void	perr_cd(char *targ)
{
	add_to_buff("cd: ", STDERR_FILENO);
	add_to_buff(targ, STDERR_FILENO);
	add_to_buff(": ", STDERR_FILENO);
	add_to_buff(ft_strerror(errno), STDERR_FILENO);
	add_to_buff("\n", STDERR_FILENO);
}

static int	set_target(char **ptr, t_cmd_to_exec *cmd)
{
	if (cmd->ac == 1 || ft_strcmp(cmd->argv[1], "~") == 0
		|| ft_strcmp(cmd->argv[1], "--") == 0)
		ptr[TARGET] = ptr[HOMEDIR];
	else if (ft_strcmp(cmd->argv[1], "-") != 0)
		ptr[TARGET] = cmd->argv[1];
	else
	{
		if (!ptr[OLDPWD])
			return (add_to_buff("cd: OLDPWD not set\n", STDERR_FILENO));
		add_to_buff(ptr[OLDPWD], STDOUT_FILENO);
		add_to_buff("\n", STDOUT_FILENO);
		ptr[TARGET] = ptr[OLDPWD];
	}
	return (EXIT_SUCCESS);
}

int	cd_main(t_minishell_control *ctrl, t_cmd_to_exec *cmd)
{
	char	*ptr[5];

	ptr[HOMEDIR] = get_env(ctrl->env, "HOME");
	ptr[OLDPWD] = get_env(ctrl->env, "OLDPWD");
	ptr[PWD] = get_env(ctrl->env, "PWD");
	if (cmd->ac > 2)
		return (add_to_buff("cd: too many arguments\n", STDERR_FILENO),
			cmd->status = EXIT_FAILURE, EXIT_FAILURE);
	if (set_target(ptr, cmd) == EXIT_FAILURE)
		return (cmd->status = EXIT_FAILURE, EXIT_FAILURE);
	if (chdir(ptr[TARGET]) == -1)
		return (perr_cd(ptr[TARGET]), cmd->status = EXIT_FAILURE, EXIT_FAILURE);
	ptr[BUFF] = malloc(PATH_MAX);
	if (!ptr[BUFF])
		return (cmd->status = EXIT_FAILURE, EXIT_FAILURE);
	set_env(&ctrl->env, "OLDPWD", ptr[PWD]);
	set_env(&ctrl->env, "PWD", getcwd(ptr[BUFF], PATH_MAX));
	return (free(ptr[BUFF]), EXIT_SUCCESS);
}
