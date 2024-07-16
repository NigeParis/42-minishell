/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_gnl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 11:13:01 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/31 14:26:14 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "tests/tests.h"

#include <fcntl.h>

static int	write_lines(const char **lines, size_t n)
{
	size_t	i;
	int		fd;

	fd = open(TESTS_FPREFIX "gnl.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	if (fd < 0)
		return (-1);
	i = 0;
	while (i < n)
	{
		write(fd, lines[i], ft_strlen(lines[i]));
		i++;
	}
	close(fd);
	return (0);
}

static const char	**return_lines(size_t *n)
{
	static const char	*test_lines[] = {
		"Hello World!\n",
		"This is Zod!\n",
		"Zod shall henceforth be the new earth emperor. Prepare yourself "
		"earthilings to the terrible rule of zod the space warrior and self "
		"proclaimed emperor of the gallaxy. this is a really long line btw... "
		"i sure hope gnl will parse it............................\n",
		"Goodbye World!\n",
	};

	*n = sizeof(test_lines) / sizeof(test_lines[0]);
	return (test_lines);
}

int	test_gnl(void)
{
	int			fd;
	char		*line;
	size_t		i;
	size_t		lines_count;
	const char	**test_lines = return_lines(&lines_count);

	line = NULL;
	if (write_lines(test_lines, lines_count) < 0)
		return (1);
	fd = open(TESTS_FPREFIX "gnl.txt", O_RDONLY);
	i = 0;
	while (i < lines_count)
	{
		line = get_next_line(fd);
		if (ft_strcmp(line, test_lines[i++]) != 0)
			return (i + 1);
		free(line);
	}
	line = get_next_line(fd);
	if (line != NULL)
		return (2);
	return (free(line), destroy_test_file(fd, TESTS_FPREFIX "gnl.txt"), 0);
}
