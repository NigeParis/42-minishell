/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 14:37:09 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/09 18:07:09 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_H
# define PAIR_H

typedef struct s_pair
{
	void	*first;
	void	*second;
}	t_pair;

/// Create a new pair
/// @brief Create a new pair with the given elements using malloc
/// @param first The first element of the pair
/// @param second The second element of the pair
/// @return The new pair
/// @file src/pair/new_pair.c
/// @note The pair is allocated with malloc
/// @warning The pair must be destroyed with destroy_pair
/// @see destroy_pair
/// @see destroy_pair_deep
t_pair	*new_pair(void *first, void *second);

/// Destroy a pair
/// @brief Destroy a pair and free the memory allocated
/// @param content The pair to destroy
/// @file src/pair/destroy_pair.c
/// @see new_pair
void	destroy_pair(t_pair *content);

/// Destroy a pair and its content
/// @brief Destroy a pair and its content and free the memory allocated
/// @param content The pair to destroy
/// @file src/pair/destroy_pair.c
/// @see new_pair
/// @see destroy_pair
/// @warning The content of the pair must be allocated with malloc
void	destroy_pair_deep(t_pair *content);

/// Get the first element of a pair
/// @brief Get the first element of a pair
/// @param pair The pair to get the first element from
/// @return The first element of the pair
/// @file src/pair/access_pair.c
void	*pair_first(t_pair *pair);

/// Get the second element of a pair
/// @brief Get the second element of a pair
/// @param pair The pair to get the second element from
/// @return The second element of the pair
/// @file src/pair/access_pair.c
void	*pair_second(t_pair *pair);

/// Compare the first element of two pairs
/// @brief Compare the first element of two pairs
/// @param content The pair to compare
/// @param to_find The pair to compare with
/// @param cmp The comparison function to use of form -1, 0, 1 if <, ==, >
/// @return The result of the comparison
/// @file src/pair/fcmp_pair.c
/// @see pair_cmpfirst
int		pair_fcmpfirst(t_pair *content, t_pair *to_find, int (*f)(void *,
				void *));

/// Compare the second element of two pairs
/// @brief Compare the second element of two pairs
/// @param content The pair to compare
/// @param to_find The pair to compare with
/// @param cmp The comparison function to use of form -1, 0, 1 if <, ==, >
/// @return The result of the comparison
/// @file src/pair/fcmp_pair.c
/// @see pair_cmpsecond
int		pair_fcmpsecond(t_pair *content, t_pair *to_find, int (*f)(void *,
				void *));

/// Compare two pairs
/// @brief Compare two pairs
/// @param content The pair to compare
/// @param to_find The pair to compare with
/// @param cmp The comparison function to use of form -1, 0, 1 if <, ==, >
/// @return The result of the comparison
/// @file src/pair/fcmp_pair.c
/// @see pair_cmp
int		pair_fcmp(t_pair *content, t_pair *to_find, int (*f)(void *, void *));

/// Compare the first element of two pairs
/// @brief Compare the first element of two pairs
/// @param content The pair to compare
/// @param to_find The pair to compare with
/// @return The result of the comparison
/// @note The comparison is made on the pointers themselves
/// @file src/pair/cmp_pair.c
/// @see pair_cmpfirst
int		pair_cmpfirst(t_pair *content, t_pair *to_find);

/// Compare the second element of two pairs
/// @brief Compare the second element of two pairs
/// @param content The pair to compare
/// @param to_find The pair to compare with
/// @return The result of the comparison
/// @note The comparison is made on the pointers themselves
/// @file src/pair/cmp_pair.c
/// @see pair_cmpsecond
int		pair_cmpsecond(t_pair *content, t_pair *to_find);

/// Compare two pairs
/// @brief Compare two pairs
/// @param content The pair to compare
/// @param to_find The pair to compare with
/// @return The result of the comparison
/// @note The comparison is made on the pointers themselves
/// @file src/pair/cmp_pair.c
/// @see pair_fcmp
int		pair_cmp(t_pair *content, t_pair *to_find);
#endif
