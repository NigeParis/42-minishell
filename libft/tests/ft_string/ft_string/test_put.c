/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_put.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 12:45:09 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/01 12:28:09 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "tests/tests.h"

int	test_string_put(void)
{
	t_string	*str;
	const char	*src;
	char		*res;
	int			fd;
	const char	*file = TESTS_FPREFIX "test_string_put.txt";

	src = "Hello world this is zod!";
	str = ft_string_from(src);
	fd = open(file, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fd == -1)
		return (1);
	ft_string_put(str, fd);
	close(fd);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (1);
	res = ft_fd_to_buff(fd);
	destroy_test_file(fd, file);
	if (ft_strcmp(src, res) != 0)
		return (1);
	free(res);
	ft_string_destroy(&str);
	return (0);
}
