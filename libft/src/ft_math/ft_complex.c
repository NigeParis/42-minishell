/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 08:11:12 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/24 09:07:37 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

double	ft_complex_abs(t_complex nb)
{
	return (ft_sqrt(nb.real * nb.real + nb.imaginary * nb.imaginary));
}

t_complex	ft_complex_addl(t_complex nb, long factor)
{
	return ((t_complex){.real = nb.real + factor,
		.imaginary = nb.imaginary + factor});
}

t_complex	ft_complex_mull(t_complex nb, long factor)
{
	return ((t_complex){.real = nb.real * factor,
		.imaginary = nb.imaginary * factor});
}

t_complex	ft_complex_muld(t_complex nb, double factor)
{
	return ((t_complex){.real = nb.real * factor,
		.imaginary = nb.imaginary * factor});
}
