/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nd2ex_wd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:38:54 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/20 15:59:01 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_char.h"
#include "ft_string.h"
#include "ft_vector.h"
#include "minishell.h"
#include "minishell_types.h"
#include "parser_types.h"
#include <stdio.h>
#include <stdlib.h>

void ft_string_del_ch(t_string *str, size_t index, size_t len)
{
	if (index + len > str->length)
		len = str->length - index;
	ft_memmove(str->str + index, str->str + index + len, str->length - index - len);
	str->length -= len;
	str->str[str->length] = '\0';
}

static char *get_key(t_string *word, size_t *i)
{
	size_t		j;
	char		*key;

	*i += 1;
	j = *i;
	if (j == *i && word->str[j] == '?')
		return (*i += 1, ft_strdup("?"));
	else if (word->str[j] == '$')
		return (*i += 1, ft_strdup("$"));
	else if (word->str[j] == '\0' || ft_isspace(word->str[j]))
		return (ft_strdup(""));
	while (ft_isalnum(word->str[j]) || word->str[j] == '_')
		j++;
	key = ft_strndup(word->str + *i, j - *i);
	*i = j;
	return (key);
}

bool	resolve_doll(t_string *word, t_minishell_control *sh, t_string *tmp, size_t *i)
{
	char *key = get_key(word, i);
	char *value;
	char *no_leaks;

	value = NULL;
	if (!key)
		return (false);
	if (ft_strncmp(key, "?", 2) == 0)
		value = ft_itoa(sh->exit);
	else if (ft_strncmp(key, "$", 2) == 0)
		value = ft_itoa(getpid());
	else if (key[0] == '\0')
		value = ft_strdup("$");
	no_leaks = value;
	if (!value)
		value = get_env(sh->env, key);
	if (DEBUG_LVL >= 2)
		printf("key: %s, value: %s\n", key, value);
	if (value)
		ft_string_append(tmp, value);
	if (no_leaks)
		free(no_leaks);
	return (free(key), true);
}

void	resolve_word(t_string **word, t_minishell_control *sh)
{
	size_t		i;
	t_string	*tmp;

	i = 0;
	tmp = ft_string_new((*word)->length); // check if this fails
	while (i < (*word)->length)
	{
		if ((*word)->str[i] == '\\')
			ft_string_append_c(tmp, (*word)->str[i++ + 1]); // check if this fails
		else if ((*word)->str[i] == '$' && !resolve_doll(*word, sh, tmp, &i))
		{
			return ; //  return false if resolve_doll fails
		}
		else
			ft_string_append_c(tmp, (*word)->str[i]); // check if this fails
		i++;
	}
	ft_string_destroy(word);
	*word = tmp;
}

bool	nd2ex_word(t_preparsed_node *nd, t_cmd_to_exec *cmd, t_minishell_control *sh)
{
	char *str[2];

	if (!nd->value)
		return (false);
	resolve_word((t_string **)&nd->value, sh);
	if (cmd->construction_vector->count < cmd->construction_index)
		ft_vec_add(&cmd->construction_vector, ft_strdup(""));
	str[0] = ft_vec_pop(cmd->construction_vector);
	str[1] = str[0];
	if (!str[0])
		str[0] = ft_string_to_str(nd->value);
	else
		str[0] = ft_strjoin(str[1], ft_string_to_str(nd->value));
	if (str[1])
		free(str[1]);
	return (ft_string_destroy((t_string**)&nd->value), \
	ft_vec_add(&cmd->construction_vector, str[0]), free(nd), true);
}
