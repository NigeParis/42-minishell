/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_optional_unwrap.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 22:32:05 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/23 22:32:30 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_optional.h"
#include "ft_optional_types.h"
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int	test_optional_unwrap(void)
{
	t_optional	opt;
	int			*ptr;
	int			pid;
	int			status;

	opt.pres = OPT_SOME;
	ptr = malloc(sizeof(int));
	*ptr = 42;
	opt.val = ptr;
	if (ft_optional_unwrap(opt) != ptr)
		return (1);
	free(ptr);
	opt.pres = OPT_NONE;
	opt.val = NULL;
	pid = fork();
	if (pid == 0)
	{
		ft_optional_unwrap(opt);
		exit(0);
	}
	waitpid(pid, &status, 0);
	if (!WIFSIGNALED(status))
		return (2);
	return (0);
}
