/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 16:05:25 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/09 16:09:57 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "minishell_types.h"
#include <unistd.h>

void	minishell_error(t_mini_err err_type, const char *msg, int errcode)
{
	ft_putstr_fd(msg, STDERR_FILENO);
	if (err_type == MINI_ERR_FATAL)
		exit(errcode);
}
