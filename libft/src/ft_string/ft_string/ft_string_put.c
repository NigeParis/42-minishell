/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_put.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 03:49:59 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/08 13:58:59 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string_struct.h"
#include <unistd.h>

int	ft_string_put(t_string *str, int fd)
{
	int	ret;

	if (fd < 0 || !str || (!str->str && str->length != 0))
		return (-1);
	ret = write(fd, str->str, str->length);
	return (ret);
}
