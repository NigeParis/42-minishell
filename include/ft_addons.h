/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addons.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 09:34:42 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/09 09:40:23 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_ADDONS_H
# define FT_ADDONS_H
# include <stddef.h>

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
size_t	ft_len_2d(const void * const *array);

#endif
