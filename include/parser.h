/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 22:34:31 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/09 23:27:23 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "parser_types.h"

void	space_char(const char *str, t_parser *words);
void	quote_char(const char *str, t_parser *words);
void	backslash_char(const char *str, t_parser *words);
void	pipe_char(const char *str, t_parser *words);
void	semicolon_char(const char *str, t_parser *words);
void	redirection_char(const char *str, t_parser *words);

char	**parse_words(const char *str);


#endif
