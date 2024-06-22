/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_cleanup.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 13:16:52 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/22 08:12:12 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include "ft_vector_types.h"
#include "parser.h"
#include "minishell.h"
#include "pair.h"
#include "parser_types.h"
#include <stdlib.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

static void	destroy_env_line(void *e)
{
	t_pair	*pair;

	pair = (t_pair *)e;
	free(pair->first);
	free(pair->second);
	free(pair);
	return ;
}

static void destroy_env(t_vector **env)
{
	ft_vec_apply(*env, destroy_env_line);
	ft_vec_destroy(env);
	return ;
}

void	free_preparsed_node(void *node_s)
{
	t_preparsed_node	*node;

	node = (t_preparsed_node *)node_s;
	if (node->type == TOK_WORD)
		free(node->value);
	free(node);
}

int	minishell_cleanup(t_minishell_control *shell)
{
	// free readline buff
	rl_clear_history();

	// free shell fields
	if (shell->input)
		free(shell->input);
	if (shell->env)
		destroy_env(&shell->env);
	if (shell->prs)
		parser_glob_cleanup(shell->prs), free(shell->prs);
	return (shell->exit);
}
