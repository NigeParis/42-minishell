/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_loop.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 13:17:01 by bgoulard          #+#    #+#             */
/*   Updated: 2024/07/15 16:40:33 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "ft_string.h"
#include "minishell.h"
#include "minishell_types.h"
#include "parser.h"
#include "parser_types.h"

#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

int	minishell_should_exit(t_minishell_control *shell)
{
	if (shell->shoulcontinue != true)
		return (1);
	return (0);
}

char	*resolve_raw_exp(char *line, t_minishell_control *shell);

// todo check if input is 1 - null 2 - empty if yes dont add to history
int	minishell_parse(t_minishell_control *shell)
{
	t_parser	*prs;

	if (!shell)
		return (EXIT_FAILURE);
	if (!shell->input || shell->input[0] == '\0')
		return (EXIT_SUCCESS);
	prs = (t_parser *)shell->prs;
	prs->line = resolve_raw_exp(shell->input, shell);
	if (!prs->line)
		return (EXIT_FAILURE);
	parser_line_init(shell->prs);
	free(prs->line);
	prs->line = NULL;
	shell->preparsed = prs->preparsed;
	if (shell->preparsed == NULL || shell->preparsed->count == 0)
		return (EXIT_SUCCESS);
	if (minishell_execute(shell))
		return (parser_line_cleanup(shell->prs), EXIT_FAILURE);
	add_history(shell->input);
	return (parser_line_cleanup(shell->prs), EXIT_SUCCESS);
}

void	minishell_loop(t_minishell_control *shell)
{
	if (!shell)
		return ;
	while (1)
	{
		if (minishell_prompt(shell) || minishell_parse(shell)
			|| minishell_should_exit(shell))
			break ;
	}
}
