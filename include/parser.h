/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 18:19:05 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/14 15:56:12 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "parser_types.h"
# include "minishell_types.h"
# include "ft_vector_types.h"

int	parser_glob_cleanup(t_parser *prs);
int	parser_line_cleanup(t_parser *prs);

int	parser_glob_init(t_parser *prs);
int	parser_line_init(t_parser *prs);
t_cmd	*parser_get_cmd(t_vector *preparsed_tokens, t_minishell_control *sh);
t_preparsed_node	*preparsed_node_factory(t_tok_type type);

// File: src/parser/tok_func/tok_eol/isok.c
bool	isok_eol(const char *line, t_preparser_context *ctx);

// File: src/parser/tok_func/tok_eol/print.c
void	prepn_eol_print(t_preparsed_node *node);

// File: src/parser/tok_func/tok_eol/create.c
bool	prepn_eol_create(t_preparsed_node *node, const char *line, size_t offset);

// File: src/parser/tok_func/tok_eol/update_lb.c
bool	prepn_eol_update_line_buffer(t_preparsed_node *node, const char *line, size_t *offset);

// File: src/parser/tok_func/tok_eol/append.c
bool	prepn_eol_append(t_preparsed_node *node, const char *line, size_t offset);

// File: src/parser/tok_func/tok_space/append.c
bool	prepn_space_append(t_preparsed_node *node, const char *line, size_t offset);

// File: src/parser/tok_func/tok_space/isok.c
bool	isok_space(const char *line, t_preparser_context *ctx);

// File: src/parser/tok_func/tok_space/create.c
bool	prepn_space_create(t_preparsed_node *node, const char *line, size_t offset);

// File: src/parser/tok_func/tok_space/print.c
void	prepn_space_print(t_preparsed_node *node);

// File: src/parser/tok_func/tok_space/update_lb.c
bool	prepn_space_update_line_buffer(t_preparsed_node *node, const char *line, size_t *offset);

// File: src/parser/tok_func/tok_word/append.c
bool	prepn_word_append(t_preparsed_node *node, const char *line, size_t offset);

// File: src/parser/tok_func/tok_word/create.c
bool	prepn_word_create(t_preparsed_node *node, const char *line, size_t offset);

// File: src/parser/tok_func/tok_word/isok.c
bool	isok_word(const char *line, t_preparser_context *ctx);

// File: src/parser/tok_func/tok_word/print.c
void	prepn_word_print(t_preparsed_node *node);

// File: src/parser/tok_func/tok_word/update_lb.c
bool	prepn_word_update_line_buffer(t_preparsed_node *node, const char *line, size_t *offset);

#endif
