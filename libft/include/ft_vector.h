/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 13:37:46 by bgoulard          #+#    #+#             */
/*   Updated: 2023/12/30 13:05:51 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_H
# define FT_VECTOR_H

# include "ft_vector_types.h"

/* ************************************************************************** */
/*                            VECTOR MODULE                                   */
/* ************************************************************************** */

// ft_vector/ft_vec_add.c

/// @brief Add an element to the end of the vector
/// @param vec pointer to the vector
/// @param data data to add
/// @return true if the element was added, false otherwise
bool		ft_vec_add(t_vector **vec, void *data);

// ft_vector/ft_vec_apply.c

/// @brief Apply a function to all the elements of the vector
/// @param vec pointer to the vector
/// @param func function to apply
/// @return void
void		ft_vec_apply(t_vector *vec, void (*func)(void *));

// ft_vector/ft_vec_at.c

/// @brief Get an element from the vector
/// @param vec pointer to the vector
/// @param n index of the element
/// @return pointer to the element
void		*ft_vec_at(t_vector *vec, size_t n);

// ft_vector/ft_vec_cat.c

/// @brief Concatenate two vectors
/// @param vec_a pointer to the first vector
/// @param vec_b pointer to the second vector
/// @return true if the vectors were concatenated, false otherwise
/// @note the second vector is not modified therefore it is not cleared.
/// Be careful with double free.
bool		ft_vec_cat(t_vector **vec_a, const t_vector *vec_b);

// ft_vector/ft_vec_clear.c

/// @brief Clear a vector by setting its size to 0 and all elements to NULL
/// @param vec pointer to the vector cleared
/// @return void
/// @note the data is not freed, cappacity is not changed. if you want to free
//  the data / reduce the cappacity use ft_vec_clear, then ft_vec_shrink.
void		ft_vec_clear(t_vector *vec);

// ft_vector/ft_vec_destroy.c

/// @brief Destroy a vector
/// @param vec pointer to the vector
/// @return true if the vector was destroyed, false otherwise
bool		ft_vec_destroy(t_vector **vec);

// ft_vector/ft_vec_filter.c

/// @brief Filter a vector
/// @param vec pointer to the vector
/// @param func function to filter the vector
/// @param del function to delete the elements filtered
/// @return void
void		ft_vec_filter(t_vector *vec, bool (*func)(void *),
				void (*del)(void *));

// ft_vector/ft_vec_map.c

/// @brief Map a vector
/// @param vec pointer to the vector
/// @param func function to map the vector
/// @return pointer to the new vector
/// @note the new vector is allocated and must be freed
/// @note as vec is an array under the hood,
//	the new vector will be a collection of adress.
/// therefore, if your function changes the value of the data,
//	the new vector will be a collection of pointers to the
//  data of the old vector. If you want to do that and change the
//  value of the data, use ft_vec_apply instead.
t_vector	*ft_vec_map(t_vector *vec, void *(*func)(void *));

// ft_vector/ft_vec_new.c

/// @brief Create a new vector
/// @return pointer to the new vector
t_vector	*ft_vec_new(void);

/// @brief Create a new vector with a given capacity
/// @param n capacity of the new vector
/// @return pointer to the new vector
t_vector	*ft_vec_from_size(size_t n);

/// @brief Create a new vector from an array
/// @param data data to add to the vector
/// @param count count of the data
/// @return pointer to the new vector
t_vector	*ft_vec_from_array(void **data, size_t count);

/// @brief Create a new vector from an array and steals ownership of the array
/// @param data data to create the vector from
/// @param count count of the data array
/// @return pointer to the new vector
t_vector	*ft_vec_convert_alloccarray(void **data, size_t count);

// ft_vector/ft_vec_remove.c

/// @brief Remove an element from the vector
/// @param vector vector to remove the element from
/// @param n index of the element to remove
/// @param del function to delete the elements data
void		ft_vec_remove(t_vector *vector, size_t n, void (*del)(void *));

/// @brief Remove an element from the vector
/// @param vector vector to remove the element from
/// @param func function to remove the element
/// @param del function to delete the elements data
/// @return void
/// @note very similar to ft_vec_filter... TODO: check if needed
void		ft_vec_remove_if(t_vector *vector, bool (*func)(void *),
				void (*del)(void *));

// ft_vector/ft_vec_reserve.c

/// @brief Reserve a given size for the vector
/// @param vec pointer to the vector
/// @param size size to reserve
/// @return true if the vector was reserved or size is smaller
/// than the current cappacity, false otherwise
bool		ft_vec_reserve(t_vector **vec, size_t size);

// ft_vector/ft_vec_reverse.c

/// @brief Reverse a vector
/// @param vector vector to reverse
/// @return void
void		ft_vec_reverse(t_vector *vector);

// ft_vector/ft_vec_shift.c

/// @brief Shift a vector
/// @param vec pointer to the vector
/// @param start index to start the shift
/// @param shift number of elements to shift
/// @return void
void		ft_vec_shift(t_vector *vec, size_t start, size_t shift);

// ft_vector/ft_vec_sort.c

/// @brief Sort a vector
/// @param vec pointer to the vector
/// @param cmp_f function to compare the elements
/// @return void
void		ft_vec_sort(t_vector *vec, int (*cmp_f)(void *, void *));

// ft_vector/ft_vec_shrink.c

/// @brief Shrink a vector
/// @param vec pointer to the vector
/// @return true if the vector was shrunk, false otherwise
bool		ft_vec_shrink(t_vector *vec);

// ft_vector/ft_vec_swap.c

/// @brief Swap two elements of a vector
/// @param vec pointer to the vector
/// @param a index of the first element
/// @param b index of the second element
/// @return void
void		ft_vec_swap(t_vector *vec, size_t a, size_t b);

#endif /* FT_VECTOR_H */
