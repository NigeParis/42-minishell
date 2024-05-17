/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tok_varexpansion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 13:25:18 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/17 13:27:23 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "minishell_types.h"
#include "parser.h"
#include "ft_string.h"

static char	*get_varname(char *str)
{
	int		i;
	char	*varname;

	i = 0;
	while (str[i] && str[i] != '$' && str[i] != ' ')
		i++;
	varname = ft_substr(str, 0, i);
	return (varname);
}

void	token_doll_handler(const char *str, t_parser *prs)
{
	const t_minishell_control	*control = (t_minishell_control *)prs->control;
	char						*tmp[4];

	tmp[3] = ((char **)prs->words->datas)[prs->word_offset];
	if (prs->quote != QUOTE_NONE)
		return (bulk_add_char(prs, str, 1));
	if (str[1] == '?')
	{
		tmp[0] = ft_strdup("?");
		tmp[1] = ft_itoa(control->ret);
	}
	else
	{
		tmp[0] = get_varname((char *)str + 1);
		tmp[1] = get_env(control->env, tmp[0]);
	}
	tmp[2] = ft_strjoin(((char **)prs->words->datas)[prs->word_offset], tmp[1]);
	prs->str_offset += ft_strlen(tmp[0]);
	((char **)prs->words->datas)[prs->word_offset] = tmp[2];
	return (free(tmp[0]), free(tmp[3]));
}
