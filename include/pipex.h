/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 13:31:15 by nrobinso          #+#    #+#             */
/*   Updated: 2024/05/11 11:58:16 by nrobinso         ###   ########.fr       */
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
# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"
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

}	t_pipex;

/// @brief basically lanches either heredoc or pipex
/// @param argc nbr of arguments passed by main
/// @param argv[] the arguments separated by a space 
/// @param env[] the enviroment tab[][] of system variables
/// @returns 0 on success 1 on error
int		pipex(int argc, char *argv[], char *env[]);

/// @brief find && split in pipex->paths[][] all PATHS listed in env
/// @param pipex structure that holds pipex->paths
/// @param cmd pointer to a command to be joined to all valid paths 
/// @param env is the tab[] of strings to be searched in.
/// @returns nbr of the paths made for env variable "PATH=" and 0 on error
int		ft_path(t_pipex *pipex, char *cmd, char **env);

/// @brief find && split in pipex->cmds[][] argv separated by spaces
/// @param pipex structure that holds the splitted cmds pipex->cmds
/// @param argv[] the arguments separated by a space 
/// @note function takes into account spaces betwwen simple quotes
/// @note for ex: "grep 'spaces' " searches for the nbr spaces
/// @returns 0 on success and -1 on error
int		get_cmd(t_pipex *pipex, char *argv);

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

/// @brief 
/// @param 
/// @param 
/// @note 
void	ft_init(t_pipex *pipex, int argc, char *argv[]);
/// @brief 
/// @param 
/// @param 
/// @note 
void	ft_open_files(t_pipex *pipex, int argc, char *argv[]);
/// @brief 
/// @param 
/// @param 
/// @note 
int		get_path_absolu(t_pipex *pipex, char *argv[], int i);
/// @brief 
/// @param 
/// @param 
/// @note 
int		path_absolu_valid(t_pipex *pipex, char *argv[], int i);
/// @brief 
/// @param 
/// @param 
/// @note 
int		make_pipe(t_pipex *pipex, char *env[], char *argv[], int i);
/// @brief 
/// @param 
/// @param 
/// @note 
void	child_process(t_pipex *pipex, char *argv[], char *env[], int i);
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
void	cleanup_main_end(t_pipex *pipex);
/// @brief 
/// @param 
/// @param 
/// @note 
void	ft_toggle_char(char *str[], char c, int toggle);
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

#endif
