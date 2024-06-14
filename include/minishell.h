/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 11:15:12 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/14 15:47:33 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "minishell_types.h"

/// @file: src/builtins/cd.c
int		cd_main(t_minishell_control *ctrl, t_cmd *cmd);

/// @file: src/builtins/env.c
int		env_main(t_minishell_control *ctrl, t_cmd *cmd);

/// @file: src/builtins/exit.c
int		exit_main(t_minishell_control *ctrl, t_cmd *cmd);

/// @file: src/builtins/export.c
int		export_main(t_minishell_control *ctrl, t_cmd *cmd);
// todo: implement export

/// @file: src/builtins/pwd.c
int		pwd_main(t_minishell_control *ctrl, t_cmd *cmd);
// todo: implement export

/// @file: src/builtins/unset.c
int		unset_main(t_minishell_control *ctrl, t_cmd *cmd);
// todo: implement export

/// @file: src/core/minishell_cleanup.c
int		minishell_cleanup(t_minishell_control *shell);

/// @file: src/core/minishell_error.c
void	minishell_error(t_mini_err err_type, const char *msg, int errcode);

/// @file: src/core/minishell_execute.c
int		minishell_execute(t_minishell_control *shell);

/// @file: src/core/minishell_loop.c
void	minishell_loop(t_minishell_control *shell);

/// @file: src/core/minishell_main.c
int		mini_main(int ac, char **av, char **envp);

/// @file: src/core/minishell_prompt.c
int		minishell_prompt(t_minishell_control *shell);

/// @file: src/core/minishell_setup.c
int		create_env(t_minishell_control *ctrl, const char **envp);

/// @file: src/core/minishell_parser_init.c
int		minishell_parser_init(void *prs);

/// @file: src/core/minishell_setup.c
int		setup_minishell(t_minishell_control *minishell, int ac, char **args,
			char **envp);

/// @file: src/env/get_env.c
char	*get_env(t_vector *env, char *keyname);
char	**get_bourne_env(t_vector *env);

/// @file: src/env/set_env.c
void	set_env(t_vector **env, char *keyname, char *value);

/// @file: src/main.c
int		main(int ac, char **av, char **envp);

#endif /* MINISHELL_H */
