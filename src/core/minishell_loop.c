/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_loop.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 13:17:01 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/20 10:48:31 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "ft_string.h"
#include "minishell.h"
#include "minishell_types.h"
#include "parser.h"
#include "parser_types.h"
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

int	minishell_should_exit(t_minishell_control *shell)
{
	return (0);
}

int	minishell_parse(t_minishell_control *shell)
{
	((t_parser *)shell->prs)->line = shell->input;
	parser_line_init(shell->prs);
	shell->preparsed = ((t_parser*)shell->prs)->preparsed;
	if (shell->preparsed == NULL || shell->preparsed->count == 0)
		return (
		printf("minishell_parse: shell->preparsed == NULL || shell->preparsed->count == 0\n"),
		1);
	if (minishell_execute(shell))
		return (
		printf("minishell_parse: minishell_execute(shell)\n"),
		parser_line_cleanup(shell->prs), 1);

	add_history(shell->input);

	return (parser_line_cleanup(shell->prs), 0);
}

void	minishell_loop(t_minishell_control *shell)
{
	printf("minishell_loop %p\n", shell);
	while (1)
	{
		if (minishell_prompt(shell) || minishell_parse(shell)
			|| minishell_should_exit(shell))
			break ;
	}
	printf("minishell_loop end\n");
}
