/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens_funcs.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 12:15:48 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/15 15:50:02 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENS_FUNCS_H
# define TOKENS_FUNCS_H

# include "parser_types.h"

bool	isok_quote(const char *line, t_preparser_context *ctx);
bool	isok_space(const char *line, t_preparser_context *ctx);
bool	isok_word(const char *line, t_preparser_context *ctx);
bool	isok_eol(const char *line, t_preparser_context *ctx);

// Files: src/parser/tok_func/tok_quote/*
void	prepn_quote_print(t_preparsed_node *node);
bool	prepn_quote_append(t_preparsed_node *nd, t_preparser_context *ctx);
bool	prepn_quote_create(t_preparsed_node *node, t_preparser_context *ctx);
bool	prepn_quote_update_line_buffer(t_preparsed_node *node, t_preparser_context *ctx);

// Files: src/parser/tok_func/tok_eol/*
void	prepn_eol_print(t_preparsed_node *node);
bool	prepn_eol_append(t_preparsed_node *nd, t_preparser_context *ctx);
bool	prepn_eol_create(t_preparsed_node *node, t_preparser_context *ctx);
bool	prepn_eol_update_line_buffer(t_preparsed_node *node, t_preparser_context *ctx);

// Files: src/parser/tok_func/tok_space/*
void	prepn_space_print(t_preparsed_node *node);
bool	prepn_space_append(t_preparsed_node *node, t_preparser_context *ctx);
bool	prepn_space_create(t_preparsed_node *node, t_preparser_context *ctx);
bool	prepn_space_update_line_buffer(t_preparsed_node *node, t_preparser_context *ctx);

// Files: src/parser/tok_func/tok_word/*
void	prepn_word_print(t_preparsed_node *node);
bool	prepn_word_create(t_preparsed_node *node, t_preparser_context *ctx);
bool	prepn_word_append(t_preparsed_node *node, t_preparser_context *ctx);
bool	prepn_word_update_line_buffer(t_preparsed_node *node, t_preparser_context *ctx);

#endif
