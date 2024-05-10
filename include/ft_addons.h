/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addons.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 09:34:42 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/10 08:00:35 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ADDONS_H
# define FT_ADDONS_H
# include <stddef.h>
# include "ft_defs.h"

/// @brief Free a null ended 2D array of pointers
/// @param arr The array to free
/// @note The array must be null ended
/// @file: src/ft_addons_free.c
void	ft_free_2d(void **arr);

/// @brief Get the length of a null ended 2D array of pointers
/// @param array The array to get the length of
/// @return The length of the array
/// @note The array must be null ended
/// @file: src/ft_addons_len.c
size_t	ft_len_2d(const void *const *array);

/// @brief Get the firs matching element in a vector using cmp
/// @param vector The vector to search in
/// @param key The key to search for
/// @param cmp The comparison function
/// @return The first matching element or NULL if not found
/// @file: src/ft_vector_get.c
void	*ft_vector_get(t_vector *vector, const void *key,
			int (*cmp)(const void *v_data, const void *key));

/// @brief Convert a vector to an array
/// @param vec The vector to convert
/// @return The array or NULL if malloc failed
/// @file: src/ft_addons/ft_vec_to_array.c
/// @note The array must be freed with free
/// @note The vector is destroyed
void	**ft_vec_to_array(t_vector **vec);

// File: src/ft_addons/ft_str_isalpha.c
bool	ft_str_isalpha(char *str);

// File: src/ft_addons/ft_str_isdigit.c
bool	ft_str_isdigit(char *str);

// File: src/ft_addons/ft_str_isnum.c
bool	ft_str_isnum(char *str);

// File: src/ft_addons/ft_strcspn.c
size_t ft_strcspn(const char *str, const char *charset);

#endif
