/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstart_with.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:07:26 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/18 20:05:26 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int	ft_strstart_with(const char *str, const char *start)
{
	if (ft_strlen(start) > ft_strlen(str))
		return (0);
	return (ft_strncmp(str, start, ft_strlen(start)) == 0);
}
