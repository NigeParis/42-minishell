/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 04:18:57 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/01 12:12:53 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "tests/tests.h"

#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#ifdef FORK_TESTS

static int	run_t_test(t_test test, int *collect)
{
	int	ret;
	int	pid;

	pid = fork();
	if (pid == 0)
		exit(test.test());
	else
	{
		waitpid(pid, &ret, 0);
		ft_putstr_fd(test.name, STDOUT_FILENO);
		if (WIFEXITED(ret) && ret == 0)
			ft_putstr_fd(" \033[32mOK \033[0m", STDOUT_FILENO);
		else
		{
			ft_putstr_fd(" \033[31mKO\033[0m ret::", STDOUT_FILENO);
			if (WIFEXITED(ret))
				ft_putnbr_fd(WEXITSTATUS(ret), STDOUT_FILENO);
			else
				ft_putstr_fd("crash", STDOUT_FILENO);
		}
		ft_putstr_fd("\n", STDOUT_FILENO);
		*collect += ret;
	}
	return (ret);
}

#else

static int	run_t_test(t_test test, int *collect)
{
	int	ret;

	ret = test.test();
	*collect += ret;
	if (ret != 0)
	{
		ft_putstr_fd(test.name, STDOUT_FILENO);
		ft_putstr_fd(" \033[31mKO\033[0m ret::", STDOUT_FILENO);
		ft_putnbr_fd(ret, STDOUT_FILENO);
		ft_putstr_fd("\n", STDOUT_FILENO);
	}
	else
		ft_putstr_fd(" \033[32mOK\033[0m", STDOUT_FILENO);
	return (ret);
}

#endif

int	open_test_file(char **func_to_test)
{
	char	*file;
	int		fd;

	file = ft_strjoin(TESTS_FPREFIX, *func_to_test);
	fd = open(file, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
	{
		ft_putstr_fd("Error: on oppening ", STDERR_FILENO);
		ft_putstr_fd(file, STDERR_FILENO);
		return (free(file), -1);
	}
	*func_to_test = file;
	return (fd);
}

void	destroy_test_file(int fd, const char *file)
{
	close(fd);
	unlink(file);
}

int	run_test(const t_test *test, int *collect)
{
	size_t	i;
	int		ret;
	int		sum;

	ret = 0;
	sum = 0;
	i = 0;
	while (test[i].name)
	{
		ret = run_t_test(test[i], &sum);
		*collect += ret;
		sum += ret;
		i++;
	}
	return (sum);
}
