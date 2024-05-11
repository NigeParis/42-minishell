/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_parser_init.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 13:04:26 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/11 09:57:09 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "minishell.h"
#include "minishell_types.h"
#include "parser.h"
#include "parser_types.h"
#include <stdlib.h>

int	minishell_parser_init(void *shell_d)
{
	t_minishell_control	*shell;

	shell = (t_minishell_control *)shell_d;
	shell->prs = malloc(sizeof(t_parser));
	if (shell->prs == NULL)
		return (EXIT_FAILURE);
	ft_bzero(shell->prs, sizeof(t_parser));
	parser_init_tokens_handlers(shell->prs);
	return (EXIT_SUCCESS);
}
