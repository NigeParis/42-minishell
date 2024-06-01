/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:52:58 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/21 17:36:58 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_char.h"

static int	ft_is_valid(const char *base)
{
	int	i;
	int	j;

	i = 0;
	if (ft_strlen(base) < 2)
		return (0);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || ft_isspace(base[i]))
			return (0);
		j = i + 1;
		while (base[j])
			if (base[i] == base[j++])
				return (0);
		i++;
	}
	return (1);
}

int	ft_atoi_base(const char *str, const char *base)
{
	const int	base_len = ft_strlen(base);
	int			i;
	int			nb;
	int			sign;

	i = 0;
	nb = 0;
	sign = 1;
	if (!ft_is_valid(base))
		return (0);
	while (ft_isspace(str[i]))
		i++;
	while (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			sign *= -1;
	while (str[i] && ft_strchr(base, str[i]))
		nb = nb * base_len + ft_strchr(base, str[i++]) - base;
	return (nb * sign);
}
