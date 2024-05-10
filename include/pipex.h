/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 13:31:15 by nrobinso          #+#    #+#             */
/*   Updated: 2024/05/10 11:30:45 by nrobinso         ###   ########.fr       */
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
# include "../libft/include/libft.h"
# include "../ft_printf/src/ft_printf.h"
# include "../get_next_line/get_next_line.h"

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

/// @brief basically lanches either heredoc of pipex
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

/// @brief executes the command with execve() command externe.
/// @param pipex structure that holds valid path - pipex->path
/// @param pipex structure that holds valid commands to be executed - pipex->cmds
/// @param i command nbr start pos ex 2 or 3 for here_doc
/// @param argv[] the arguments separated by a space 
/// @param env is the tab[] of strings to be searched in.
/// @note function takes into account spaces between the simple quotes
/// @note for ex: "grep 'spaces' " searches for the nbr spaces
void	exec_cmd(t_pipex *pipex, int i, char *argv[], char *env[]);




void	ft_exec_cmd_error(t_pipex *pipex, char *message);
void	ft_cleanup(t_pipex *pipex, int type);
void	ft_cleanup_helper1(t_pipex *pipex, int type);
void	ft_cleanup_helper2(t_pipex *pipex, int type);
void	close_fd(t_pipex *pipex, int type);
void	ft_cleanup_helper(t_pipex *pipex, int type);
void	ft_init(t_pipex *pipex, int argc, char *argv[]);
void	ft_open_files(t_pipex *pipex, int argc, char *argv[]);
int		get_path_absolu(t_pipex *pipex, char *argv[], int i);
int		path_absolu_valid(t_pipex *pipex, char *argv[], int i);
int		make_pipe(t_pipex *pipex, char *env[], char *argv[], int i);
void	child_process(t_pipex *pipex, char *argv[], char *env[], int i);
void	parent_process(t_pipex *pipex);
void	ft_heredoc_init(t_pipex *pipex, int argc, char *argv[]);
void	ft_heredoc_cleanup(t_pipex *pipex);
int		ft_heredoc(t_pipex *pipex, int argc, char *argv[]);
void	ft_here_doc(t_pipex *pipex, char *argv[]);
int		ft_pipex(t_pipex *pipex, int argc, char *argv[]);
void	ft_pipes(t_pipex *pipex, char *argv[], char *env[], int i);
void	cleanup_main_end(t_pipex *pipex);
void	ft_toggle_char(char *str[], char c, int toggle);
void	ft_tog_delim_ch(char *str, char delimiter, char c, int toggle);
void	ft_find_delim(char *str, char delimiter, int *count, int *fst_pos);
void	ft_make_toogle_cmd_arg(t_pipex *pipex);

#endif
