/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_test_utils.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 13:30:26 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/24 11:42:59 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LISTS_TEST_UTILS_H
# define LISTS_TEST_UTILS_H

# include "ft_list_types.h"
# include <stdbool.h>

void	create_2elem_dlist(t_dlist **list, void **data1, void **data2);
void	create_2elem_list(t_list **list, void **data1, void **data2);

#endif
