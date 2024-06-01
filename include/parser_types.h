/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_types.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 22:36:53 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/20 11:13:12 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_TYPES_H
# define PARSER_TYPES_H

# include "ft_vector_types.h"
#include "minishell_types.h"
# define TOKEN_MAX_SIZE 2

/*
 * Token types explanation:
	TOKEN_SPACE = 0,        // ' ' '\t' '\v' '\f' '\r'
	TOKEN_EOL,              // '\n'
	TOKEN_QUOTE_ALL,        // '\'' '"'
	TOKEN_BACKSLASH,        // '\\'
	TOKEN_PIPE,             // '|'
	TOKEN_SEMICOLON,        // ';'
	TOKEN_REDIRECTION,      // '<' '>' '>>' '<<'
	TOKEN_REDIRECTION_REF,  // '>&' '<&'
	TOKEN_BACKGROUD,        // '&\n' *only at the end of the line*
	TOKEN_STRING_EXPANSION, // '$'
	TOKEN_SUBSHELL,         // '(' ')'
	TOKEN_OR,               // '||'
	TOKEN_AND,              // '&&'
	TOKEN_EOF,              // '\0'
	TOKEN_UNKNOWN_ERROR     // unknow error // keep last used for error handling
 *
*/

typedef enum e_token_type
{
	TOKEN_SPACE = 0,
	TOKEN_EOL,
	TOKEN_QUOTE_ALL,
	TOKEN_BACKSLASH,
	TOKEN_PIPE,
	TOKEN_SEMICOLON,
	TOKEN_REDIRECTION,
	TOKEN_REDIRECTION_REF,
	TOKEN_BACKGROUD,
	TOKEN_STRING_EXPANSION,
	TOKEN_SUBSHELL,
	TOKEN_OR,
	TOKEN_AND,
	TOKEN_EOF,
	TOKEN_UNKNOWN_ERROR
}						t_token_type;

/*
 * Token flags explanation:
	TOK_FLG_SINGLE = 1 << 0, // signifies that said token is a
								// single character (e.g. ' ' '\t' '\v' '\f'...)
	TOK_FLG_DOUBLE = 1 << 1, // signifies that said token is a
								//	double character (e.g. '||' '&&' '>>' ...)
 *
*/

typedef enum e_tok_flags
{
	TOK_FLG_SINGLE = 1 << 0,
	TOK_FLG_DOUBLE = 1 << 1,
}						t_token_flag;

typedef enum e_quote
{
	QUOTE_NONE = 0,
	QUOTE_SINGLE,
	QUOTE_DOUBLE
}						t_quote;

typedef struct s_parser
{
	size_t				str_offset;
	size_t				word_offset;
	t_quote				quote;
	t_vector			*words;
	void				*control;
	t_vector			*tokens_handlers;
}						t_parser;

typedef struct s_parser_line
{
	char				*ptr_offset;
	t_token_type		type;
	t_parser			*parser;
}						t_parser_line;

typedef void			(*t_token_handler)(t_parser_line *line, t_cmd *cmd);
typedef bool			(*t_token_validator)(const char *str, t_parser *prs);

typedef struct s_token
{
	t_token_type		type;
	t_token_flag		flag;
	char				token[TOKEN_MAX_SIZE + 1];
	t_token_handler		handler;
	t_token_validator	validator;
}						t_token;

# undef t_token_handler
# undef t_token_validator

#endif /* PARSER_TYPES_H */
