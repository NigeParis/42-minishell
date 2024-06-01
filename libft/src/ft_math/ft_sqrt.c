/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 23:00:06 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/24 09:33:30 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// using newton's method
double	ft_sqrt(double nb)
{
	double	x;
	double	y;

	x = nb;
	if (nb <= 0)
		return (-1);
	y = 1;
	while (x - y > 0.0000001)
	{
		x = (x + y) / 2;
		y = nb / x;
	}
	return (x);
}
