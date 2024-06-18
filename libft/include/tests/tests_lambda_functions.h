/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_lambda_functions.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 11:41:41 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/24 14:05:47 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_LAMBDA_FUNCTIONS_H
# define TESTS_LAMBDA_FUNCTIONS_H
# include <stdbool.h>

// File: tests/lambda_functions.h
bool	is42(const void *data);
void	add42(void *data);
void	*add42_ret(const void *data);
int		cmp_int(const void *a, const void *b);
void	**creat_tb(void);

#endif
