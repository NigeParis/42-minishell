/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_realloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 12:21:02 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/31 15:28:02 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int	test_realloc(void)
{
	char	*str;
	char	*str_ret;

	str = ft_calloc(15, sizeof(char));
	ft_strlcpy(str, "Hello world", 15);
	str = ft_realloc(str, 25, 15);
	ft_strlcat(str, " this is zod!", 25);
	if (ft_strcmp(str, "Hello world this is zod!") != 0)
		return (1);
	str_ret = ft_realloc(str, 10, 10);
	if (str != str_ret)
		return (2);
	free(str);
	return (0);
}
