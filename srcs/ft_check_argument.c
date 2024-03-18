/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_argument.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 08:42:22 by juperez           #+#    #+#             */
/*   Updated: 2024/03/18 14:19:57 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

bool	ft_check_argument(char *name, const char **test, int count)
{
	bool	match;
	size_t	i;

	match = false;
	i = 0;
	while (g_ftest[i].name)
	{
		if (!strcmp(name, g_ftest[i].name) && ft_test_norminette(name))
		{
			if (count)
				ft_print_grade((*g_ftest[i].f)(name, test));
			else
				ft_print_grade((*g_ftest[i].f)(name, g_ftest[i].test));
			match = true;
			break ;
		}
		i++;
	}
	return (match);
}
