/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_types.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 10:55:31 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/14 14:36:11 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_TYPES_H
# define PARSER_TYPES_H

# include "ft_list_types.h"
# include "ft_vector_types.h"
# include "minishell_types.h"

typedef struct s_parser					t_parser;
typedef struct s_token					t_token;
typedef struct s_redir					t_redir;
typedef t_vector						t_preparsed_cmd;
typedef struct s_cmd_to_exec			t_cmd_to_exec;
typedef struct s_preparser_context		t_preparser_context;
typedef struct s_preparsed_node			t_preparsed_node;

typedef bool							(*t_tok_is)\
			(const char *str, t_preparser_context *ctx);

typedef bool							(*t_preparsed_line_buffer_interact)\
			(t_preparsed_node *node, const char *line, size_t offset);

typedef bool							(*t_preparsed_line_buffer_update)\
			(t_preparsed_node *node, const char *line, size_t *offset);

typedef void							(*t_preparsed_apply)\
			(t_preparsed_node *node);

typedef enum e_tok_type
{
	TOK_WORD,
	TOK_SPACE,
	TOK_EOL,
	/*
	TOK_PIPE,
	TOK_SEMICOLON,
	TOK_AND,
	TOK_OR,
	TOK_REDIR,
	TOK_VAR_EXP,
	TOK_CMD_EXP,
	TOK_BACKSLASH,
	*/
	TOK_UNKNOWN,
}										t_tok_type;

typedef enum e_rdir_flag
{
	RDIR_FILE,
	RDIR_STD,
}										t_rdir_flag;

typedef enum e_rdir_type
{
	RDIR_INPUT,
	RDIR_OUTPUT,
	RDIR_TRUNC,
	RDIR_APPEND,
	RDIR_HEREDOC,
	RDIR_DUP,
}										t_rdir_type;

typedef enum e_quote
{
	QUOTE_NONE,
	QUOTE_DQUOTE,
	QUOTE_SQUOTE,
}										t_quote;

struct									s_token
{
	const t_tok_type					type;
	const char							*value;
	t_tok_is							validator;
};

struct									s_redir
{
	int									src_std;
	char								*src_file;
	t_rdir_flag							flag;
	t_rdir_type							rdir_type;
	char								*target_file;
	int									target_std;
};

struct									s_cmd_to_exec
{
	char								*cmd_path;
	char								**argv;
	int									ac;
	char								**env;
	int									status;
	t_list								*redir_to_do;
};

struct									s_preparsed_node
{
	t_tok_type							type;
	void								*value;
	t_preparsed_line_buffer_interact	create;
	t_preparsed_line_buffer_update		update_line_buffer;
	t_preparsed_line_buffer_interact	append;
	t_preparsed_apply					print;
};

struct									s_parser
{
	t_vector							*tokens;
	t_minishell_control					*control;
	char								*line;
	t_preparsed_cmd						*preparsed;
	t_cmd_to_exec						*res;
};

struct									s_preparser_context
{
	size_t								line_offset;
	char								*unexpected;
	t_token								*c_tok;
	t_token								*n_tok;
	t_quote								quote_ctx;
};

#endif /* PARSER_TYPES_H */
