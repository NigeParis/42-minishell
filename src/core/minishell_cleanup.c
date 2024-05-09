/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_cleanup.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 13:16:52 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/09 18:05:55 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_addons.h"
#include "ft_vector.h"
#include "minishell.h"
#include "pair.h"
#include <stdlib.h>

static void	destroy_env_line(void *e)
{
	return (destroy_pair_deep((t_pair *)e));
}

int	minishell_cleanup(t_minishell_control *shell)
{
	if (shell->input)
		free(shell->input);
	if (shell->words)
		ft_free_2d((void **)shell->words);
	if (shell->env)
	{
		ft_vec_apply(shell->env, destroy_env_line);
		ft_vec_destroy(&shell->env);
	}
	return (shell->ret);
}
