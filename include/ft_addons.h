/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addons.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 14:48:25 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/14 17:51:47 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ADDONS_H
# define FT_ADDONS_H

#include "ft_string_types.h"
# include "ft_vector_types.h"

void	*ft_vec_collect(t_vector **vec, void *(*f)(const void *c_val, \
											   const void *d_val));
void	*ft_vec_end(t_vector *vec);

char	*ft_string_to_str_inplace(t_string *str);

#endif
