/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 12:22:59 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/25 12:23:08 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int	test_free(void)
{
	char	*str;

	str = ft_calloc(10, sizeof(char));
	ft_free((void **)&str);
	if (str != NULL)
		return (1);
	return (0);
}
