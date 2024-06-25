/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strappend.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 11:12:40 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/30 11:19:40 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int	test_strappend_c(void)
{
	char	*str;

	str = ft_strdup("Hello");
	if (!str)
		return (1);
	if (ft_strappend_c(&str, ' ') == 0)
		return (2);
	if (ft_strcmp(str, "Hello ") != 0)
		return (3);
	if (ft_strappend_c(&str, 'W') == 0)
		return (4);
	if (ft_strcmp(str, "Hello W") != 0)
		return (5);
	free(str);
	return (0);
}
