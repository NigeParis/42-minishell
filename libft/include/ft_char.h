/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 16:59:44 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/21 19:08:31 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CHAR_H
# define FT_CHAR_H

# include <stdbool.h>

/// @file: src/ft_string/ft_char/ft_isoctdigit.c
int		ft_isoctdigit(int c);

/// @file: src/ft_string/ft_char/ft_ishexdigit.c
int		ft_ishexdigit(int c);

/// @brief check if the char is a space character
/// @param c char to check
/// @return 1 if the char is a space character, 0 otherwise
/// @file: src/ft_string/ft_char/ft_isspace.c
int		ft_isspace(int c);

/// @brief check if the char is a lower case character
/// @param c char to check
/// @return 1 if the char is a lower case character, 0 otherwise
/// @file: src/ft_string/ft_char/ft_islower.c
int		ft_islower(int c);

/// @brief check if the char is an ascii character
/// @param c char to check
/// @return 1 if the char is an ascii character, 0 otherwise
/// @file: src/ft_string/ft_char/ft_isascii.c
int		ft_isascii(int c);

/// @brief check if the char is an upper case character
/// @param c char to check
/// @return 1 if the char is an upper case character, 0 otherwise
/// @file: src/ft_string/ft_char/ft_isupper.c
int		ft_isupper(int c);

/// @brief check if the char is an alphanumeric character
/// @param c char to check
/// @return 1 if the char is an alphanumeric character, 0 otherwise
/// @file: src/ft_string/ft_char/ft_isalnum.c
int		ft_isalnum(int c);

/// @brief check if the char is a digit
/// @param c char to check
/// @return 1 if the char is a digit, 0 otherwise
/// @file: src/ft_string/ft_char/ft_isdigit.c
int		ft_isdigit(int c);

/// @brief check if the char is a letter
/// @param c char to check
/// @return 1 if the char is a letter, 0 otherwise
/// @file: src/ft_string/ft_char/ft_isalpha.c
int		ft_isalpha(int c);

/// @brief pass a char to lower case
/// @param c char to pass to lower case
/// @return the char in lower case
/// @file: src/ft_string/ft_char/ft_tolower.c
int		ft_tolower(int c);

/// @brief check if the char is printable
/// @param c char to check
/// @return 1 if the char is printable, 0 otherwise
/// @file: src/ft_string/ft_char/ft_isprint.c
int		ft_isprint(int c);

/// @brief print the char on the specified file descriptor
/// @param c char to print
/// @param fd file descriptor to print on
/// @return void
void	ft_putchar_fd(char c, int fd);

/// @brief pass a char to lower case
/// @param c char to pass to lower case
/// @return the char in lower case
/// @file: src/ft_string/ft_char/ft_toupper.c
int		ft_toupper(int c);

#endif /* FT_CHAR_H */
