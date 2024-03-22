/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_call_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 08:42:22 by juperez           #+#    #+#             */
/*   Updated: 2024/03/22 12:23:48 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

bool	ft_call_test(char *name, void **test, int count)
{
	for (size_t i = 0; g_ftest[i].name; i++)
	{
		if (!strcmp(name, g_ftest[i].name) && ft_test_norminette(name))
		{
			ft_time_function("reset");
			ft_print_grade((*g_ftest[i].f)(name, count ? test : NULL));
			return (true);
		}
	}
	return (false);
}
