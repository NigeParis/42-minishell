/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_prompt.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 16:13:21 by bgoulard          #+#    #+#             */
/*   Updated: 2024/07/15 15:32:00 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <readline/readline.h>

int	minishell_prompt(t_minishell_control *shell)
{
	if (!shell)
		return (EXIT_FAILURE);
	shell->input = readline(PROMPT);
	if (shell->input == NULL)
		shell->shoulcontinue = false;
	return (EXIT_SUCCESS);
}
