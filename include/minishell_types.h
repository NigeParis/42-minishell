/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_types.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 10:50:34 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/23 17:08:06 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_TYPES_H
# define MINISHELL_TYPES_H

# include "ft_vector_types.h"
# include "pair.h"

typedef struct s_minishell_control
{
	bool		shoulcontinue;
	char		*input;
	t_vector	*env;
	int			exit;
	t_vector	*preparsed;
	void		*prs;
}	t_minishell_control;

// MINI_ERR_CMDP, parse
// MINI_ERR_CMDE, exec
// MINI_ERR_FATAL, leave as last elem of enum (used to get enum length)

typedef enum e_mini_err
{
	MINI_ERR_ENVC,
	MINI_ERR_USER_INPUT,
	MINI_ERR_CMDP,
	MINI_ERR_CMDE,
	MINI_ERR_FATAL,
}	t_mini_err;

/// @brief Structure to store a command and its arguments
/// @param cmd The command to execute with its full path
/// @param args The arguments to pass to the command
/// @param argc The number of arguments
/// @param envp The environment variables as an array of strings
/// @param ret The return value of the command
typedef struct s_cmd
{
	char		*cmd;
	char		**args;
	int			argc;
	char		**envp;
	int			ret;
}	t_cmd;

#endif
