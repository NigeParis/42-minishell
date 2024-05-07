/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_types.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:13:10 by bgoulard          #+#    #+#             */
/*   Updated: 2023/12/30 13:20:43 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_TYPES_H
# define FT_VECTOR_TYPES_H

# ifndef FT_VECTOR_BASE_LEN
#  ifdef TEST
#   define FT_VECTOR_BASE_LEN 5
#  else
#   define FT_VECTOR_BASE_LEN 4096
#  endif
# endif

# include <stdbool.h>
# include <stddef.h>

/// @brief vector structure
/// @param datas array of pointers to the elements
/// @param count number of elements in the vector
/// @param cappacity number of elements that can be stored in the vector
typedef struct s_vector
{
	void	**datas;
	size_t	count;
	size_t	cappacity;
}			t_vector;

#endif /* FT_VECTOR_TYPES_H */