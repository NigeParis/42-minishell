/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_loop.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 13:17:01 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/20 11:32:50 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "ft_string.h"
#include "minishell.h"
#include "minishell_types.h"
#include <stdio.h>

int	minishell_should_exit(t_minishell_control *shell)
{
	return (0);
}

int	minishell_parse(t_minishell_control *shell)
{
	parser(shell, shell->input);
	if (!shell->cmds)
		return (1);
	return (0);
}

void	minishell_loop(t_minishell_control *shell)
{
	printf("minishell_loop %p\n", shell);
	while (1)
	{
		if (minishell_prompt(shell) || minishell_parse(shell)
			|| minishell_should_exit(shell))
			break ;
		minishell_execute(shell);
	}
}
