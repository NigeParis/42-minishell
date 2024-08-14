/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_syntax.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 02:45:32 by bgoulard          #+#    #+#             */
/*   Updated: 2024/08/14 08:32:02 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_vector.h"
#include "parser_types.h"

void	print_syntax_error(t_syntax syntax)
{
	ft_putstr_fd("syntax error near unexpected token", STDERR_FILENO);
	if (syntax == PIPE)
		ft_putstr_fd(" '|'\n", STDERR_FILENO);
	else if (syntax == EOL)
		ft_putstr_fd(" '\\n'\n", STDERR_FILENO);
	else if (syntax == REDIR)
		ft_putstr_fd(" 'newline'\n", STDERR_FILENO);
	else if (syntax == WORD)
		ft_putstr_fd(" 'word'\n", STDERR_FILENO);
}

static t_syntax	loop_body(t_preparsed_node *token, int var[3])
{
	if ((token->type == TOK_PIPE || token->type == TOK_EOL) && \
	(!var[_SYN_CMD_WD] || var[_SYN_CTX] != 0))
		return ((t_syntax)token->type);
	if (token->type == TOK_REDIR)
		var[_SYN_CTX] = 1;
	if (token->type == TOK_WORD || token->type == TOK_QUOTE)
	{
		var[_SYN_CMD_WD]++;
		if (var[_SYN_CTX] == 1)
			var[_SYN_CMD_WD]--;
		var[_SYN_CTX] = 0;
	}
	if (token->type == TOK_PIPE)
		var[_SYN_CMD_WD] = 0;
	return (E_NONE);
}

t_syntax	syntax_check(t_vector *prep)
{
	int					var[3];
	t_preparsed_node	*token;
	t_syntax			ret;

	ft_bzero(var, sizeof(var));
	while (prep && (size_t)var[_SYN_IT] < prep->count)
	{
		token = ft_vec_at(prep, var[_SYN_IT]);
		ret = loop_body(token, var);
		if (ret != E_NONE)
			return (ret);
		var[_SYN_IT]++;
	}
	return (E_NONE);
}
