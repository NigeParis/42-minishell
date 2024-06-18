/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_tests.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:31:03 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/31 15:37:50 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests/char_tests.h"
#include "tests/tests.h"

int	char_tests(void)
{
	int				i;
	const t_test	tests[] = {
	{"isalnum", test_ft_isalnum}, {"isalpha", test_ft_isalpha},
	{"isascii", test_ft_isascii}, {"isdigit", test_ft_isdigit},
	{"isprint", test_ft_isprint}, {"tolower", test_ft_tolower},
	{"toupper", test_ft_toupper}, {"isalnum", test_ft_isalnum},
	{"putchar", test_ft_putchar}, {"ishexdigit", test_ft_ishexdigit},
	{"isoctdigit", test_ft_isoctdigit}, {"isspace", test_ft_isspace},
	{NULL, NULL}};

	i = 0;
	run_test(tests, &i);
	return (i);
}
