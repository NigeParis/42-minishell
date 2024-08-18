/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 18:19:05 by bgoulard          #+#    #+#             */
/*   Updated: 2024/08/18 10:33:01 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "parser_types.h"
# include "minishell_types.h"
# include "ft_vector_types.h"

void				file_creation(t_vector *prep);

int					update_preparsed(t_parser *restrict p,
						t_preparser_context *restrict ctx);
int					update_context(t_parser *restrict p,
						t_preparser_context *restrict ctx);
void				preparser_destroy(t_preparser_context *restrict c,
						t_parser *restrict p);

void				get_next_token(t_parser *p, t_preparser_context *ctx);

int					parser_glob_cleanup(t_parser *prs);
int					parser_line_cleanup(t_parser *prs);

int					parser_glob_init(t_parser *prs);
int					parser_line_init(t_parser *prs);

void				call_destroy(void *data);
t_cmd_to_exec		*parser_get_cmd(t_vector *preparsed_tokens,
						t_minishell_control *sh);
t_preparsed_node	*preparsed_node_factory(t_tok_type type);

bool				resolve_word(t_string **word, t_minishell_control *sh);

void				print_syntax_error(t_syntax syntax);
t_syntax			syntax_check(t_vector *prep);

#endif
