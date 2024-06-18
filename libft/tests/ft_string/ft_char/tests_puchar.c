/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_puchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 16:01:41 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/23 16:18:25 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_char.h"
#include "tests/tests.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int	test_ft_putchar(void)
{
	const char	*file;
	char		buf[256];
	char		c;
	int			fd;
	int			ret;

	file = "ft_putchar";
	c = 0;
	fd = open_test_file((char **)&file);
	if (fd < 0)
		return (1);
	while ((unsigned char)c < 255)
		ft_putchar_fd(c++, fd);
	close(fd);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (2);
	ret = read(fd, buf, 256);
	if (ret != 255)
		return (3);
	buf[255] = 0;
	while (ret--)
		if (buf[ret] != --c)
			return (4);
	return (destroy_test_file(fd, (char *)file), free((char *)file), 0);
}
