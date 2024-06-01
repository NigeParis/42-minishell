/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_core.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 12:25:28 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/20 11:44:14 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_addons.h"
#include "ft_string.h"
#include "ft_vector.h"
#include "parser_types.h"

int	tokencmp_by_token(const void *token, const void *str)
{
	t_token	*t;
	char	*s;

	t = (t_token *)token;
	s = (char *)str;
	return (ft_strncmp(t->token, s, ft_min(ft_strlen(s), t->flag)));
}

size_t	search_next_token(const char *str, t_parser *prs)
{
	const size_t	m_len = ft_strlen(str);
	t_token			*token;
	size_t			len;

	len = 0;
	token = NULL;
	while (len < m_len && token == NULL)
	{
		token = (t_token *)ft_vec_get(prs->tokens_handlers, str + len,
				tokencmp_by_token);
		if (token == NULL)
		{
			len++;
			continue ;
		}
		if (token->type == TOKEN_SPACE && prs->quote != QUOTE_NONE)
		{
			token = NULL;
			len++;
		}
	}
	return (len);
}

t_token_type	get_token_type(char *str, t_parser *prsr)
{
	size_t	i;
	t_token	*token;

	i = 0;
	while (prsr->tokens_handlers->count > i)
	{
		token = (t_token *)ft_vec_at(prsr->tokens_handlers, i);
		if (!ft_strncmp(str, token->token, token->flag))
			return (token->type);
		i++;
	}
	return (TOKEN_UNKNOWN_ERROR);
}

size_t	get_token_handler(const char *str, const t_parser *restrict prs)
{
	size_t	i;
	t_token	*token;

	i = 0;
	while (prs->tokens_handlers->count > i)
	{
		token = (t_token *)ft_vec_at(prs->tokens_handlers, i);
		if (!ft_strncmp(str, token->token, token->flag))
			return (i);
		i++;
	}
	return (TOKEN_UNKNOWN_ERROR);
}

void	token_handler(size_t token_t, const char *str, t_parser *prs,
					t_vector *env)
{
	t_token	*token;

	if (token_t == TOKEN_UNKNOWN_ERROR)
		return ;
	token = (t_token *)ft_vec_at(prs->tokens_handlers, token_t);
//	token->handler(str, prs);
	prs->str_offset += token->flag;
}
