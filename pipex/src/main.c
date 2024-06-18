/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 13:13:05 by nrobinso          #+#    #+#             */
/*   Updated: 2024/06/18 17:56:48 by nrobinso         ###   ########.fr       */
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


void	ft_init(t_pipex *pipex, t_redir *redir)
{
    (void)redir;

	pipex->fdout = -1;
	pipex->fdin = -1;
	pipex->child_pid = -1;

}

     
// #include <stdio.h>
// #include <stdlib.h>
// #include <signal.h>
// #include <unistd.h>

// //Signal handler function for SIGINT
//  void control_c_parent(int sig) {
//     printf("Caught signal %d (SIGTSTP). Exiting CTRL-Z...\n", sig);
//     return ; // Exit the program
// }

// void control_c_paren(int sig) {
//     printf("Caught signal %d (SIGTSTP). Exiting CTRL-C...\n", sig);
//     exit(0); // Exit the program
// }


// int main() {

//     pid_t process;

//     process = fork();
//         // Set up the signal handler for SIGINT
  

//         if (signal(SIGINT, control_c_paren) == SIG_ERR) {
//             perror("signal");
//             return 1;
//         }
//         signal(SIGQUIT, SIG_IGN);       /* desactivates Ctrl-\ */
 

//     if (!process)
//     {
//         // Infinite loop to keep the program running
//         while (1) {
//             printf("Running..with no signal. Press Ctrl+C to exit.\n");
//             sleep(1); // Sleep for 1 second
//         }
//     }
//     else
//     {    
//         wait(NULL);
//     }
//     return 0;
// }

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
    
    redir = test_redir();
    ft_setup_prog(av);
    ft_init(&pipex, redir);
    
    
    while (1)
    {
        signal(SIGQUIT, SIG_IGN);       /* desactivates Ctrl-\ */
        str = readline("minishell $> ");
                
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
        if ((ft_strcmp(str,"ls") == 0) 
            || (ft_strcmp(str,"yes") == 0)
            || (ft_strcmp(str,"pwd") == 0)     
            || (ft_strcmp(str,"echo") == 0)
            || (ft_strcmp(str,"clear") == 0)
            || (ft_strcmp(str,"cat") == 0)
             || (ft_strcmp(str,"qqqq") == 0))
        {
            //first_cmds

            if(ft_strcmp(str,"ls") == 0)
                args = cmd_to_exec_ls();
            if(ft_strcmp(str,"yes") == 0)
                args = cmd_to_exec_yes();
            if(ft_strcmp(str,"pwd") == 0)
                args = cmd_to_exec_pwd();
            if(ft_strcmp(str,"echo") == 0)
                args = cmd_to_exec_echo();
            if(ft_strcmp(str,"clear") == 0)
                args = cmd_to_exec_clear();
            if(ft_strcmp(str,"cat") == 0)
                args = cmd_to_exec_cat();    
            if(ft_strcmp(str,"qqqq") == 0)
                args = cmd_to_exec_qqqq();
            execute(args, &pipex, redir);
            
            //cmds pipe to pipe;
            args = cmd_to_exec_cat();
            execute(args, &pipex, redir);

            //last_cmd_cat;
            args = cmd_to_exec_cat_last();
            execute(args, &pipex, redir);
            

          
        }            
            
        dup2(redir->std_src, STDIN_FILENO); 
        dup2(redir->std_dst, STDOUT_FILENO);      // reset STDIN amd STDOUT          
        free(str);

    }
        close(redir->std_src);               
        close(redir->std_dst);               
    

    
    return(0);

}




