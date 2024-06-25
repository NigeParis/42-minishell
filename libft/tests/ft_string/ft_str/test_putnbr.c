/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_putnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 11:13:01 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/31 15:07:51 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "tests/tests.h"
#include <limits.h>

static int	nb_to_file(const int *nbs, size_t size, const char *file_name)
{
	int		fd;
	size_t	i;

	fd = open(file_name, O_RDWR | O_CREAT | O_TRUNC, 0666);
	if (fd < 0)
		return (-1);
	i = 0;
	while (i < size)
	{
		ft_putnbr_fd(nbs[i], fd);
		ft_putstr_fd("\n", fd);
		i++;
	}
	close(fd);
	return (0);
}

static int	file_cmp(const char *file_name, const char *expected)
{
	int		fd;
	char	buff[100];

	fd = open(file_name, O_RDONLY);
	ft_bzero(buff, sizeof(buff));
	read(fd, buff, sizeof(buff));
	close(fd);
	if (ft_strncmp(buff, expected, sizeof(buff)))
		return (1);
	return (destroy_test_file(fd, file_name), 0);
}

static int	test_positives(void)
{
	const int	t_cases[] = {0, 1, 9, 10, 99, 100, 999, 1000, 9999, 10000, \
		INT_MAX};
	const char	*expected = "0\n1\n9\n10\n99\n100\n999\n1000\n9999\n10000\n"
		"2147483647\n";
	const char	*file_name = TESTS_FPREFIX "putnbr.txt";

	nb_to_file(t_cases, sizeof(t_cases) / sizeof(t_cases[0]), file_name);
	return (file_cmp(file_name, expected));
}

static int	test_negatives(void)
{
	const int	nbs[] = {-1, -9, -10, -99, -100, -999, -1000, -9999, -10000, \
		INT_MIN};
	const char	*exp = "-1\n-9\n-10\n-99\n-100\n-999\n-1000\n-9999\n-10000\n"
		"-2147483648\n";
	const char	*file_name = TESTS_FPREFIX "putnbr.txt";

	nb_to_file(nbs, sizeof(nbs) / sizeof(nbs[0]), file_name);
	return (file_cmp(file_name, exp));
}

int	test_putnbr(void)
{
	if (test_positives() != 0)
		return (1);
	if (test_negatives() != 0)
		return (2);
	return (0);
}
