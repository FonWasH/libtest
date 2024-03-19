/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_argument.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 08:42:22 by juperez           #+#    #+#             */
/*   Updated: 2024/03/19 04:14:34 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

bool	ft_call_test(char *name, const char **test, int count)
{
	bool	match = false;

	for (size_t i = 0; g_ftest[i].name; i++)
	{
		if (!strcmp(name, g_ftest[i].name) && ft_test_norminette(name))
		{
			ft_print_grade((*g_ftest[i].f)(name, count ? test : g_ftest[i].test));
			match = true;
			break ;
		}
	}
	return (match);
}
