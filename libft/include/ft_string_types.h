/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_types.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 16:54:48 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/28 09:08:28 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_TYPES_H
# define FT_STRING_TYPES_H

# include <stddef.h>
# ifndef MAX_FD
#  ifdef TEST
#   define MAX_FD 5
#  else
#   define MAX_FD 1024
#  endif
# endif

# ifndef BUFFER_SIZE
#  ifdef TEST
#   define BUFFER_SIZE 5
#  else
#   define BUFFER_SIZE 4096
#  endif
# endif

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

#endif /* FT_STRING_TYPES_H */
