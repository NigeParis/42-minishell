/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 22:34:31 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/17 13:23:37 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "ft_vector_types.h"
# include "parser_types.h"

// File: src/parser/init_parser.c
int				parser_init_tokens_handlers(t_parser *prs);
int				init_parser_line(t_parser *prs);

// File: src/parser/parser_cleanup.c
void			parser_cleanup(t_parser *prs);
void			parser_cleanup_final(t_parser *prs);

// File: src/parser/parser_main.c
// dependant of minishell_types.h not parser.h
// bridge function
// int	parser(t_minishell_control *ctrl, char *str);

// File: src/parser/parse_words.c
char			**parse_words(const char *str, t_parser *prs);

// File: src/parser/token_core.c
int				tokencmp_by_token(const void *token, const void *str);
size_t			search_next_token(const char *str, t_parser *prs);
t_token_type	get_token_type(char *str, t_parser *prsr);
size_t			get_token_handler(const char *str, const t_parser *prs);
void			token_handler(size_t token_t, const char *str, t_parser *prs);

// File: src/parser/tokens/tok_none.c
void			bulk_add_char(t_parser *words, const char *str, int len);

// File: src/parser/tokens/tok_quotes.c
void			token_quote_all_handler(const char *str, t_parser *prs);

// File: src/parser/tokens/tok_space.c
void			token_space_handler(const char *str, t_parser *prs);

// File: src/parser/tokens/tok_varexpansion.c
void			token_doll_handler(const char *str, t_parser *prs);

#endif
