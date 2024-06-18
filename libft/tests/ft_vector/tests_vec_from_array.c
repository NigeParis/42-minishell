/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_vec_from_array.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 11:19:37 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/28 08:04:26 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include "ft_vector_types.h"

int	checks_01(t_vector *vec, void **data)
{
	if (vec->count != 3 || vec->cappacity != FT_VECTOR_BASE_LEN
		|| vec->datas == NULL)
		return (1);
	else if (ft_vec_at(vec, 0) != data[0] || ft_vec_at(vec, 1) != data[1]
		|| ft_vec_at(vec, 2) != data[2])
		return (2);
	return (0);
}

int	checks_02(t_vector *vec, void **data)
{
	if (vec->count != 6 || vec->cappacity != 6 || vec->datas == NULL)
		return (3);
	else if (ft_vec_at(vec, 0) != data[0] || ft_vec_at(vec, 1) != data[1]
		|| ft_vec_at(vec, 2) != data[2] || ft_vec_at(vec, 3) != data[3]
		|| ft_vec_at(vec, 4) != data[4] || ft_vec_at(vec, 5) != data[5])
		return (4);
	return (0);
}

int	test_vec_from_array(void)
{
	void		*data[3];
	void		*data2[6];
	t_vector	*vec;

	data[0] = (void *)12;
	data[1] = (void *)13;
	data[2] = (void *)14;
	data2[0] = (void *)20;
	data2[1] = (void *)21;
	data2[2] = (void *)22;
	data2[3] = (void *)23;
	data2[4] = (void *)24;
	data2[5] = (void *)25;
	vec = ft_vec_from_array(data, sizeof(data) / sizeof(data[0]));
	if (checks_01(vec, data))
		return (checks_01(vec, data));
	ft_vec_destroy(&vec);
	vec = ft_vec_from_array(data2, sizeof(data2) / sizeof(*data2));
	if (checks_02(vec, data2))
		return (checks_02(vec, data2));
	return (ft_vec_destroy(&vec), 0);
}
