/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_optional_chain.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 22:28:51 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/31 15:58:53 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_optional.h"
#include "ft_optional_types.h"
#include "tests/optional_test.h"
#include "ft_defs.h"

int	test_optional_chain(void)
{
	t_optional				opt;
	bool					ret;
	const t_data_tr_i		function_list[3] = {
		add_4,
		add_4,
		NULL
	};

	opt.pres = OPT_SOME;
	opt.val = (void *)42;
	ret = ft_optional_chain(&opt, function_list);
	if (ret != true || opt.pres != OPT_SOME || opt.val != (void *)42 + 8)
		return (1);
	opt.pres = OPT_NONE;
	ret = ft_optional_chain(&opt, function_list);
	if (ret != false || opt.pres != OPT_NONE)
		return (1);
	ret = ft_optional_chain(&opt, NULL);
	if (ret != false || opt.pres != OPT_NONE)
		return (1);
	return (0);
}
