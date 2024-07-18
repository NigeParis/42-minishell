/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_expansions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 10:46:48 by bgoulard          #+#    #+#             */
/*   Updated: 2024/07/18 02:33:53 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_addons.h"
#include "ft_string.h"
#include "minishell.h"
#include "parser_types.h"

static void	update_ctx(t_quote *ctx, char c)
{
	if (*ctx == QUOTE_NONE)
	{
		if (c == '\'')
			*ctx = QUOTE_SQUOTE;
		if (c == '\"')
			*ctx = QUOTE_DQUOTE;
	}
	else if ((*ctx == QUOTE_SQUOTE && c == '\'') || \
	(*ctx == QUOTE_DQUOTE && c == '\"'))
		*ctx = QUOTE_NONE;
}

static bool	set_vars(t_quote *ctx, size_t *cr_offset, size_t *buf_add,
		t_string **ret_s)
{
	*ctx = QUOTE_NONE;
	*cr_offset = 0;
	*buf_add = 0;
	*ret_s = ft_string_new(1);
	if (*ret_s == NULL)
		return (false);
	return (true);
}

// || stop at first matched condition so if !line we dont alloc
char	*resolve_raw_exp(char *line, t_minishell_control *shell)
{
	t_quote		ctx;
	size_t		cr_offset;
	size_t		buf_add;
	t_string	*ret_s;

	if (!line || set_vars(&ctx, &cr_offset, &buf_add, &ret_s) == false)
		return (NULL);
	while (line[cr_offset])
	{
		if (line[cr_offset] == '$' && (ctx == QUOTE_NONE \
		|| ctx == QUOTE_DQUOTE))
		{
			if (ft_string_append_n(ret_s, line + buf_add, cr_offset - buf_add))
				return (ft_string_destroy(&ret_s), NULL);
			resolve_dollarsign(line + cr_offset, shell, ret_s, &cr_offset);
			buf_add = cr_offset;
			continue ;
		}
		if (ft_strchr("\'\"", line[cr_offset]))
			update_ctx(&ctx, line[cr_offset]);
		cr_offset++;
	}
	ft_string_append_n(ret_s, line + buf_add, cr_offset - buf_add);
	return (ft_string_to_str_inplace(&ret_s));
}
