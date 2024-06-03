/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 13:13:05 by nrobinso          #+#    #+#             */
/*   Updated: 2024/06/03 13:21:14 by nrobinso         ###   ########.fr       */
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




int	main(int argc, char *argv[], char *env[])
{
	return(pipex(argc, argv, env));
}
