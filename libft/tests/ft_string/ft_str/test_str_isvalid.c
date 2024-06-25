/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_str_isvalid.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 08:10:32 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/30 00:44:55 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int	string_validator(int c)
{
	return (c == 'a' || c == 'b' || c == 'c');
}

int	test_str_isvalid(void)
{
	if (ft_str_isvalid("abc", string_validator) != 1 || ft_str_isvalid("abcabc",
			string_validator) != 1 || ft_str_isvalid("aabbcc",
			string_validator) != 1)
		return (1);
	if (ft_str_isvalid("abd", string_validator) != 0 || ft_str_isvalid("bap",
			string_validator) != 0 || ft_str_isvalid("ck",
			string_validator) != 0)
		return (2);
	return (0);
}
