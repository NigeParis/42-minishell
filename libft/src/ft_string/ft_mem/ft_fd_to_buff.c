/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fd_to_buff.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 19:52:02 by bgoulard          #+#    #+#             */
/*   Updated: 2024/07/16 13:03:10 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

#include <fcntl.h>
#include <unistd.h>

char	*ft_fd_to_buff(int fd)
{
	char	buff[READ_BLOCKS + 1];
	char	*file;
	char	*prev;
	int		ret;

	if (fd == -1)
		return (NULL);
	file = NULL;
	ret = read(fd, buff, READ_BLOCKS);
	if (ret == -1)
		return (NULL);
	buff[ret] = '\0';
	file = ft_strdup(buff);
	while (ret == READ_BLOCKS)
	{
		ret = read(fd, buff, READ_BLOCKS);
		if (ret == -1)
			return (ft_free((void **)&file), NULL);
		buff[ret] = '\0';
		prev = file;
		file = ft_strjoin(file, buff);
		ft_free((void **)&prev);
	}
	return (file);
}
