/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 12:56:38 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/10 08:10:40 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_types.h"
#include "parser_types.h"
#include "ft_string.h"
#include "ft_vector.h"
#include "ft_addons.h"
#include "parser.h"

void	bulk_add_char(t_words *words, const char *str, int len)
{
	char *tmp[3];

	tmp[0] = ft_strndup(str + words->str_offset, len);
	tmp[1] = ft_vec_at(words->words, words->word_offset);
	tmp[2] = ft_strjoin(tmp[1], tmp[0]);
	((char **)words->words->datas)[words->word_offset] = tmp[2];
	free(tmp[0]);
	free(tmp[1]);
	words->str_offset += len;
}

int	tokencmp_by_token(const void *token, const void *str)
{
	return (ft_strncmp(((t_token *)token)->token, (char *)str, 2));
}

size_t	search_next_token(const char *str, t_parser *prs)
{
	const size_t	m_len = ft_strlen(str + prs->str_offset);
	t_token			*token;
	char			tmp[3];
	size_t			len;

	len = 0;
	ft_bzero(tmp, 3);
	while ((len + 2) < m_len)
	{
		ft_memcpy(tmp, str + prs->str_offset + len, 2);
		token = (t_token *)ft_vector_get(prs->tokens_handlers, tmp, tokencmp_by_token);
		if (token != NULL)
			return (len);
		len++;
	}
	return (len);
}

t_token_type	get_token_type(char *str, t_parser *prsr)
{
	size_t i;

	i = 0;
	while (prsr->tokens_handlers->count > i)
	{
		if (!ft_strncmp(str, \
		((t_token *)ft_vec_at(prsr->tokens_handlers, i))->token, 2))
			return (((t_token *)ft_vec_at(prsr->tokens_handlers, i))->type);
		i++;
	}
	return (TOKEN_UNKNOWN_ERROR);
}

size_t	get_token_handler(const char *str, const t_parser *restrict prs)
{
	size_t i;

	i = 0;
	while (prs->tokens_handlers->count > i)
	{
		if (!ft_strncmp(str, \
		((t_token *)ft_vec_at(prs->tokens_handlers, i))->token, 2))
			return (i);
		i++;
	}
	return (TOKEN_UNKNOWN_ERROR);
}

void	token_handler(size_t token_t, const char *str, t_parser *prs)
{
	if (token_t == TOKEN_UNKNOWN_ERROR)
		return ;
	((t_token *)ft_vec_at(prs->tokens_handlers, token_t))->handler(str, prs);
}

int	init_parser(t_parser *prs)
{
	ft_bzero(prs, sizeof(t_parser));
	prs->words = ft_vec_new();
	prs->tokens_handlers = ft_vec_new();
	parser_init_tokens_handlers(prs);
	return (0);
}

// replace this - temporary
char	**parse_words(const char *str)
{
	t_parser	parser;
	int			next_token;
	size_t		token_t;
	char		**ret;

	init_parser(&parser);
	while (str[parser.str_offset])
	{
		next_token = search_next_token(str + parser.str_offset, &parser); 
		if (next_token != 0)
			bulk_add_char(&parser, str, next_token);
		else
		{
			token_t = get_token_handler(str + parser.str_offset, &parser);
			token_handler(token_t, str + parser.str_offset, &parser);
		}
	}
	ret = (char **)ft_vec_to_array(&parser.words);
	return (ret);
}

int	parser(t_minishell_control *ctrl, char *str)
{
	ctrl->input = str;
	ctrl->words = parse_words(ctrl->input);
	return (0);
}
