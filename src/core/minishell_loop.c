/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_loop.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 13:17:01 by bgoulard          #+#    #+#             */
/*   Updated: 2024/08/18 10:18:15 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_char.h"
#include "ft_string.h"
#include "minishell.h"
#include "parser.h"

#include <stdio.h>
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
	prs = (t_parser *)shell->prs;
	prs->line = resolve_raw_exp(shell->input, shell);
	if (!prs->line)
		return (EXIT_FAILURE);
	if (!prs->line || prs->line[0] == '\0' || ft_str_isvalid(prs->line, \
	ft_isspace))
		return (ft_free((void **)&prs->line), EXIT_SUCCESS);
	parser_line_init(prs);
	ft_free((void **)&prs->line);
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
