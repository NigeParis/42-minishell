/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 16:24:41 by nrobinso          #+#    #+#             */
/*   Updated: 2024/07/23 14:20:56 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

// cd
# define PWD 0
# define HOMEDIR 1
# define OLDPWD 2
# define TARGET 3
# define BUFF 4

# define PATH_MAX 1024

# include "parser_types.h"
# include "minishell_types.h"

/* ************************************************************************** */
/* ****************************builtins module utils************************* */
/* ************************************************************************** */

void	call_bin(t_minishell_control *shell, t_cmd_to_exec *cmd);

int	(*get_builtin(const char *cmd))(t_minishell_control *a, t_cmd_to_exec *b);

/// @file: src/builtins/builtins_utils.c
t_string	*buff_func(t_string *set_v, bool set_f, int fd_dst);
bool		add_to_buff(const char *str_to_add, int fd_dest);
void		destroy_buff(int fd_dest);
void		print_buff(int fd_dest);
void		buff_destroy_all(void);
void		buff_print_all(void);

/* ************************************************************************** */
/* **************************builtins module internals*********************** */
/* ************************************************************************** */

/// @file: src/builtins/cd.c
int			cd_main(t_minishell_control *ctrl, t_cmd_to_exec *cmd);

/// @file: src/builtins/env.c
int			env_main(t_minishell_control *ctrl, t_cmd_to_exec *cmd);

/// @file: src/builtins/exit.c
int			exit_main(t_minishell_control *ctrl, t_cmd_to_exec *cmd);

/// @file: src/builtins/echo.c
int			echo_main(t_minishell_control *ctrl, t_cmd_to_exec *cmd);

/// @file: src/builtins/export.c
int			export_main(t_minishell_control *ctrl, t_cmd_to_exec *cmd);
// todo: implement export

/// @file: src/builtins/pwd.c
int			pwd_main(t_minishell_control *ctrl, t_cmd_to_exec *cmd);
// todo: implement export

/// @file: src/builtins/unset.c
int			unset_main(t_minishell_control *ctrl, t_cmd_to_exec *cmd);

// todo: implement export
// todo: implement echo

#endif
