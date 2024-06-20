/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 13:13:05 by nrobinso          #+#    #+#             */
/*   Updated: 2024/06/20 17:01:21 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include <readline/readline.h>
#include <unistd.h>
#include <signal.h>
#include "pipex.h"

#define FLAG_POUR_FILE_TMP 1
#define FLAG_REPLACE_STD 1

// // creer un '< infile'
// t_list  *test_redir_baptiste_infile(void)
// {
//     t_redir    *redir;
//     t_list    *list;

//     list = NULL;
//     redir = malloc(sizeof(t_redir));
//     if (!redir)
//         return (NULL); 
//     redir->std_src = -1;
//     redir->std_dst = STDIN_FILENO;
//     redir->src_flag = FLAG_POUR_FILE_TMP;
//     redir->dst_flag = FLAG_REPLACE_STD;
//     redir->file_src = ft_strdup("infile");
//     redir->file_dst = NULL;
//   //  ft_listadd_front(&list, redir);
//     return (list);
// }




t_minishell_control *testminictrl(void)
{
    t_minishell_control *minictrl;

    minictrl = malloc(sizeof(t_minishell_control));
    
	minictrl->input = NULL;
	minictrl->env = NULL;
	minictrl->exit = 0;
	minictrl->preparsed = NULL;
	minictrl->prs = NULL;

    return (minictrl);
}

t_redir    *test_redir(void)
{
    t_redir    *redir;
   
    redir = malloc(sizeof(t_redir));
    if (!redir)
        return (NULL); 
    redir->src_flag = 0;
    redir->file_src = ft_strdup("infile");
    redir->dst_flag = 0;
    redir->file_dst = ft_strdup("outfile");
    redir->std_dst = dup(STDOUT_FILENO);
    redir->std_src = dup(STDIN_FILENO);
    return (redir);
}

t_redir    *test_redir_pipe(void)
{
    t_redir    *redir;
   
    redir = malloc(sizeof(t_redir));
    if (!redir)
        return (NULL); 
    redir->src_flag = 0;
    redir->file_src = ft_strdup("infile");
    redir->dst_flag = 0;
    redir->file_dst = ft_strdup("outfile");
    redir->std_dst = dup(STDOUT_FILENO);
    redir->std_src = dup(STDIN_FILENO);
    return (redir);
}




t_cmd_to_exec    *cmd_to_exec_clear(void)  
{
    t_cmd_to_exec    *blank;

    blank = malloc(sizeof(t_cmd_to_exec));
    if (!blank)
        return (NULL);
    blank->cmd_path = ft_strdup("/usr/bin/clear");
    blank->argv = ft_split("clear", ' ');
    blank->ac = ft_len_2d((const void * const *)blank->argv);
    blank->env = ft_split("TERM=xterm-256color HOME=$HOME PATH=/usr/bin:/bin /home/nrobinso/Documents/42-minishell/pipex", ' ');
    blank->status = 0;
    blank->redir_to_do = NULL;
    blank->lastcmd_index = FIRST_CMD;
    blank->left_token = ' ';
    blank->right_token = ' ';
    return (blank);
}

t_cmd_to_exec    *cmd_to_exec_init(void)  
{
    t_cmd_to_exec    *blank;

    blank = malloc(sizeof(t_cmd_to_exec));
    if (!blank)
        return (NULL);
    blank->cmd_path = NULL;
    blank->argv = NULL;
    blank->ac = 0;
    blank->env = ft_split("TERM=xterm-256color HOME=$HOME PATH=/usr/bin:/bin /home/nrobinso/Documents/42-minishell/pipex", ' ');
    blank->status = 0;
    blank->redir_to_do = NULL;
    blank->lastcmd_index = FIRST_CMD;
    blank->left_token = ' ';
    blank->right_token = ' ';
    return (blank);
}






void	ft_init(t_pipex *pipex, t_redir *redir)
{
    (void)redir;

	pipex->fdout = -1;
	pipex->fdin = -1;
	pipex->child_pid = -1;
    

}



char *nospaces(char *str)
{
    char *newstr;
    int  i;
    int  y;
    int  len;

    i = 0;
    y = 0;
    len = ft_strlen(str);
    newstr = NULL;
    
    newstr = (char*)malloc(sizeof(char) * len + 1);
    if (!newstr)
        return (NULL);
    if (!str)
        return (NULL);
    
    while (str && str[i])
    {
		if (str[i] == ' ')
		{
		    while (str[i] == ' ')
			    i++;
			continue;
		}
        newstr[y++] = str[i++];
    }
    newstr[y] = '\0';
    return (newstr);
}




#include "string.h"


int	main(int ac, const char *av[], char *env[])
{
    t_cmd_to_exec *args;
    t_pipex pipex;
    t_redir *redir;
    
    (void)args;
    (void)ac;
    (void)av;
    (void)env;
    
    
    char *str;
    char *cmds_nospace;
    char **cmds = NULL;
	size_t cmd_nb = 0;
    
    redir = test_redir();
    ft_setup_prog(av);
    ft_init(&pipex, redir);
    args = cmd_to_exec_init();

    
    
    while (1)
    {
        signal(SIGINT, Ctrl_C_handler);   /* Ctrl-c handler*/
        signal(SIGQUIT, SIG_IGN);          /* desactivates Ctrl-\ */

        cmds = NULL;
        
        cmds =  ft_split(NULL, 0);
        str = readline("minishell $> ");
		if (!str)
			break;
        if (!str[0]) continue;
   
            cmds_nospace = nospaces(str);
        
            if (ft_strlen(&cmds_nospace[0]) > 1)
                cmds = ft_split(cmds_nospace, '|');
			if (cmds)
				cmd_nb = ft_len_2d((const void *const *)cmds);
