/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_struct.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 16:54:48 by bgoulard          #+#    #+#             */
/*   Updated: 2023/12/12 12:43:12 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_STRUCT_H
# define FT_STRING_STRUCT_H

# include <stddef.h>

/// @brief Structure representing a string
/// @param str The string
/// @param length The length of the string
/// @param capacity The capacity of the string
typedef struct s_string
{
	char	*str;
	size_t	length;
	size_t	capacity;
}			t_string;

#endif // FT_STRING_STRUCT_H
