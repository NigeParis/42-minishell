/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tok_none.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 12:27:26 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/11 14:42:57 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_vector.h"
#include "ft_vector_types.h"
#include "parser_types.h"

void	bulk_add_char(t_parser *words, const char *str, int len, t_vector *env)
{
	char	*tmp[3];

	tmp[0] = ft_strndup(str + words->str_offset, len);
	tmp[1] = ft_vec_at(words->words, words->word_offset);
	tmp[2] = ft_strjoin(tmp[1], tmp[0]);
	((char **)words->words->datas)[words->word_offset] = tmp[2];
	free(tmp[0]);
	free(tmp[1]);
	words->words->count = words->word_offset + 1;
	words->str_offset += len;
}
