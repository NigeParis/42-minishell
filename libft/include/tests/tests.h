/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 11:15:14 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/31 14:13:02 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_H
# define TESTS_H

# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>
# define TESTS_FPREFIX "build/test_"

# ifndef FORK_TESTS
#  define FORK_TESTS 1
# endif

typedef struct s_test
{
	char	*name;
	int		(*test)(void);
}			t_test;

int			run_test(const t_test *test, int *collect);
int			open_test_file(char **func_to_test);
void		destroy_test_file(int fd, const char *file);

int			tests_map(void);
int			tests_math(void);
int			tests_linked_list_all(void);
int			tests_doubly_linked_list_all(void);
int			tests_vector(void);
int			tests_string(void);
int			tests_optional(void);
int			tests_args(void);

#endif /* TESTS_H */
