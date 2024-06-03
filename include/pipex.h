/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 13:31:15 by nrobinso          #+#    #+#             */
/*   Updated: 2024/06/03 13:09:57 by nrobinso         ###   ########.fr       */
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

typedef struct s_pipex
{
	int		path_nb;
	int		fdin;
	int		fdout;
	int		pipe_fd[2];
	char	**paths;
	char	*path_cmd;
	char	*path;
	char	**cmds;
	char	**uni_path;
	char	*uni_cmd;
	int		uni_path_flag;
	int		valid_cmd;
	int		all_cmd_valid;
	int		nbr_cmds;
	int		nb_argc;
	int		parse_flag;
	int		cmd_not_flag;
	int		doc;
	int		pipe_doc[2];
	int		lastcmd_flag;

}	t_pipex;

typedef struct s_cmd_to_exec
{
    char    *cmd_path;
    char    **argv;
    int        ac;
    char    **env;
    int        status;
    t_list    *redir_to_do;
}   t_cmd_to_exec;

typedef struct s_redir
{
    int        src;
    int        flag;
    char    *target_file;
    int        target_std;
}   t_redir;



/// @brief basically lanches either heredoc or pipex
/// @param argc nbr of arguments passed by main
/// @param argv[] the arguments separated by a space 
/// @param env[] the enviroment tab[][] of system variables
/// @returns 0 on success 1 on error
int		pipex(int argc, char *argv[], char *env[]);


/// @brief displays the error msg of execve() with the command held in pipex->cmds[0].
/// @brief - Cleansup the frees to be done before exit and closes open FD .
/// @param pipex structure that holds the cmd to be displayed in the MSG - pipex->cmds
/// @param message pointer to str that will be printed as error message on fd[2]
/// @note the buffer of ERROR_MSG_SIZE is 100 but can be redefined in pipex.h
/// @note frees all molloc memory and closes open FDs before it exits the child with execve.
void	ft_exec_cmd_error(t_pipex *pipex, char *message);

/// @brief executes the command with execve() command externe.
/// @param pipex structure that holds valid path - pipex->path
/// @param pipex structure that holds valid commands to be executed - pipex->cmds
/// @param i command nbr start pos ex 2 or 3 for here_doc
/// @param argv[] the arguments separated by a space 
/// @param env is the tab[] of strings to be searched in.
/// @note function takes into account spaces between the simple quotes
void	exec_cmd(t_pipex *pipex, int i, char *argv[], char *env[]);

/// @brief frees the malloc memory with different configurations.
/// @param pipex structure that holds valid path, paths, cmd, flags - etc
/// @param type selector that enables different configurations of free's.
/// @note the function has two internal helpers that extend the configs of free
/// @note ft_cleanup_helper1 and ft_cleanup_helper2
void	ft_cleanup(t_pipex *pipex, int type);

/// @brief frees the malloc memory with different configurations.
/// @param pipex structure that holds valid path, paths, cmd, flags - etc
/// @param type selector that enables different configurations of free's.
/// @note the function extends the configs of ft_cleanup()
void	ft_cleanup_helper1(t_pipex *pipex, int type);

/// @brief frees the malloc memory with different configurations.
/// @param pipex structure that holds valid path, paths, cmd, flags - etc
/// @param type selector that enables different configurations of free's.
/// @note the function extends the configs of ft_cleanup()
void	ft_cleanup_helper2(t_pipex *pipex, int type);

/// @brief closes FD's fdin and/or fdout
/// @param pipex strure that hold the addresses of fdin and fdout
/// @param type selector that enables different choices 0->fdin 1->fdout 10->both
/// @note fd == -1 then it just returns doing nothing
void	close_fd(t_pipex *pipex, int type);

/// @brief initialises all elements of the structure pipex
/// @param pipex the structure that holds all the elments needed.
/// @param argc number of arguments
/// @param argv arguments separated by spaces
/// @note calls the function ft_open_files() inputs into the structure fdin and fdout.
void	ft_init(t_pipex *pipex, int argc, char *argv[]);

/// @brief opens files for FD fdin and fdout - checks fdin file is readable and exists - checks fdout file exists or creates it if not
/// @param pipex the structure that holds both FD, fdin and fdout adresses
/// @param argc number of arguements
/// @param argv tab[][] of arguments separted by a space
/// @note inserts the FD adresses of input and output files
void	ft_open_files(t_pipex *pipex, int argc, char *argv[]);

/// @brief checks and loads a given path from a argv input ex : mybin/cat
/// @param pipex the structure that holds uni_path variable and uni_path_flag
/// @param argv hold input arguments from command line and any flags separated by ' ', ex :'ls -la'
/// @param i command nbr start pos ex 2 or 3 for here_doc
/// @note 1 on success on valid unique path and 0 if fails
int		get_path_absolu(t_pipex *pipex, char *argv[], int i);

/// @brief checks if the path is valid and exists and copies path to pipex->path and sets flags ex: mybin/cat
/// @param pipex the structure that holds uni_path variable and uni_path_flag
/// @param argv hold input arguments from command line and any flags separated by ' '
/// @param i command nbr start pos ex 2 or 3 for here_doc
/// @note uses function access(); to check if the path is valid
int		path_absolu_valid(t_pipex *pipex, char *argv[], int i);

/// @brief makes a pipe pipe_fd[0] and pipe_fd[1] then forks to pid_t process - parent process and child process
/// @param pipex the structure that holds the pipe_fd[0 and 1]
/// @param env holds all environnement variables like PATH=
/// @param argv holds input arguments from command line and any flags separated by ' '
/// @param i command nbr start pos ex 2 or 3 for here_doc
int		make_pipe(t_pipex *pipex, char *env[], char *argv[], int i);

/// @brief with function dup2, opens a copy stdin or stdout to file descriptor fdin and fdout
/// @param pipex structure thatholds the fd's fdin , fdout, pipe_fd[0 and 1] and pipe_doc[0 and 1]
/// @param argv holds input arguments from command line and any flags separated by ' '
/// @param env holds all environnement variables like PATH= needed by exec_cmd()
/// @param i command nbr start pos ex 2 or 3 for here_doc
void	child_process(t_pipex *pipex, char *argv[], char *env[], int i);

/// @brief nothing really happens in the parent process, closes fd[1] and dup2 (fd[0] stdin)
/// @param pipex that holds in a structure all variables
/// @note Parent waits until all child processes are finnished before moving on
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
int		ft_pipex(t_pipex *pipex, int argc, char *argv[]);
/// @brief 
/// @param 
/// @param 
/// @note 
void	ft_pipes(t_pipex *pipex, char *argv[], char *env[], int i);
/// @brief 
/// @param 
/// @param 
/// @note 
void	cleanup_pipex_end(t_pipex *pipex);
/// @brief 
/// @param 
/// @param 
/// @note 
//void	ft_toggle_char(char *str[], char c, int toggle);
/// @brief 
/// @param 
/// @param 
/// @note 
void	ft_tog_delim_ch(char *str, char delimiter, char c, int toggle);
/// @brief 
/// @param 
/// @param 
/// @note 
void	ft_find_delim(char *str, char delimiter, int *count, int *fst_pos);
/// @brief 
/// @param 
/// @param 
/// @note 
void	ft_make_toogle_cmd_arg(t_pipex *pipex);

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
t_list    *test_redir(void);


#endif
