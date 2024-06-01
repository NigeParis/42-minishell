/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 22:34:31 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/20 11:38:45 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "ft_vector_types.h"
#include "minishell_types.h"
# include "parser_types.h"

/// @file: src/parser/init_parser.c
int				parser_init_tokens_handlers(t_parser *prs);
int				init_parser_line(t_parser *prs);

/// @file: src/parser/parser_cleanup.c
void			parser_cleanup(t_parser *prs);
void			parser_cleanup_final(t_parser *prs);

/// @file: src/parser/parse_words.c
t_vector *preparse_cmds(const char *str, t_parser *parser);

/// @file: src/parser/token_core.c
int				tokencmp_by_token(const void *token, const void *str);
size_t			search_next_token(const char *str, t_parser *prs);
t_token_type	get_token_type(char *str, t_parser *prsr);
size_t			get_token_handler(const char *str, const t_parser *prs);
void			token_handler(size_t token_t, const char *str, t_parser *prs);

/*
** Token handlers and validators
*/

// [a - z0 - 9A - Z_-]
//		1: simple word
/// @file: src/parser/exec_tok/tok_none.c
void			bulk_add_char(t_parser *words, const char *str, int len,
					t_vector *env);
// '\'' '"'
// 		1: single quote
// 		2: double quote
/// @file: src/parser/exec_tok/tok_quotes.c
void			tok_han_quote(t_parser_line *line, t_cmd *cmd);
/// @file: src/parser/validity_tok/tok_quotes.c
bool			tok_val_quote(const char *str, t_parser *parser);

// [' ' '\t' '\v' '\r' '\f' '\n']
// 		1: space
/// @file: src/parser/exec_tok/tok_space.c
void			tok_han_space(t_parser_line *line, t_cmd *cmd);
/// @file: src/parser/validity_tok/tok_space.c
bool			tok_val_space(const char *s, t_parser *parser);

// '$' '$?' '$$' '${' '$('
//		1: simple variable expansion
//		2: exit status expansion
//		3: pid expansion
//		4: parameter expansion with braces as delimiters
//		5: command substitution with parentheses as delimiters
/// @file: src/parser/exec_tok/tok_varexpansion.c
void			tok_han_doll(t_parser_line *line, t_cmd *cmd);
/// @file: src/parser/validity_tok/tok_varexpansion.c
bool			tok_val_doll(const char *s, t_parser *parser);

#endif
