/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_node_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 10:19:30 by bgoulard          #+#    #+#             */
/*   Updated: 2024/08/18 10:19:58 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_types.h"

void	call_destroy(void *data)
{
	t_preparsed_node	*token;

	token = data;
	if (token && token->destroy)
		token->destroy(token);
}
