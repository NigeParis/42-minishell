/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_dollarsign.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 02:31:53 by bgoulard          #+#    #+#             */
/*   Updated: 2024/08/14 15:37:08 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_char.h"
#include "ft_string.h"
#include "minishell.h"

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

int	special_cases(char *line, t_string *ret, size_t *cr_offset)
{
	int		i;

	i = 1;
	*cr_offset += 1;
	if (line[i] == ' ' || line[i] == '\0')
	{
		if (line[i] == ' ' && ft_string_append(ret, "$ ") == -1)
			return (EXIT_FAILURE);
		else if (line[i] == '\0' && ft_string_append(ret, "$") == -1)
			return (EXIT_FAILURE);
		if (line[i] == ' ')
			*cr_offset += 1;
	}
	return (EXIT_SUCCESS);
}

int	resolve_dollarsign(char *line, t_minishell_control *sh, t_string *ret,
		size_t *cr_offset)
{
	t_string	*key;
	char		*value;
	size_t		len;
	size_t		i;

	i = 1;
	len = 0;
	setup_len(&len, &i, line);
	if (len == 0 && i == 1)
		return (special_cases(line, ret, cr_offset));
	key = ft_string_from_n(line + 1, len);
	if (key == NULL)
		return (EXIT_FAILURE);
	value = set_value(key, sh);
	if (value == NULL)
		return (ft_string_destroy(&key), EXIT_FAILURE);
	if (ft_string_append(ret, value) == -1)
		return (ft_string_destroy(&key), free(value), EXIT_FAILURE);
	*cr_offset += key->length + 1;
	ft_string_destroy(&key);
	free(value);
	return (EXIT_SUCCESS);
}
