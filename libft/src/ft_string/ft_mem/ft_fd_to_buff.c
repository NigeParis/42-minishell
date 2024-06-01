/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fd_to_buff.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 19:52:02 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/27 09:31:20 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

#include "ft_string.h"

#define READ_BLOCKS 4096

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
