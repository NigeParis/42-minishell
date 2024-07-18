/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nd2ex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:38:54 by bgoulard          #+#    #+#             */
/*   Updated: 2024/07/18 01:20:14 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_addons.h"
#include "ft_string.h"
#include "ft_vector.h"
#include "parser_types.h"

#include <stdlib.h>

bool	nd2ex_quote(t_preparsed_node *nd, t_cmd_to_exec *cmd, \
				t_minishell_control *sh)
{
	t_quote_node	*quote;
	char			*str[2];
	t_optional		op[2];

	if (nd->type != TOK_QUOTE || nd->value == NULL)
		return (false);
	quote = nd->value;
	str[0] = ft_vec_at(cmd->construction_vector, cmd->construction_index);
	ft_optional_init(&op[0], str[0]);
	ft_optional_init(&op[1], ((t_string *)quote->value)->str);
	str[1] = optional_strjoin(&op[0], &op[1]);
	if (op[0].pres == OPT_SOME)
		(ft_vec_pop(cmd->construction_vector), free(op[0].val));
	ft_vec_add(&cmd->construction_vector, str[1]);
	ft_string_destroy((t_string **)&quote->value);
	free(quote);
	free(nd);
	return (true);
}
