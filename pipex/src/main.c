/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 13:13:05 by nrobinso          #+#    #+#             */
/*   Updated: 2024/06/11 16:15:09 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */




#include "pipex.h"

t_redir    *test_redir(void)
{
    t_redir    *redir;
   
    redir = malloc(sizeof(t_redir));
    if (!redir)
        return (NULL); 
    redir->src_flag = 1;
    redir->file_src = ft_strdup("infile");
    redir->dst_flag = 0;
    redir->file_dst = ft_strdup("outfile");
    redir->std_dst = STDOUT_FILENO;
    redir->std_src = STDIN_FILENO;
    redir->saved_fd = -1;
    return (redir);
}


t_cmd_to_exec    *cmd_to_exec_new0(void)
{
    t_cmd_to_exec    *blank;

    blank = malloc(sizeof(t_cmd_to_exec));
    if (!blank)
        return (NULL);
    blank->cmd_path = ft_strdup("/usr/bin/pwd");
    blank->argv = ft_split("pwd", ' ');
    blank->ac = ft_len_2d((const void * const *)blank->argv);
    blank->env = NULL;
    blank->status = 0;
    blank->redir_to_do = NULL;
    blank->lastcmd_index = FIRST_CMD;
    blank->left_token = ' ';
    blank->right_token = ' ';
    return (blank);
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
    blank->lastcmd_index = PIPE_CMD;
    blank->left_token = ' ';
    blank->right_token = '|';
    return (blank);
}

t_cmd_to_exec    *cmd_to_exec_new2(void)
{
    t_cmd_to_exec    *blank;

    blank = malloc(sizeof(t_cmd_to_exec));
    if (!blank)
        return (NULL);
    blank->cmd_path = ft_strdup("/usr/bin/cat");
    blank->argv = ft_split("cat", ' ');
    blank->ac = ft_len_2d((const void * const *)blank->argv);
    blank->env = NULL;
    blank->status = 0;
    blank->redir_to_do = NULL;
    blank->lastcmd_index = LAST_CMD;
    blank->left_token = ' ';
    blank->right_token = ' ';
    return (blank);
}



void	ft_init(t_pipex *pipex, t_redir *redir)
{
	pipex->fdout = -1;
	pipex->fdin = -1;
	redir->saved_fd = dup(STDIN_FILENO);

}


int	main(void)
{
    t_cmd_to_exec *args;
    t_pipex pipex;
    t_redir *redir;

    char *str;

    redir = test_redir();
    ft_init(&pipex, redir);
    while (1)
    {
        ft_putstr_fd("type exe to test> ", 1);
        str = get_next_line(0);


        if (ft_strcmp(str, "exit\n") == 0)
            exit (0);

        if (ft_strcmp(str,"exe\n") == 0)
        {
            args = cmd_to_exec_new0();
            execute(args, &pipex, redir);
            
            args = cmd_to_exec_new();
            execute(args, &pipex, redir);
            // execute(args, &pipex, redir);
            // execute(args, &pipex, redir);
            // execute(args, &pipex, redir);
            // // execute(args, &pipex, redir);
            // // execute(args, &pipex, redir);
            // // execute(args, &pipex, redir);
            // // execute(args, &pipex, redir);
            // execute(args, &pipex, redir);
            // execute(args, &pipex, redir);
            // execute(args, &pipex, redir);
            // execute(args, &pipex, redir);
            // execute(args, &pipex, redir);
            // execute(args, &pipex, redir);
            // execute(args, &pipex, redir);
            // execute(args, &pipex, redir);
            // execute(args, &pipex, redir);
            // execute(args, &pipex, redir);
            // execute(args, &pipex, redir);
            // //execute(args, &pipex, redir);
            // // execute(args, &pipex, redir);
        
        
            args = cmd_to_exec_new2();
            execute(args, &pipex, redir);
            
            dup2(redir->saved_fd, STDIN_FILENO);

            if (args->right_token != '>')
                ft_putstr_fd("\n", 1);
          
            
            
        }
        free(str);
    }
    
    return(0);

}
