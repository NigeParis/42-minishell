/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_round.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 23:10:18 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/23 23:10:36 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double	ft_round(double x)
{
	double	dec;
	double	round;

	dec = x - (int)x;
	if (dec >= 0.5)
		round = (int)x + 1;
	else
		round = (int)x;
	return (round);
}
