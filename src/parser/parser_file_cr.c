/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_file_cr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 14:27:43 by bgoulard          #+#    #+#             */
/*   Updated: 2024/07/23 14:28:04 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include "parser_types.h"

#include <fcntl.h>

void	cr_file(int i, t_vector *prep)
{
	t_preparsed_node	*nd;
	t_redir				*redir;
	char				*fname;

	nd = ft_vec_at(prep, i);
	redir = nd->value;
	if ((redir->redir_type & RDIR_MSK_IO) == RDIR_INPUT)
		return ;
	if ((redir->redir_type & RDIR_MSK_IO) == RDIR_OUTPUT)
	{
		while (nd && (nd->type != TOK_WORD && nd->type != TOK_QUOTE))
			nd = ft_vec_at(prep, i++);
		if (nd->type == TOK_WORD)
			fname = ((t_string *)nd->value)->str;
		else if (nd->type == TOK_QUOTE)
			fname = ((t_quote_node *)nd->value)->value->str;
		if ((redir->redir_type & RDIR_MSK_MODE) == RDIR_TRUNC)
			open(fname, O_WRONLY | O_TRUNC | O_CREAT, 0644);
		else if ((redir->redir_type & RDIR_MSK_MODE) == RDIR_APPEND)
			open(fname, O_WRONLY | O_APPEND | O_CREAT, 0644);
	}
}

void	file_creation(t_vector *prep)
{
	t_preparsed_node	*token;
	int					i;

	i = 0;
	while (prep && (size_t)i < prep->count)
	{
		token = ft_vec_at(prep, i);
		if (token->type == TOK_REDIR)
			cr_file(i, prep);
		i++;
	}
}
