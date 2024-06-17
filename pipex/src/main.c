/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 13:13:05 by nrobinso          #+#    #+#             */
/*   Updated: 2024/06/17 18:57:13 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */




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


t_cmd    *test_cmd(void)
{
    t_cmd *testcmd;

    testcmd = malloc(sizeof(t_cmd));

	testcmd->cmd = ft_strdup("pwd");
	testcmd->args = ft_split("pwd", ' ');
	testcmd->argc = ft_len_2d((const void * const *)testcmd->args);
	testcmd->envp = NULL;
	testcmd->ret = 0;

    return (testcmd);
}


t_cmd    *test_cmd_echo(void)
{
    t_cmd *testcmd;

    testcmd = malloc(sizeof(t_cmd));

	testcmd->cmd = ft_strdup("echo");
	testcmd->args = ft_split("echo hello *", ' ');
	testcmd->argc = ft_len_2d((const void * const *)testcmd->args);
	testcmd->envp = NULL;
	testcmd->ret = 0;

    return (testcmd);
}



t_cmd    *test_cmd_exit(void)
{
    t_cmd *testcmd;

    testcmd = malloc(sizeof(t_cmd));

	testcmd->cmd = ft_strdup("exit");
	testcmd->args = ft_split("exit 127", ' ');
	testcmd->argc = ft_len_2d((const void * const *)testcmd->args);
	testcmd->envp = NULL;
	testcmd->ret = 0;

    return (testcmd);
}



// t_vector *testvector(void)
// {
// 	void	**datas;
// 	size_t	count;
// 	size_t	cappacity;
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




t_minishell_control *testminictrl_exit(void)
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
    redir->src_flag = 1;
    redir->file_src = ft_strdup("infile");
    redir->dst_flag = 0;
    redir->file_dst = ft_strdup("outfile");
    redir->std_dst = dup(STDOUT_FILENO);
    redir->std_src = dup(STDIN_FILENO);
    redir->saved_fd = -1;
    return (redir);
}




t_cmd_to_exec    *cmd_to_exec_clear(char *env[])
{
    t_cmd_to_exec    *blank;

    blank = malloc(sizeof(t_cmd_to_exec));
    if (!blank)
        return (NULL);
    blank->cmd_path = ft_strdup("/usr/bin/clear");
    blank->argv = ft_split("clear -x -T '\033[2J \033[1f'", ' ');
    blank->ac = ft_len_2d((const void * const *)blank->argv);
    blank->env = env;
    blank->status = 0;
    blank->redir_to_do = NULL;
    blank->lastcmd_index = FIRST_CMD;
    blank->left_token = ' ';
    blank->right_token = ' ';
    return (blank);
}


t_cmd_to_exec    *cmd_to_exec_yes(void)
{
    t_cmd_to_exec    *blank;

    blank = malloc(sizeof(t_cmd_to_exec));
    if (!blank)
        return (NULL);
    blank->cmd_path = ft_strdup("/usr/bin/yes");
    blank->argv = ft_split("yes", ' ');
    blank->ac = ft_len_2d((const void * const *)blank->argv);
    blank->env = NULL;
    blank->status = 0;
    blank->redir_to_do = NULL;
    blank->lastcmd_index = FIRST_CMD;
    blank->left_token = ' ';
    blank->right_token = ' ';
    return (blank);
}


t_cmd_to_exec    *cmd_to_exec_pwd(void)
{
    t_cmd_to_exec    *blank;

    blank = malloc(sizeof(t_cmd_to_exec));
    if (!blank)
        return (NULL);
    blank->cmd_path = ft_strdup("/usr/bin/pwd");
    blank->argv = ft_split("pwd --", ' ');
    blank->ac = ft_len_2d((const void * const *)blank->argv);
    blank->env = NULL;
    blank->status = 0;
    blank->redir_to_do = NULL;
    blank->lastcmd_index = FIRST_CMD;
    blank->left_token = ' ';
    blank->right_token = ' ';
    return (blank);
}


