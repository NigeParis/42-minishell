/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_types.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 10:50:34 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/08 14:08:29 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_TYPES_H
# define MINISHELL_TYPES_H

# include "ft_vector_types.h"

typedef struct s_minishell_control
{
	char		*input;
	t_vector	*env;
	int			exit;
	int			ret;
}	t_minishell_control;

#endif
