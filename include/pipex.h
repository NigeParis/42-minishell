/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 13:31:15 by nrobinso          #+#    #+#             */
/*   Updated: 2024/06/10 13:56:25 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/types.h>
# include "ft_printf.h"
# include "get_next_line.h"
# include "ft_string.h"
# include "ft_list.h"



# define ERROR_MSG_SIZE 100

# define INFILE 0
# define OUTFILE 1
# define FIRST_CMD 0
# define PIPE_CMD 1
# define LAST_CMD 2

typedef struct s_pipex
{
	int		fdout;
	int		fdin;
	int		pipe_fd[2];
	
}	t_pipex;

typedef struct s_cmd_to_exec
{
    char    *cmd_path;
    char    **argv;
    int        ac;
    char    **env;
    int        status;
    int     lastcmd_index;
    char    left_token;
    char    right_token;
    t_list    *redir_to_do;
}   t_cmd_to_exec;


typedef struct s_redir
{
    int   std_src;
    char  *file_src;
    int   src_flag;
    int   std_dst;
    char  *file_dst;
    int   dst_flag;
}   t_redir;



/// @brief 
/// @param 
/// @param 
/// @note 
int		execute(t_cmd_to_exec *args, t_pipex *pipex, t_redir *redir);

/// @brief 
/// @param 
/// @param 
/// @note 
void	exec_cmd(t_cmd_to_exec *args);

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
void	ft_open_outfile(t_pipex *pipex, char *outfile);

/// @brief 
/// @param 
/// @param 
/// @note 
void	ft_open_infile(t_pipex *pipex, char *outfile);

/// @brief 
/// @param 
/// @param 
/// @note 
int     make_pipe(t_pipex *pipex, t_cmd_to_exec *args, t_redir *redir, int i);

/// @brief 
/// @param 
/// @param 
/// @note 
void	child_process(t_pipex *pipex, t_cmd_to_exec *args, t_redir *redir, int i);

/// @brief 
/// @param 
/// @param 
/// @note 
void	parent_process(t_pipex *pipex);

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
int		ft_heredoc(t_pipex *pipex, int argc, char *argv[]);
/// @brief 
/// @param 
/// @param 
/// @note 
void	ft_here_doc(t_pipex *pipex, char *argv[]);
/// @brief 
/// @param 
/// @param 
/// @note 
int		ft_pipex(t_pipex *pipex);
/// @brief 
/// @param 
/// @param 
/// @note 
void	ft_pipes(t_pipex *pipex, t_cmd_to_exec *args, t_redir *redir, int i);

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



/// @brief takes args from a list and passes them to a pointer;
/// @param void function, see above main
/// @note structure to call cmd
t_cmd_to_exec    *cmd_to_exec_new(void);


/// @brief function for testing redirections 
/// @param void, see above main
/// @note struction for redirections
t_redir   *test_redir(void);


#endif
