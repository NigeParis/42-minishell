/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens_funcs.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 12:15:48 by bgoulard          #+#    #+#             */
/*   Updated: 2024/07/03 17:09:17 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENS_FUNCS_H
# define TOKENS_FUNCS_H

# include "minishell_types.h"
# include "parser_types.h"

// >> todo <<

bool	isok_quote(const char *line, t_preparser_context *ctx);
bool	isok_space(const char *line, t_preparser_context *ctx);
bool	isok_word(const char *line, t_preparser_context *ctx);
bool	isok_eol(const char *line, t_preparser_context *ctx);
bool	isok_pipe(const char *line, t_preparser_context *ctx);
bool	isok_redir(const char *line, t_preparser_context *ctx);

// Files: src/parser/tok_func/tok_quote/*
void	prepn_quote_print(t_preparsed_node *node);
bool	prepn_quote_append(t_preparsed_node *nd, t_preparser_context *ctx);
bool	prepn_quote_create(t_preparsed_node *node, t_preparser_context *ctx);
bool	prepn_quote_ulb(t_preparsed_node *node, t_preparser_context *ctx);
bool	nd2ex_quote(t_preparsed_node *node, t_cmd_to_exec *cmd,
			t_minishell_control *sh);
void	destroy_quote(t_preparsed_node *node);

// Files: src/parser/tok_func/tok_eol/*
void	prepn_eol_print(t_preparsed_node *node);
bool	prepn_eol_append(t_preparsed_node *nd, t_preparser_context *ctx);
bool	prepn_eol_create(t_preparsed_node *node, t_preparser_context *ctx);
bool	prepn_eol_ulb(t_preparsed_node *node, t_preparser_context *ctx);
bool	nd2ex_eol(t_preparsed_node *node, t_cmd_to_exec *cmd,
			t_minishell_control *sh);
void	destroy_eol(t_preparsed_node *node);

// Files: src/parser/tok_func/tok_space/*
void	prepn_space_print(t_preparsed_node *node);
bool	prepn_space_append(t_preparsed_node *node, t_preparser_context *ctx);
bool	prepn_space_create(t_preparsed_node *node, t_preparser_context *ctx);
bool	prepn_space_ulb(t_preparsed_node *node, t_preparser_context *ctx);
bool	nd2ex_space(t_preparsed_node *node, t_cmd_to_exec *cmd,
			t_minishell_control *sh);
void	destroy_space(t_preparsed_node *node);

// Files: src/parser/tok_func/tok_word/*
void	prepn_word_print(t_preparsed_node *node);
bool	prepn_word_create(t_preparsed_node *node, t_preparser_context *ctx);
bool	prepn_word_append(t_preparsed_node *node, t_preparser_context *ctx);
bool	prepn_word_ulb(t_preparsed_node *node, t_preparser_context *ctx);
bool	nd2ex_word(t_preparsed_node *node, t_cmd_to_exec *cmd,
			t_minishell_control *sh);
void	destroy_word(t_preparsed_node *node);

// Files: src/parser/tok_func/tok_pipe/*
void	prepn_pipe_print(t_preparsed_node *node);
bool	prepn_pipe_create(t_preparsed_node *node, t_preparser_context *ctx);
bool	prepn_pipe_append(t_preparsed_node *node, t_preparser_context *ctx);
bool	prepn_pipe_ulb(t_preparsed_node *node, t_preparser_context *ctx);
bool	nd2ex_pipe(t_preparsed_node *nd, t_cmd_to_exec *cmd,
			t_minishell_control *sh);
void	destroy_pipe(t_preparsed_node *node);

// Files: src/parser/tok_func/tok_redir/*
void	prepn_redir_print(t_preparsed_node *node);
bool	prepn_redir_create(t_preparsed_node *node, t_preparser_context *ctx);
bool	prepn_redir_append(t_preparsed_node *node, t_preparser_context *ctx);
bool	prepn_redir_ulb(t_preparsed_node *node, t_preparser_context *ctx);
bool	nd2ex_redir(t_preparsed_node *nd, t_cmd_to_exec *cmd,
			t_minishell_control *sh);
void	destroy_redir(t_preparsed_node *node);

#endif
