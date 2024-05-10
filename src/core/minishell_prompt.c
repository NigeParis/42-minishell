/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_prompt.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 16:13:21 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/10 12:46:29 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h>
#include <stdio.h>
#include <readline/readline.h>

// TODO:
// move printf("exit\n") to shell cleanup function or somewhere else cleaner
int	minishell_prompt(t_minishell_control *shell)
{
	shell->input = readline("minishell $> ");
	if (shell->input == NULL)
		return (printf("exit\n"), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
