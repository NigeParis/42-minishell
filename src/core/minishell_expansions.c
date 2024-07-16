/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_expansions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 10:46:48 by bgoulard          #+#    #+#             */
/*   Updated: 2024/07/16 12:36:17 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_addons.h"
#include "ft_char.h"
#include "ft_string.h"
#include "minishell.h"

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

static void	setup_len(size_t *len, size_t *i, const char *line)
{
	while (line[(*i)] && (ft_isalnum(line[(*i)]) || line[(*i)] == '_'))
	{
		(*len)++;
		(*i)++;
	}
	if ((*len) == 0 && (line[(*i)] == '?' || line[(*i)] == '$'))
	{
		(*len)++;
		(*i)++;
	}
}

static char	*set_value(t_string *key, t_minishell_control *sh)
{
	char	*value;

	if (ft_string_cmp(key, "?") == 0 || ft_string_cmp(key, "$") == 0 \
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
	return (value);
}

static int	resolve_dollarsign(char *line, t_minishell_control *sh,
		t_string *ret, size_t *cr_offset)
{
	t_string	*key;
	char		*value;
	size_t		len;
	size_t		i;

	i = 1;
	len = 0;
	setup_len(&len, &i, line);
	key = ft_string_from_n(line + 1, len);
	if (key == NULL)
		return (EXIT_FAILURE);
	value = set_value(key, sh);
	if (value == NULL)
		return (ft_string_destroy(&key), EXIT_FAILURE);
	ft_string_append(ret, value);
	*cr_offset += key->length + 1;
	ft_string_destroy(&key);
	free(value);
	return (EXIT_SUCCESS);
}

char	*resolve_raw_exp(char *line, t_minishell_control *shell)
{
	t_quote		ctx;
	size_t		cr_offset;
	size_t		buf_add;
	t_string	*ret_s;

	ctx = QUOTE_NONE;
	cr_offset = 0;
	buf_add = 0;
	ret_s = ft_string_new(1);
	if (!line || !ret_s)
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
