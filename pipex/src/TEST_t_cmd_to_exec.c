/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TEST_t_cmd_to_exec.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 11:04:12 by nrobinso          #+#    #+#             */
/*   Updated: 2024/06/25 15:43:26 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_redir    *test_redir_init(void)
{
    t_redir    *redir;
   
    redir = malloc(sizeof(t_redir));
    if (!redir)
        return (NULL); 
    redir->flag = RDIR_STD;
    redir->redir_type = (t_redir_type)RDIR_INPUT;
    redir->src_file = ft_strdup("infile");
    redir->target_file = ft_strdup("oufile");
    redir->target_std = dup(STDOUT_FILENO);
    redir->src_std = dup(STDIN_FILENO);
    return (redir);
}




//FIRST

t_cmd_to_exec    *cmd_to_exec_pwd(void)
{
    t_cmd_to_exec    *blank;

    blank = malloc(sizeof(t_cmd_to_exec));
    if (!blank)
        return (NULL);
    blank->cmd_path = ft_strdup("/usr/bin/pwd");
    blank->argv = ft_split("pwd", ' ');
    blank->ac = ft_len_2d((const void * const *)blank->argv);
    blank->env = NULL;
    blank->status = -1;
    blank->redir_to_do = NULL;
    blank->lastcmd_index = FIRST_CMD;
  
    return (blank);
}


t_cmd_to_exec    *cmd_to_exec_exit(void)
{
    t_cmd_to_exec    *blank;

    blank = malloc(sizeof(t_cmd_to_exec));
    if (!blank)
        return (NULL);
    blank->cmd_path = ft_strdup("exit");
    blank->argv = ft_split("exit 12", ' ');
    blank->ac = ft_len_2d((const void * const *)blank->argv);
    blank->env = NULL;
    blank->status = -1;
    blank->redir_to_do = NULL;
    blank->lastcmd_index = FIRST_CMD;
 
    return (blank);
}




// src_std -> source file descriptor
// src_file -> source file path
// flag -> RDIR_FILE | RDIR_STD
// redir_type -> RDIR_INPUT | RDIR_OUTPUT | RDIR_TRUNC | RDIR_APPEND
//   | RDIR_HEREDOC | RDIR_DUP
// target_file -> target file path
// target_std -> target file descriptor



t_redir    *test_redir_ls_l(void)
{
    t_redir    *redir;
   
    redir = malloc(sizeof(t_redir));
    if (!redir)
        return (NULL); 
    redir->flag = (t_redir_flag)RDIR_STD;
    redir->redir_type = RDIR_PIPE;
    redir->src_file = ft_strdup("infile");
    redir->target_file = ft_strdup("outls_l");
    redir->target_std = dup(STDOUT_FILENO);
    redir->src_std = dup(STDIN_FILENO);
    return (redir);
}


t_cmd_to_exec    *cmd_to_exec_ls_l(void)
{
    t_cmd_to_exec    *blank;

    blank = malloc(sizeof(t_cmd_to_exec));
    if (!blank)
        return (NULL);
    blank->cmd_path = ft_strdup("/usr/bin/ls");
    blank->argv = ft_split("ls -l", ' ');
    blank->ac = ft_len_2d((const void * const *)blank->argv);
    blank->env = NULL;
    blank->status = 0;
    blank->redir_to_do = (t_list*)test_redir_ls_l();
    ft_ll_push(&blank->redir_to_do, (t_list*)test_redir_ls_l());
    blank->lastcmd_index = FIRST_CMD;
   
    return (blank);
}









t_redir    *test_redir_ls(void)
{
    t_redir    *redir;
   
    redir = malloc(sizeof(t_redir));
    if (!redir)
        return (NULL); 
    redir->flag = (t_redir_flag)RDIR_STD;
    redir->redir_type = RDIR_PIPE;
    redir->src_file = ft_strdup("infile");
    redir->target_file = ft_strdup("outls_l");
    redir->target_std = dup(STDOUT_FILENO);
    redir->src_std = dup(STDIN_FILENO);
    return (redir);
}


t_cmd_to_exec    *cmd_to_exec_ls(void)
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
    blank->redir_to_do = (t_list*)test_redir_ls();
    ft_ll_push(&blank->redir_to_do, (t_list*)test_redir_ls());
    blank->lastcmd_index = FIRST_CMD;
   
    return (blank);
}


t_cmd_to_exec    *cmd_to_exec_qqqq(void)
{
    t_cmd_to_exec    *blank;

    blank = malloc(sizeof(t_cmd_to_exec));
    if (!blank)
        return (NULL);
    blank->cmd_path = NULL;
    blank->argv = ft_split("qqqq", ' ');
    blank->ac = ft_len_2d((const void * const *)blank->argv);
    blank->env = NULL;
    blank->status = 0;
    blank->redir_to_do = NULL;
    blank->lastcmd_index = FIRST_CMD;
 
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
  
    return (blank);
}

// t_cmd_to_exec    *cmd_to_exec_echo(void)
// {
//     t_cmd_to_exec    *blank;

//     blank = malloc(sizeof(t_cmd_to_exec));
//     if (!blank)
//         return (NULL);
//     blank->cmd_path = ft_strdup("/usr/bin/echo");
//     blank->argv = ft_split("echo hello", ' ');
//     blank->ac = ft_len_2d((const void * const *)blank->argv);
//     blank->env = NULL;
//     blank->status = -1;
//     blank->redir_to_do = NULL;
//     blank->lastcmd_index = FIRST_CMD;
   
//     return (blank);
// }

// SECOND CMD


t_redir    *test_redir_cat_e(void)
{
    t_redir    *redir;
   
    redir = malloc(sizeof(t_redir));
    if (!redir)
        return (NULL); 
    redir->flag = (t_redir_flag)RDIR_STD;
    redir->redir_type = 0;
    redir->src_file = ft_strdup("infile");
    redir->target_file = ft_strdup("/dev/stdout");
    redir->target_std = dup(STDOUT_FILENO);
    redir->src_std = dup(STDIN_FILENO);
    return (redir);
}

t_cmd_to_exec    *cmd_to_exec_cat_e(void)
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
    blank->redir_to_do = (t_list*)test_redir_cat_e();
    ft_ll_push(&blank->redir_to_do, test_redir_cat_e());
    blank->lastcmd_index = FIRST_CMD;
 
    return (blank);
}






t_redir    *test_redir_cat(void)
{
    t_redir    *redir;
   
    redir = malloc(sizeof(t_redir));
    if (!redir)
        return (NULL); 
    redir->flag = (t_redir_flag)RDIR_FILE;
    redir->redir_type = RDIR_PIPE;
    redir->src_file = ft_strdup("infile");
    redir->target_file = ft_strdup("outls_l");
    redir->target_std = dup(STDOUT_FILENO);
    redir->src_std = dup(STDIN_FILENO);
    return (redir);
}


t_cmd_to_exec    *cmd_to_exec_cat(void)
{
    t_cmd_to_exec    *blank;

    blank = malloc(sizeof(t_cmd_to_exec));
    if (!blank)
        return (NULL);
    blank->cmd_path = ft_strdup("/usr/bin/cat");
    blank->argv = ft_split("cat infile", ' ');
    blank->ac = ft_len_2d((const void * const *)blank->argv);
    blank->env = NULL;
    blank->status = 0;
     blank->redir_to_do = (t_list*)test_redir_cat();
    ft_ll_push(&blank->redir_to_do, test_redir_cat());
    blank->lastcmd_index = FIRST_CMD;
   
    return (blank);
}








t_redir    *test_redir_echo_n(void)
{
    t_redir    *redir;
   
    redir = malloc(sizeof(t_redir));
    if (!redir)
        return (NULL); 
    redir->flag = (t_redir_flag)RDIR_STD;
    redir->redir_type = (t_redir_type)RDIR_PIPE;
    redir->src_file = ft_strdup("infile");
    redir->target_file = ft_strdup("outls_l");
    redir->target_std = dup(STDOUT_FILENO);
    redir->src_std = dup(STDIN_FILENO);
    return (redir);
}


t_cmd_to_exec    *cmd_to_exec_echo_n(void)
{
    t_cmd_to_exec    *blank;

    blank = malloc(sizeof(t_cmd_to_exec));
    if (!blank)
        return (NULL);
    blank->cmd_path = ft_strdup("/usr/bin/echo");
    blank->argv = ft_split("echo Hello", ' ');
    blank->ac = ft_len_2d((const void * const *)blank->argv);
    blank->env = NULL;
    blank->status = 0;
    blank->redir_to_do = (t_list*) test_redir_echo_n();
    ft_ll_push(&blank->redir_to_do, test_redir_echo_n());
    blank->lastcmd_index = FIRST_CMD;
  
    return (blank);
}





t_cmd_to_exec    *cmd_to_exec_wc(void)
{
    t_cmd_to_exec    *blank;

    blank = malloc(sizeof(t_cmd_to_exec));
    if (!blank)
        return (NULL);
    blank->cmd_path = ft_strdup("/usr/bin/wc");
    blank->argv = ft_split("wc", ' ');
    blank->ac = ft_len_2d((const void * const *)blank->argv);
    blank->env = NULL;
    blank->status = 0;
    blank->redir_to_do = NULL;
    //ft_ll_push(&blank->redir_to_do, test_redir());
    blank->lastcmd_index = FIRST_CMD;
  
    return (blank);
}


// LAST CMD


// t_cmd_to_exec    *cmd_to_exec_cat_last(void)
// {
//     t_cmd_to_exec    *blank;

//     blank = malloc(sizeof(t_cmd_to_exec));
//     if (!blank)
//         return (NULL);
//     blank->cmd_path = ft_strdup("/usr/bin/cat");
//     blank->argv = ft_split("cat", ' ');
//     blank->ac = ft_len_2d((const void * const *)blank->argv);
//     blank->env = NULL;
//     blank->status = 0;
//     blank->redir_to_do = NULL;
//     blank->lastcmd_index = LAST_CMD;
//     blank->left_token = ' ';
//     blank->right_token = ' ';
//     return (blank);
// }