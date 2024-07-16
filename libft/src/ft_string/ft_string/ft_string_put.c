/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_put.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 03:49:59 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/31 15:58:12 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string_types.h"

#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int	ft_string_put(t_string *str, int fd)
{
	int	ret;

	if (fd < 0 || str == NULL || (str->str == NULL && str->length != 0))
		return (-1);
	ret = write(fd, str->str, str->length);
	return (ret);
}
