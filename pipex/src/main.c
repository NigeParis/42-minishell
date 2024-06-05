/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 13:13:05 by nrobinso          #+#    #+#             */
/*   Updated: 2024/06/05 18:12:26 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */




#include "pipex.h"


t_redir    *test_redir(void)
{
    t_redir    *redir;
   
    redir = malloc(sizeof(t_redir));
    if (!redir)
        return (NULL); 
    redir->src = STDOUT_FILENO;
    redir->flag = 0;
    redir->target_file = ft_strdup("file");
    redir->target_std = 0;
    return (redir);
}

t_cmd_to_exec    *cmd_to_exec_new(void)
{
    t_cmd_to_exec    *blank;

    blank = malloc(sizeof(t_cmd_to_exec));
    if (!blank)
        return (NULL);
    blank->cmd_path = ft_strdup("/usr/bin/ls");
    blank->argv = ft_split("ls", ' ');
    blank->ac = ft_len_2d((const void * const *)blank->argv);
    blank->env = NULL;
    blank->status = 0;
    blank->redir_to_do = NULL;
    blank->lastcmd_index = 4;
    blank->left_token = ';';
    blank->right_token = ';';
    return (blank);
}
t_cmd_to_exec    *cmd_to_exec_new2(void)
{
    t_cmd_to_exec    *blank;

    blank = malloc(sizeof(t_cmd_to_exec));
    if (!blank)
        return (NULL);
    blank->cmd_path = ft_strdup("/usr/bin/cat");
    blank->argv = ft_split("cat -e", ' ');
    blank->ac = ft_len_2d((const void * const *)blank->argv);
    blank->env = NULL;
    blank->status = 0;
    blank->redir_to_do = NULL;
    blank->lastcmd_index = 4;
    blank->left_token = '|';
    blank->right_token = '|';
    return (blank);
}



void	ft_init(t_pipex *pipex)
{
	pipex->fdout = -1;
}


int	main(void)
{
    t_cmd_to_exec *args;
    t_pipex pipex;
    t_redir *redir;

    ft_init(&pipex);
    redir = test_redir();
    args = cmd_to_exec_new();

    execute(args, &pipex, redir);
    execute(args, &pipex, redir);
    execute(args, &pipex, redir);
    //execute(args, &pipex, redir);
    // execute(args, &pipex, redir);


    args = cmd_to_exec_new2();

    execute(args, &pipex, redir);
    // execute(args, &pipex, redir);
    
    return(0);

}
