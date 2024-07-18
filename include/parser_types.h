/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_types.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 10:55:31 by bgoulard          #+#    #+#             */
/*   Updated: 2024/07/18 02:42:52 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_TYPES_H
# define PARSER_TYPES_H

// sub types needed

# include "ft_list_types.h"
# include "ft_string_types.h"
# include "ft_vector_types.h"
# include "minishell_types.h"

# define _SYN_IT		0
# define _SYN_CMD_WD	1
# define _SYN_CTX		2

// types definition for parser structs

typedef struct s_parser				t_parser;
typedef struct s_token				t_token;
typedef struct s_redir				t_redir;
typedef t_vector					t_preparsed_cmd;
typedef struct s_cmd_to_exec		t_cmd_to_exec;
typedef struct s_preparser_context	t_preparser_context;
typedef struct s_preparsed_node		t_preparsed_node;
typedef struct s_quote_node			t_quote_node;

// function pointer definition for parser structs (norminette mandatory)

typedef bool						(*t_tok_chek)(const char *line,
							t_preparser_context *ctx);

typedef bool						(*t_tok_action)(t_preparsed_node *nd,
							t_preparser_context *ctx);

typedef void						(*t_preparsed_apply)(
							t_preparsed_node *node);
typedef bool						(*t_preparsed_exec)(
							t_preparsed_node *node, t_cmd_to_exec *res,
							t_minishell_control *control);

// enum definition for parser structs

/* >> todo <<
TOK_SEMICOLON,
TOK_AND,
TOK_OR,
TOK_VAR_EXP,
TOK_CMD_EXP,
TOK_BACKSLASH,
*/
typedef enum e_tok_type
{
	TOK_PIPE,
	TOK_REDIR,
	TOK_WORD,
	TOK_SPACE,
	TOK_QUOTE,
	TOK_EOL,
	TOK_UNKNOWN,
}									t_tok_type;

typedef enum e_redir_flag
{
	RDIR_FILE,
	RDIR_STD,
}									t_redir_flag;

# define RDIR_MSK_IO 0x03
# define RDIR_MSK_MODE 0x0C
# define RDIR_MSK_DUP 0x10

/*
typedef enum e_redir_type
{
	RDIR_PIPE		= 1,		// 0 00 01
	RDIR_INPUT		= 2,		// 0 00 10
	RDIR_OUTPUT		= 3,		// 0 00 11
	RDIR_TRUNC		= 1 << 2,	// 0 01 00
	RDIR_APPEND		= 2 << 2,	// 0 10 00
	RDIR_HEREDOC	= 3 << 2,	// 0 11 00
	RDIR_DUP		= 1 << 4,	// 1 00 00 // >&
}									t_redir_type;
*/

typedef enum e_redir_type
{
	RDIR_PIPE		= 1,
	RDIR_INPUT		= 2,
	RDIR_OUTPUT		= 3,
	RDIR_TRUNC		= 1 << 2,
	RDIR_APPEND		= 2 << 2,
	RDIR_HEREDOC	= 3 << 2,
	RDIR_DUP		= 1 << 4,
}									t_redir_type;

/*
truc = RDIR_OUTPUT | RDIR_APPEND; // 0 00 11 | 0 10 00 
  // = 0 10 11
if (truc & RDIR_MSK_IO == RDIR_OUTPUT)
  // redirect output
*/
typedef enum e_quote
{
	QUOTE_NONE,
	QUOTE_DQUOTE,
	QUOTE_SQUOTE,
}									t_quote;

/*
 * enum for syntax checking
 *
*/
typedef enum e_syntax
{
	WORD = TOK_WORD,
	REDIR = TOK_REDIR,
	PIPE = TOK_PIPE,
	EOL = TOK_EOL,
	E_NONE = 0
}	t_syntax;

// struct definition for parser structs

// type  -> QUOTE_DQUOTE | QUOTE_SQUOTE
// value -> string without ' or "
struct								s_quote_node
{
	t_quote							type;
	t_string						*value;
};

// type  -> TOK_WORD | TOK_SPACE | TOK_EOL | TOK_QUOTE
// value -> string of the token '\'' or '"' or ' ' or '\n' ...
// validator -> function pointer to check if the token is valid 
//   in the current context
struct								s_token
{
	const t_tok_type				type;
	const char						*value;
	t_tok_chek						validator;
};

// src_std -> source file descriptor
// src_file -> source file path
// flag -> RDIR_FILE | RDIR_STD
// redir_type -> RDIR_INPUT | RDIR_OUTPUT | RDIR_TRUNC | RDIR_APPEND
//   | RDIR_HEREDOC | RDIR_DUP
// target_file -> target file path
// target_std -> target file descriptor
struct								s_redir
{
	int								src_std;
	char							*src_file;
	t_redir_flag					flag;
	t_redir_type					redir_type;
	char							*target_file;
	int								target_std;
};

struct								s_cmd_to_exec
{
	t_vector						*construction_vector;
	size_t							construction_index;
	size_t							nb_tok_consumed;
	char							*cmd_path;
	char							**argv;
	int								ac;
	char							**env;
	int								status;
	int								nbr_cmds;
	t_list							*redir_to_do;
};

// type -> TOK_WORD | TOK_SPACE | TOK_EOL | TOK_QUOTE ...
// value -> string of the token.
// create				->		create the token.
// update_line_buffer	->		update the line buffer.
// append				->		append the token to the command.
// print				->		print the token.
// # wow who could have guessed that print would print
struct								s_preparsed_node
{
	t_tok_type						type;
	void							*value;
	t_tok_action					create;
	t_tok_action					ulb;
	t_tok_action					append;
	t_preparsed_apply				print;
	t_preparsed_apply				destroy;
	t_preparsed_exec				execute;
};

// parser struct for the minishell
// tokens -> list of tokens in the parser
// control -> minishell control structure (parent node)
// line -> line to parse
// preparsed -> list of preparsed nodes (vector of t_preparsed_node)
// res -> command to execute
struct								s_parser
{
	t_vector						*tokens;
	t_minishell_control				*control;
	char							*line;
	t_preparsed_cmd					*preparsed;
	t_cmd_to_exec					*res;
};

// context variables for the preparser
// line_offset -> offset of the line
// unexpected -> unexpected token
// line -> line to parse
// c_tok -> current token
// n_tok -> next token
// quote_ctx -> quote context
struct								s_preparser_context
{
	size_t							line_offset;
	char							*unexpected;
	char							*line;
	t_token							*c_tok;
	t_token							*n_tok;
	t_quote							quote_ctx;
};

#endif /* PARSER_TYPES_H */
