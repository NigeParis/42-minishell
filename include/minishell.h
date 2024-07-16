/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 11:15:12 by bgoulard          #+#    #+#             */
/*   Updated: 2024/07/16 10:46:18 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define DEFAULT_PROMPT " minishell $> "

# ifndef DEBUG_LEVEL
#  define DEBUG_LEVEL 0
#  define PROMPT DEFAULT_PROMPT
# elif DEBUG_LEVEL >= 20
#  define PROMPT "dbg $> "
# else
#  define PROMPT DEFAULT_PROMPT
# endif

# include "parser_types.h"
# include "minishell_types.h"

/* ************************************************************************** */
/* ***************************Pipe utils function**************************** */
/* ************************************************************************** */

bool	has_pipe(t_list *redirs);
void	set_pipe(int *pipe_fd, int fd_1, int fd_2);

void	signal_init(void);

/* ************************************************************************** */
/* **************************core module internals*************************** */
/* ************************************************************************** */

void	free_rdr_node(void *abst_node);

void	discard_cmd(t_cmd_to_exec *cmd);

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

/* ************************************************************************** */
/* ***************************env module internals*************************** */
/* ************************************************************************** */

/// @file: src/env/get_env.c
char	*get_env(t_vector *env, char *keyname);
char	**get_bourne_env(t_vector *env);

/// @file: src/env/set_env.c
void	set_env(t_vector **env, char *keyname, char *value);

/// @file: src/env/unset_env.c
bool	unset_env(t_vector *env, const char *key);

// trailing main function

/// @file: src/main.c
int		main(int ac, char **av, char **envp);

#endif /* MINISHELL_H */