t_cmd_to_exec    *cmd_to_exec_new0(void)
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
    blank->lastcmd_index = FIRST_CMD;
    blank->left_token = ' ';
    blank->right_token = ' ';
    return (blank);
}

t_cmd_to_exec    *cmd_to_exec_qqqq(void)
{
    t_cmd_to_exec    *blank;

    blank = malloc(sizeof(t_cmd_to_exec));
    if (!blank)
        return (NULL);
    blank->cmd_path = ft_strdup("/usr/bin/qqqq");
    blank->argv = ft_split("qqqq", ' ');
    blank->ac = ft_len_2d((const void * const *)blank->argv);
    blank->env = NULL;
    blank->status = 0;
    blank->redir_to_do = NULL;
    blank->lastcmd_index = FIRST_CMD;
    blank->left_token = ' ';
    blank->right_token = ' ';
    return (blank);
}

t_cmd_to_exec    *cmd_to_exec_echo()
{
    t_cmd_to_exec    *blank;

    blank = malloc(sizeof(t_cmd_to_exec));
    if (!blank)
        return (NULL);
    blank->cmd_path = ft_strdup("/usr/bin/echo");
    blank->argv = ft_split("echo hello", ' ');
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
    blank->argv = ft_split("cat -e", ' ');
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
	redir->saved_fd = -1;
	pipex->child_pid = -1;

}












int	main(int ac, const char *av[], char *env[])
{
    t_cmd_to_exec *args;
    t_pipex pipex;
    t_redir *redir;
    
    printf("%s\n", env[5]);

    char *str;
    redir = test_redir();
    (void)args;
    (void)ac;
    (void)av;
    
    ft_setup_prog(av);
   
   
   
    ft_init(&pipex, redir);
    
    while (1)
    {
        ft_putstr_fd("type exe to test> ", 1);
        str = get_next_line(0);
                
        if (ft_strcmp(str, "exit\n") == 0)
        {

            exit_main(testminictrl_exit(),test_cmd_exit());
            close(redir->std_src);               
            close(redir->std_dst); 
            free(redir->file_src);
            free(redir->file_dst);
            free(redir);
            free(str);

            exit (0);
        }
        if ((ft_strcmp(str,"exe\n") == 0) 
            || (ft_strcmp(str,"yes\n") == 0)
            || (ft_strcmp(str,"pwd\n") == 0)     
            || (ft_strcmp(str,"echo\n") == 0)
            || (ft_strcmp(str,"clear\n") == 0)
             || (ft_strcmp(str,"qqqq\n") == 0))
        {
            if(ft_strcmp(str,"exe\n") == 0)
                args = cmd_to_exec_new0();
            if(ft_strcmp(str,"yes\n") == 0)
                args = cmd_to_exec_yes();
            if(ft_strcmp(str,"pwd\n") == 0)
                args = cmd_to_exec_pwd();
            if(ft_strcmp(str,"echo\n") == 0)
                args = cmd_to_exec_echo();
            if(ft_strcmp(str,"clear\n") == 0)
                args = cmd_to_exec_clear(env);    
            if(ft_strcmp(str,"qqqq\n") == 0)
                args = cmd_to_exec_qqqq();
            execute(args, &pipex, redir);
            
            //free(args);
            args = cmd_to_exec_new();
            execute(args, &pipex, redir);
            execute(args, &pipex, redir);
            execute(args, &pipex, redir);
            execute(args, &pipex, redir);
         
            execute(args, &pipex, redir);
            execute(args, &pipex, redir);
            //free(args);
            
        
        
            args = cmd_to_exec_new2();
            execute(args, &pipex, redir);
            //free(args);
            

          
        }            
            
        dup2(redir->std_src, STDIN_FILENO); 
        dup2(redir->std_dst, STDOUT_FILENO);      // reset STDIN amd STDOUT          
        free(str);

    }
        close(redir->std_src);               
        close(redir->std_dst);               
    

    
    return(0);

}




