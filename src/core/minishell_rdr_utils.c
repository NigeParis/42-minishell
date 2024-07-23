/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_rdr_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 14:06:50 by bgoulard          #+#    #+#             */
/*   Updated: 2024/07/23 14:13:05 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_types.h"
#include <fcntl.h>
#include <stdlib.h>

int	get_op_mode(int type)
{
	int	op_mode;

	op_mode = 0;
	if ((type & RDIR_MSK_IO) == RDIR_PIPE)
		return (EXIT_SUCCESS);
	if ((type & RDIR_MSK_IO) == RDIR_INPUT)
		op_mode = O_RDONLY;
	else if ((type & RDIR_MSK_IO) == RDIR_OUTPUT)
	op_mode = O_WRONLY | O_CREAT;
	if ((type & RDIR_MSK_MODE) == RDIR_APPEND)
		op_mode |= O_APPEND;
	else if ((type & RDIR_MSK_IO) != RDIR_INPUT)
		op_mode |= O_TRUNC;
	return (op_mode);
}
