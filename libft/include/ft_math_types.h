/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math_types.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 19:08:43 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/18 19:09:28 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATH_TYPES_H
# define FT_MATH_TYPES_H

typedef struct s_complex
{
	double	real;
	double	imaginary;
}			t_complex;

typedef struct s_vec2
{
	double	x;
	double	y;
}			t_vec2;

typedef struct s_vec3
{
	double	x;
	double	y;
	double	z;
}			t_vec3;

typedef struct s_vec4
{
	double	x;
	double	y;
	double	z;
	double	w;
}			t_vec4;

#endif
