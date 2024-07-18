/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_syntax.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 02:45:32 by bgoulard          #+#    #+#             */
/*   Updated: 2024/07/18 02:46:03 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_vector.h"
#include "parser_types.h"

#include <stdio.h>

void	print_syntax_error(t_syntax syntax)
{
	printf("Syntax error near unexpected token");
	if (syntax == PIPE)
		printf(" '|'\n");
	else if (syntax == EOL)
		printf(" '\\n'\n");
	else if (syntax == REDIR)
		printf(" 'newline'\n");
	else if (syntax == WORD)
		printf(" 'word'\n");
}

t_syntax	syntax_check(t_vector *prep)
{
	int					var[3];
	t_preparsed_node	*token;

	ft_bzero(var, sizeof(var));
	while (prep && (size_t)var[_SYN_IT] < prep->count)
	{
		token = ft_vec_at(prep, var[_SYN_IT]);
		if ((token->type == TOK_PIPE || token->type == TOK_EOL) && \
		(!var[_SYN_CMD_WD] || var[_SYN_CTX] != 0))
			return ((t_syntax)token->type);
		if (token->type == TOK_REDIR)
			var[_SYN_CTX] = 1;
		if (token->type == TOK_WORD || token->type == TOK_QUOTE)
		{
			var[_SYN_CMD_WD]++;
			var[_SYN_CTX] = 0;
		}
		if (token->type == TOK_PIPE)
			var[_SYN_CMD_WD] = 0;
		var[_SYN_IT]++;
	}
	return (E_NONE);
}
