/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_optional.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 18:07:13 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/31 18:51:18 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_OPTIONAL_H
# define FT_OPTIONAL_H

# include "ft_defs.h"
# include "ft_optional_types.h"
# include <stdbool.h>

/* ************************************************************************** */
/*                                  OPTIONAL                                  */
/* ************************************************************************** */

/// @brief Create a new empty optional
/// @return The new optional
/// @note prefer creating from stack
/// @note WARNING: you must free the optional after use
t_optional	*ft_optional_new(void);

/// @brief Create a new optional with a value
/// @param ptr The value to store in the optional
/// @return The new optional
/// @note prefer creating from stack
/// @note WARNING: you must free the optional after use
t_optional	*ft_optional_from_val(void *ptr);

/// @brief Copies the value of an optional into another
/// @param dest The destination optional
/// @param src The source optional
void		ft_optional_copy(t_optional *dest, t_optional *src);

/// @brief Chain functions calls on an optional until either there are no more
/// functions to call or one of the functions returns NULL
/// @param opt The optional to chain
/// @param f The functions to call
/// @return true if all functions were called, false otherwise
/// @note This function was made to emulate object programming pipelines
/// @note WARNING: The function will return false if the optional is empty
/// or if the function list is NULL
/// @code
/// #include "ft_optional.h"
/// #include "ft_optional_types.h"
/// #include "ft_string.h"
/// #include "ft_defs.h"
/// #include <fcntl.h>
/// #include <stdio.h>
/// 
/// char	*ft_fd_to_buff(int fd);
/// 
/// void *check_file_ext(void *filename) {
///   if (!filename)
/// 	return (NULL);
///   if (ft_strend_with(filename, ".txt"))
///     return (filename);
///   return (printf("Error: file must be a .txt\n"), free(filename), NULL);
/// }
/// 
/// void *load_file_to_buff(void *filename) {
///   int fd;
///   char *buff;
/// 
///   fd = open(filename, O_RDONLY);
///   if (fd < 0)
///   {
/// 	printf("Error: could not open file\n");
///     return (free(filename), NULL);
///   }
///   buff = ft_fd_to_buff(fd);
///   return (close(fd), free(filename), buff);
/// }
/// 
/// int main(int ac, char **av) {
///   t_optional opt = {OPT_NONE, NULL};
///   const t_data_tr_i function_list[] = {
/// 		check_file_ext,
/// 		load_file_to_buff,
///         NULL};
///   
///   if (ac != 2)
/// 	return (printf("Usage: %s <file.txt>\n", av[0]), 1);
///   opt.pres = OPT_SOME;
///   opt.val = ft_strdup(av[1]);
///   if (!ft_optional_chain(&opt, function_list))
///     return (printf("Error: could not load file\n"), 1);
///   // Do something with the file
///   printf("File content: %s\n", (char *)opt.val);
///   return (free(opt.val), ft_optional_destroy(&opt), 0);
/// }
/// 
/// @endcode
/// @note Demonstrated above, we crate a list of operations to perform on a file
/// name, we then chain the operations on the optional until either:
///		1) an operation returns NULL (we return false)
///			-or-
///		2) there are no more operations to perform (we return true)
bool		ft_optional_chain(t_optional *opt, const t_data_tr_i *f);

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
bool		ft_optional_destroy(t_optional *opt);

/// @brief Duplicate an optional
/// @param org The optional to duplicate
/// @return The new optional
/// @note prefer creating from stack
/// @note WARNING: you must free the optional after use
t_optional	*ft_optional_dup(t_optional *org);

/// @brief Return the value contained in an optional
/// @param opt The optional to unwrap
/// @return The value contained in the optional
/// @note WARNING: The optional must not be empty otherwise the function will
/// crash
void		*ft_optional_unwrap(t_optional opt);

#endif /* FT_OPTIONAL_H */
