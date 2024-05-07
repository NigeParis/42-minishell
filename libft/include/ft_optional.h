/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_optional.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 18:07:13 by bgoulard          #+#    #+#             */
/*   Updated: 2024/01/07 14:07:40 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_OPTIONAL_H
# define FT_OPTIONAL_H

#include "ft_optional_types.h"
#include <stdbool.h>

/// @brief Create a new empty optional
/// @return The new optional
/// @note prefer creating from stack
/// @note WARNING: you must free the optional after use
t_optional *ft_optional_new(void);

/// @brief Create a new optional with a value
/// @param ptr The value to store in the optional
/// @return The new optional
/// @note prefer creating from stack
/// @note WARNING: you must free the optional after use
t_optional *ft_optional_from_val(void *ptr);

/// @brief Copies the value of an optional into another
/// @param dest The destination optional
/// @param src The source optional
void ft_optional_copy(t_optional *dest, t_optional *src);

/// @brief Chain functions calls on an optional until either there are no more
/// functions to call or one of the functions returns NULL
/// @param opt The optional to chain
/// @param f The functions to call
/// @return true if all functions were called, false otherwise
bool ft_optional_chain(t_optional *opt, void *(**f)(void *));

/// @brief Map a result of a function on an optional
/// @param opt The optional with the value to map
/// @param f The function to call
/// @return The new optional with the result of the functions.
/// @note WARNING: The function will return an empty optional if the result
/// of the function is NULL.
t_optional	ft_optional_map(t_optional *opt, void *(**f)(void *));

/// @brief Destroy an optional
/// @param opt The optional to destroy
/// @return true if the optional was destroyed, false otherwise
/// @note WARNING: The optional must be empty before destroying it
/// otherwise the function will return false
bool ft_optional_destroy(t_optional *opt);

/// @brief Duplicate an optional
/// @param org The optional to duplicate
/// @return The new optional
/// @note prefer creating from stack
/// @note WARNING: you must free the optional after use
t_optional *ft_optional_dup(t_optional *org);

/// @brief Return the value contained in an optional
/// @param opt The optional to unwrap
/// @return The value contained in the optional
/// @note WARNING: The optional must not be empty otherwise the function will
/// crash
void *ft_optional_unwrap(t_optional opt);

#endif /* FT_OPTIONAL_H */
