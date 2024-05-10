/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_types.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 22:36:53 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/09 23:34:48 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_TYPES_H
# define PARSER_TYPES_H

# include "ft_vector_types.h"

typedef enum e_token_type {
	TOKEN_SPACE = 0, // ' ' '\t' '\v' '\f' '\r'
	TOKEN_EOL, // '\n'
	TOKEN_QUOTE_ALL, // '\'' '"'
	TOKEN_BACKSLASH, // '\\'
	TOKEN_PIPE, // '|'
	TOKEN_SEMICOLON, // ';'
	TOKEN_REDIRECTION, // '<' '>' '>>' '<<'
	TOKEN_REDIRECTION_REF, // '>&' '<&'
	TOKEN_BACKGROUD, // '&\n' *only at the end of the line*
	TOKEN_STRING_EXPANSION, // '$'
	TOKEN_SUBSHELL, // '(' ')'
	TOKEN_OR, // '||'
	TOKEN_AND, // '&&'
	TOKEN_EOF, // '\0'
	TOKEN_UNKNOWN_ERROR // unknow error // keep last used for error handling
}	t_token_type;

typedef enum e_quote {
	QUOTE_NONE = 0,
	QUOTE_SINGLE,
	QUOTE_DOUBLE
}	t_quote;

typedef struct s_parser {
	size_t		str_offset;
	size_t		word_offset;
	t_quote		quote;
	t_vector	*words;
	t_vector	*tokens_handlers;
}	t_parser;

typedef struct s_token {
	t_token_type	type;
	char			token[2];
	void			handler(const char *str, t_parser *words);
}	t_token;

#endif /* PARSER_TYPES_H */
