/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_destroy.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:20:41 by bgoulard          #+#    #+#             */
/*   Updated: 2024/01/02 22:01:01 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

void	ft_string_destroy(t_string **str)
{
	if (str == NULL || *str == NULL)
		return ;
	free((*str)->str);
	free(*str);
	*str = NULL;
}
