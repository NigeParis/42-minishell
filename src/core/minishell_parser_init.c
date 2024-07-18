/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_parser_init.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 13:04:26 by bgoulard          #+#    #+#             */
/*   Updated: 2024/07/18 01:16:42 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "minishell.h"
#include "parser.h"

#include <stdlib.h>

int	minishell_parser_init(void *shell_d)
{
	t_minishell_control	*shell;

	shell = (t_minishell_control *)shell_d;
	shell->prs = malloc(sizeof(t_parser));
	if (shell->prs == NULL)
		return (EXIT_FAILURE);
	ft_bzero(shell->prs, sizeof(t_parser));
	((t_parser *)(shell->prs))->control = shell;
	return (parser_glob_init(shell->prs));
}
