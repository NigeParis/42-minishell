/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nd2ex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:38:54 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/20 16:00:11 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_vector.h"
#include "parser_types.h"
#include <stdlib.h>

void	resolve_word(t_string **word, t_minishell_control *sh);

bool	nd2ex_quote(t_preparsed_node *nd, t_cmd_to_exec *cmd, t_minishell_control *sh)
{
	t_quote_node	*quote;
	char			*str[2];

	if (nd->type != TOK_QUOTE || nd->value == NULL)
		return (false);
	quote = nd->value;
	if (quote->type == QUOTE_DQUOTE)
		resolve_word(&quote->value, sh);
	if (cmd->construction_vector->count < cmd->construction_index)
		ft_vec_add(&cmd->construction_vector, ft_strdup(""));
	str[0] = ft_vec_pop(cmd->construction_vector);
	str[1] = str[0];
	if (!str[0])
		str[0] = ft_string_to_str(quote->value);
	else
		str[0] = ft_strjoin(str[1], ft_string_to_str(quote->value));
	if (str[1])
		free(str[1]);
	return (ft_string_destroy((t_string**)&quote->value), \
	ft_vec_add(&cmd->construction_vector, str[0]), free(quote), free(nd), true);
}
