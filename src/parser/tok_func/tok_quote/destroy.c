/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 14:30:49 by bgoulard          #+#    #+#             */
/*   Updated: 2024/07/03 14:28:22 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "parser_types.h"
#include <stdlib.h>

void	destroy_quote(t_preparsed_node *node)
{
	t_quote_node	*quote;

	quote = (t_quote_node *)node->value;
	ft_string_destroy(&quote->value);
	free(quote);
	free(node);
	return ;
}
