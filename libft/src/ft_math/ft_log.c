/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_log.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 10:09:57 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/24 00:13:26 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_ullogof(unsigned long long nbr, int base)
{
	int	pow;

	pow = -1;
	while (nbr)
	{
		nbr /= base;
		pow++;
	}
	return (pow);
}

int	ft_llogof(long long nbr, int base)
{
	if (nbr <= 0)
		return (-1);
	return (ft_ullogof((unsigned long long)nbr, base));
}

int	ft_logof(int nbr, int base)
{
	if (nbr <= 0)
		return (-1);
	return (ft_llogof((long long)nbr, base));
}

int	ft_log(int nbr)
{
	return (ft_logof(nbr, 10));
}
