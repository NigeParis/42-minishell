/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 13:13:05 by nrobinso          #+#    #+#             */
/*   Updated: 2024/06/04 17:13:03 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */




#include "pipex.h"


t_list    *test_redir(void)
{
    t_redir    *redir;
    t_list    *list;

    list = NULL;
    redir = malloc(sizeof(t_redir));
    if (!redir)
        return (NULL); 
    redir->src = STDOUT_FILENO;
    redir->flag = 0;
    redir->target_file = ft_strdup("file");
    redir->target_std = 0;
    ft_listadd_back(&list, ft_listcreate(redir));
    return (list);
}

t_cmd_to_exec    *cmd_to_exec_new(void)
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
    return (blank);
}




void	ft_init(t_pipex *pipex, char *infile, char *outfile)
{
	pipex->fdin = -1;
	pipex->fdout = -1;
	ft_open_files(pipex, infile, outfile);
}


int	main(void)
{
    t_cmd_to_exec *args;
    t_pipex pipex;

    args = cmd_to_exec_new();
    execute(args, &pipex);


    
    return(0);

}
