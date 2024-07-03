/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 16:24:41 by nrobinso          #+#    #+#             */
/*   Updated: 2024/07/03 17:34:22 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# define PWD 0
# define HOMEDIR 1
# define OLDPWD 2
# define TARGET 3
# define BUFF 4
# define PATH_MAX 1024

# include "parser_types.h"
# include "minishell_types.h"

/* ************************************************************************** */
/* **************************builtins module internals*********************** */
/* ************************************************************************** */

/// @file: src/builtins/cd.c
int		cd_main(t_minishell_control *ctrl, t_cmd_to_exec *cmd);

/// @file: src/builtins/env.c
int		env_main(t_minishell_control *ctrl, t_cmd_to_exec *cmd);

/// @file: src/builtins/exit.c
int		exit_main(t_minishell_control *ctrl, t_cmd_to_exec *cmd);

/// @file: src/builtins/echo.c
int		echo_main(t_minishell_control *ctrl, t_cmd_to_exec *cmd);

/// @file: src/builtins/export.c
int		export_main(t_minishell_control *ctrl, t_cmd_to_exec *cmd);
// todo: implement export

/// @file: src/builtins/pwd.c
int		pwd_main(t_minishell_control *ctrl, t_cmd_to_exec *cmd);
// todo: implement export

/// @file: src/builtins/unset.c
int		unset_main(t_minishell_control *ctrl, t_cmd_to_exec *cmd);

// todo: implement export
// todo: implement echo

#endif