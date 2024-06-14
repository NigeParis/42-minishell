/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_glob_cleanup.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 10:54:51 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/13 13:45:09 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include "parser_types.h"
#include <stdlib.h>

int	parser_glob_cleanup(t_parser *prs)
{
	if (prs->tokens)
		ft_vec_destroy(&prs->tokens);
	return (EXIT_SUCCESS);
}
