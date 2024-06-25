/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_putendl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 11:13:01 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/31 15:07:22 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "tests/tests.h"

int	test_putendl(void)
{
	const char	*str;
	int			fd;
	char		buff[100];
	int			bread;
	const char	file_name[] = TESTS_FPREFIX "putendl.txt";

	str = "Hello World!";
	fd = open(file_name, O_RDWR | O_CREAT | O_TRUNC, 0666);
	ft_putendl_fd(str, fd);
	close(fd);
	fd = open(file_name, O_RDONLY);
	bread = read(fd, buff, 100);
	if (bread < 0 || ft_strncmp(buff, str, ft_strlen(str)) != 0
		|| buff[ft_strlen(str)] != '\n')
		return (1);
	destroy_test_file(fd, file_name);
	fd = open(file_name, O_RDWR | O_CREAT | O_TRUNC, 0666);
	ft_putendl_fd(NULL, fd);
	close(fd);
	fd = open(file_name, O_RDONLY);
	bread = read(fd, buff, 100);
	if (bread != 0)
		return (2);
	destroy_test_file(fd, file_name);
	return (0);
}
