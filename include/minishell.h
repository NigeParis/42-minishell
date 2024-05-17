/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 11:15:12 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/17 13:24:26 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "minishell_types.h"

// File: src/builtins/cd.c
int		cd(t_minishell_control *ctrl, t_cmd *cmd);

// File: src/builtins/env.c
int		ft_env(t_minishell_control *ctrl, t_cmd *cmd);

// File: src/builtins/exit.c
int		exit_main(t_minishell_control *ctrl, t_cmd *cmd);

// File: src/builtins/export.c
// todo: implement export

// File: src/builtins/pwd.c
// todo: implement export

// File: src/builtins/unset.c
// todo: implement export

// File: src/core/minishell_cleanup.c
int		minishell_cleanup(t_minishell_control *shell);

// File: src/core/minishell_error.c
void	minishell_error(t_mini_err err_type, const char *msg, int errcode);

// File: src/core/minishell_execute.c
int		minishell_execute(t_minishell_control *shell);

// File: src/core/minishell_loop.c
void	minishell_loop(t_minishell_control *shell);

// File: src/core/minishell_main.c
int		mini_main(int ac, char **av, char **envp);

// File: src/core/minishell_prompt.c
int		minishell_prompt(t_minishell_control *shell);

// File: src/core/minishell_setup.c
int		create_env(t_minishell_control *ctrl, const char **envp);

// File: src/core/minishell_parser_init.c
int		minishell_parser_init(void *prs);

// File: src/core/minishell_setup.c
int		setup_minishell(t_minishell_control *minishell, int ac, char **args,
			char **envp);

// File: src/env/get_env.c
char	*get_env(t_vector *env, char *keyname);

// File: src/env/set_env.c
void	set_env(t_vector **env, char *keyname, char *value);

// File: src/main.c
int		main(int ac, char **av, char **envp);

// File: src/parser/parser_main.c
int		parser(t_minishell_control *ctrl, char *str);

#endif /* MINISHELL_H */
