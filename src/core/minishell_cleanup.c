/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_cleanup.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 13:16:52 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/13 18:34:32 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_vector.h"
#include "parser.h"
#include "minishell.h"
#include "pair.h"
#include <stdlib.h>

static void	destroy_env_line(void *e)
{
	return (destroy_pair_deep((t_pair *)e));
}

static void destroy_env(void *env)
{
	ft_vec_apply(*(t_vector **)env, destroy_env_line);
	ft_vec_destroy((t_vector **)env);
}

int	minishell_cleanup(t_minishell_control *shell)
{
	if (shell->input)
		free(shell->input);
	if (shell->preparsed)
		ft_vec_destroy(&shell->preparsed);
	if (shell->env)
		destroy_env(&shell->env);
	if (shell->prs)
		parser_glob_cleanup(shell->prs);
	return (shell->exit);
}
