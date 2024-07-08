/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_expansions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 10:46:48 by bgoulard          #+#    #+#             */
/*   Updated: 2024/07/08 11:36:07 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_addons.h"
#include "ft_char.h"
#include "ft_string.h"
#include "ft_string_types.h"
#include "minishell.h"
#include "minishell_types.h"
#include "parser_types.h"
#include <stdio.h>

static void update_ctx(t_quote *ctx, char c)
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

static void	resolve_dollarsign(char *line, t_minishell_control *sh, 
			t_string *ret, size_t *cr_offset)
{
	t_string	*key;
	char		*value;
	size_t		len;
	size_t		i;

	i = 1;
	len = 0;
	while (line[i] && (ft_isalnum(line[i]) || line[i] == '_'))
		(len++, i++);
	if (len == 0 && (line[i] == '?' || line[i] == '$'))
		(len++, i++);
	key = ft_string_from_n(line + 1, len);
	if (ft_string_cmp(key, "?") == 0 || ft_string_cmp(key, "$") == 0
	|| ft_string_cmp(key, "") == 0)
	{
		value = NULL;
		if (ft_string_cmp(key, "?") == 0)
			value = ft_itoa(sh->exit);
		else if (ft_string_cmp(key, "$") == 0)
			value = ft_itoa(getpid());
		else
			value = ft_strdup("$");
	}
	else
	{
		value = get_env(sh->env, key->str);
		if (value == NULL)
			value = ft_strdup("");
		else
			value = ft_strdup(value);
	}
	ft_string_append(ret, value);
	*cr_offset += key->length + 1;
	ft_string_destroy(&key);
	free(value);
	return ;
}

char *resolve_raw_exp(char *line, t_minishell_control *shell)
{
	t_quote		ctx;
	size_t		cr_offset;
	size_t		buff_add;
	t_string	*ret_s;

	cr_offset = 0;
	ctx = QUOTE_NONE;
	buff_add = 0;
	if (!line)
		return (line);
	ret_s = ft_string_new(1);
	while (line[cr_offset])
	{
		if (line[cr_offset] == '$' && (ctx == QUOTE_NONE \
		|| ctx == QUOTE_DQUOTE))
		{
			ft_string_append_n(ret_s, line + buff_add, cr_offset - buff_add);
			resolve_dollarsign(line + cr_offset, shell, ret_s, &cr_offset);
			buff_add = cr_offset;
			continue ;
		}
		if (ft_strchr("\'\"", line[cr_offset]))
			update_ctx(&ctx, line[cr_offset]);
		cr_offset++;
	}
	ft_string_append_n(ret_s, line + buff_add, cr_offset - buff_add);
	return (ft_string_to_str_inplace(&ret_s));
}