//            printf("cmd1 '%s'   cmd2 '%s'   cmd3 '%s' \n", cmds[0], cmds[1], cmds[2]);
            if(cmd_nb > 0 && cmds[0])
            {
                
                if (ft_strcmp(str, "exit") == 0)
                {

                    exit_main(testminictrl(),test_cmd_exit());
                    close(redir->std_src);               
                    close(redir->std_dst); 
                    free(redir->file_src);
                    free(redir->file_dst);
                    free(redir);
                    free(str);

                    exit (0);
                }
                if (cmd_nb > 0 && cmds[0])
                {
                    // first cmd
                  
                    test_first_cmd(args, cmds, "ls-l", &cmd_to_exec_ls_l);
                    test_first_cmd(args, cmds, "ls", &cmd_to_exec_ls);
                    test_first_cmd(args, cmds, "yes", &cmd_to_exec_yes);
                    test_first_cmd(args, cmds, "pwd", &cmd_to_exec_pwd);
                    test_first_cmd(args, cmds, "cat-e", &cmd_to_exec_cat_e);
                    test_first_cmd(args, cmds, "cat", &cmd_to_exec_cat);
                    test_first_cmd(args, cmds, "echo", &cmd_to_exec_echo);
                    test_first_cmd(args, cmds, "clear", &cmd_to_exec_clear);
                    test_first_cmd(args, cmds, "echo-n", &cmd_to_exec_echo_n);
                    test_first_cmd(args, cmds, "qqqq", &cmd_to_exec_qqqq);
                    test_first_cmd(args, cmds, "wc", &cmd_to_exec_wc);
                    
                     
                    execute(args, &pipex, redir);
                }            
                
                if (cmd_nb > 1 && cmds[1])
                {
                    // middle cmds pipe to pipe
                
                    test_pipe_cmd(args, cmds, "cat-e", &cmd_to_exec_cat_e);
                    test_pipe_cmd(args, cmds, "ls-l", &cmd_to_exec_ls_l);
                    test_pipe_cmd(args, cmds, "ls", &cmd_to_exec_ls);
                    test_pipe_cmd(args, cmds, "yes", &cmd_to_exec_yes);
                    test_pipe_cmd(args, cmds, "pwd", &cmd_to_exec_pwd);
                    test_pipe_cmd(args, cmds, "cat", &cmd_to_exec_cat);
                    test_pipe_cmd(args, cmds, "qqqq", &cmd_to_exec_qqqq);
                    test_pipe_cmd(args, cmds, "echo", &cmd_to_exec_echo);
                    test_pipe_cmd(args, cmds, "clear", &cmd_to_exec_clear);
                    test_pipe_cmd(args, cmds, "wc", &cmd_to_exec_wc);

                    execute(args, &pipex, redir);
                }
                
                if (cmd_nb > 2 && cmds[2])
                {
                    //last_cmds;
                    
                    test_last_cmd(args, cmds, "cat-e", &cmd_to_exec_cat_e);
                    test_last_cmd(args, cmds, "ls-l", &cmd_to_exec_ls_l);
                    test_last_cmd(args, cmds, "ls", &cmd_to_exec_ls);
                    test_last_cmd(args, cmds, "yes", &cmd_to_exec_yes);
                    test_last_cmd(args, cmds, "pwd", &cmd_to_exec_pwd);
                    test_last_cmd(args, cmds, "cat", &cmd_to_exec_cat);
                    test_last_cmd(args, cmds, "qqqq", &cmd_to_exec_qqqq);
                    test_last_cmd(args, cmds, "echo", &cmd_to_exec_echo);
                    test_last_cmd(args, cmds, "clear", &cmd_to_exec_clear);
                    test_last_cmd(args, cmds, "wc", &cmd_to_exec_wc);
                    
                    execute(args, &pipex, redir);
                }      
                    
                dup2(redir->std_src, STDIN_FILENO); 
                dup2(redir->std_dst, STDOUT_FILENO);      // reset STDIN amd STDOUT          
            }          
        free(str);
    }
	close(redir->std_src);               
	close(redir->std_dst);     
    
    // if (str[0] == '\0')

    dup2(redir->std_dst, STDOUT_FILENO);      // reset STDIN amd STDOUT
    close(redir->std_dst);          
    ft_putstr_fd("exit\n", 1);
    
    return(0);
}
