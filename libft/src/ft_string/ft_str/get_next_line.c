/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:02:12 by bgoulard          #+#    #+#             */
/*   Updated: 2023/12/06 15:13:36 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*get_next_line(int fd)
{
	static char	loc_buff[1024][BUFFER_SIZE + 1] = {0};
	char		*ret;
	int			rep;

	ret = NULL;
	while (ft_strchr_index(loc_buff[fd], '\n') == -1)
	{
		if (loc_buff[fd][0] && \
		split_from(&ret, loc_buff[fd], ft_strlen(loc_buff[fd]), '\n'))
			return (NULL);
		rep = read(fd, loc_buff[fd], BUFFER_SIZE);
		if (rep <= 0)
			return (ret);
		loc_buff[fd][rep] = 0;
		if (rep != BUFFER_SIZE)
			break ;
	}
	rep = ft_strchr_index(loc_buff[fd], '\n');
	if (rep == -1)
		rep = ft_strlen(loc_buff[fd]);
	if (split_from(&ret, loc_buff[fd], rep, '\n'))
		return (NULL);
	return (ret);
}
