/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_cleanup.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 13:16:52 by bgoulard          #+#    #+#             */
/*   Updated: 2024/07/15 13:16:24 by bgoulard         ###   ########.fr       */
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

void	exec_cl(t_minishell_control *shell)
{
	t_preparsed_node	*node;
	size_t				i;

	if (!shell)
		return ;
	i = 0;
	if (shell->preparsed)
	{
		while (i < shell->preparsed->count)
		{
			node = ft_vec_at(shell->preparsed, i);
			if (node && node->destroy)
				node->destroy(node);
			i++;
		}
		ft_vec_destroy(&shell->preparsed);
		shell->preparsed = NULL;
	}
}

static void	destroy_env_line(void *e)
{
	t_pair	*pair;

	pair = (t_pair *)e;
	free(pair->first);
	free(pair->second);
	free(pair);
	return ;
}

static void	destroy_env(t_vector **env)
{
	ft_vec_apply(*env, destroy_env_line);
	ft_vec_destroy(env);
	return ;
}

void	free_preparsed_node(void *node_s)
{
	t_preparsed_node	*node;

	node = (t_preparsed_node *)node_s;
	if (node->type != TOK_UNKNOWN && node->destroy)
		node->destroy(node);
	else
		free(node);
}

int	minishell_cleanup(t_minishell_control *shell)
{
	if (DEBUG_LEVEL >= 20)
		printf("cleanup\n");
	rl_clear_history();
	if (shell->input)
		free(shell->input);
	if (shell->env)
		destroy_env(&shell->env);
	if (shell->prs)
		(parser_glob_cleanup(shell->prs), free(shell->prs));
	if (shell->preparsed)
	{
		ft_vec_apply(shell->preparsed, free_preparsed_node);
		ft_vec_destroy(&shell->preparsed);
	}
	return (shell->exit);
}
