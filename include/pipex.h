/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 13:31:15 by nrobinso          #+#    #+#             */
/*   Updated: 2024/06/29 14:54:12 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/types.h>
# include "../ft_printf/src/ft_printf.h"
# include "../get_next_line/get_next_line.h"
# include "ft_string.h"
# include "ft_list.h"
# include "ft_char.h"
# include "ft_args.h"
#include "parser_types.h"
#include "minishell_types.h"
#include "minishell.h"


# define ERROR_MSG_SIZE 100

# define INFILE 0
# define OUTFILE 1

typedef struct s_pipex
{
	int		fdout;
	int		fdin;
	int		pipe_fd[2];
	int 	pipe_doc[2];
	int 	doc;
	int		child_pid;
}	t_pipex;




void    close_fd(int *fd);

void backslash_handler(int sig);
void Ctrl_C_handler(int sig);
void Ctrl_C_child_handler(int sig);


/// @brief 
/// @param 
/// @param 
/// @note 
int   put_echo(t_minishell_control *ctrl, t_cmd_to_exec *cmd);


/// @brief exits minishell
/// @param 
/// @param 
/// @returns 0 on SUCCESS or 1 on ERROR 
int	exit_main(t_minishell_control *ctrl, t_cmd_to_exec *cmd);

/// @brief 
/// @param 
/// @param 
/// @note 
//int		execute(t_cmd_to_exec *args, t_pipex *pipex);
int	execute(t_cmd_to_exec *argv, t_pipex *pipex, t_minishell_control *shell);

/// @brief 
/// @param 
/// @param 
/// @note 
void	exec_cmd(t_cmd_to_exec *args, t_pipex *pipex, t_minishell_control *shell);

/// @brief 
/// @param 
/// @param 
/// @note 
void	close_fdout(t_pipex *pipex);


/// @brief 
/// @param 
/// @param 
/// @note 
void	close_fdin(t_pipex *pipex);

/// @brief 
/// @param 
/// @param 
/// @note 
// void	ft_init(t_pipex *pipex, t_redir *redir);
void	ft_init(t_pipex *pipex);


/// @brief 
/// @param 
/// @param 
/// @note
int 	checkfile_read_and_exists(char *file, int type);


/// @brief 
/// @param 
/// @param 
/// @note 
void	ft_open_file(t_pipex *pipex, t_cmd_to_exec *argv);


/// @brief 
/// @param 
/// @param 
/// @note 
void	ft_open_outfile_trunc(t_pipex *pipex, char *outfile);


/// @brief 
/// @param 
/// @param 
/// @note 
void	ft_open_outfile_append(t_pipex *pipex, char *outfile);

/// @brief 
/// @param 
/// @param 
/// @note 
void	ft_open_infile(t_pipex *pipex, char *outfile);

/// @brief 
/// @param 
/// @param 
/// @note 
//int     make_pipe(t_pipex *pipex, t_cmd_to_exec *args, );
int make_pipe(t_pipex *pipex, t_cmd_to_exec *argv, t_minishell_control *shell);

/// @brief 
/// @param 
/// @param 
/// @note 
//void	child_process(t_pipex *pipex, t_cmd_to_exec *args);
void child_process(t_pipex *pipex, t_cmd_to_exec *argv, t_minishell_control *shell);

/// @brief 
/// @param 
/// @param 
/// @note 
//void	parent_process(t_pipex *pipex, t_cmd_to_exec *args);
void parent_process(t_pipex *pipex, t_cmd_to_exec *argv, t_minishell_control *shell);


/// @brief 
/// @param 
/// @param 
/// @note 
void	ft_heredoc_init(t_pipex *pipex, int argc, char *argv[]);


/// @brief 
/// @param 
/// @param 
/// @note 
void	ft_heredoc_cleanup(t_pipex *pipex);

/// @brief 
/// @param 
/// @param 
/// @note 
//int		ft_heredoc(t_pipex *pipex, int argc, char *argv[]);
int	ft_heredoc(t_pipex *pipex, t_cmd_to_exec *cmd);

/// @brief 
/// @param 
/// @param 
/// @note 
//void	ft_here_doc(t_pipex *pipex, char *argv[]);
void	ft_here_doc(t_pipex *pipex, t_cmd_to_exec *cmd);


/// @brief 
/// @param 
/// @param 
/// @note 
void	ft_free_tab(char *tab);

/// @brief 
/// @param 
/// @param 
/// @note 
void	ft_free_double_tab(char *tab[]);


void	print_cmd(t_cmd_to_exec *cmd);   // fubctions Baptiste not declared
void discard_cmd(t_cmd_to_exec *cmd);
int (*get_builtin(const char *cmd))(t_minishell_control *, t_cmd_to_exec *);
 


t_redir   *test_redir_ls(void);



t_minishell_control *testminictrl(void);
t_minishell_control *testminictrl_exit(void);



#endif
