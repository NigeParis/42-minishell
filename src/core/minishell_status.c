/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_status.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 10:48:46 by bgoulard          #+#    #+#             */
/*   Updated: 2024/08/19 10:49:35 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

static int	singelton_status(int status, bool set)
{
	static int	st = 0;

	if (set)
		st = status;
	return (st);
}

int	get_status(int status)
{
	return (singelton_status(status, false));
}

void	set_status(int status)
{
	singelton_status(status, true);
}
