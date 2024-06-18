/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_fd_to_buff.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:15:20 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/31 10:53:05 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "tests/tests.h"

int	test_fd_to_buff(void)
{
	char	buff[100];
	char	*ret;
	int		fd;

	ft_bzero(buff, 100);
	ft_strlcat(buff, "Hello World\n\n\n\n\tv\vjkldqskjfsldfjsmldfkj\n", 100);
	fd = open(TESTS_FPREFIX "test_fd_to_buff.txt", O_RDWR | O_CREAT, 0644);
	if (fd < 0)
		return (1);
	write(fd, buff, ft_strlen(buff));
	close(fd);
	fd = open(TESTS_FPREFIX "test_fd_to_buff.txt", O_RDONLY);
	if (fd < 0)
		return (1);
	ret = ft_fd_to_buff(fd);
	if (ft_strcmp(ret, buff) != 0)
		return (1);
	destroy_test_file(fd, TESTS_FPREFIX "test_fd_to_buff.txt");
	free(ret);
	return (0);
}
