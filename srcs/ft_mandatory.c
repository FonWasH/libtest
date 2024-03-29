/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandatory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 07:49:06 by juperez           #+#    #+#             */
/*   Updated: 2024/03/29 15:55:31 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

void	ft_mandatory(bool title, bool force)
{
	if (title)
		system(TITLE);
	for (size_t i = 0; g_ftest[i].name; i++)
	{
		printf("\n");
		ft_print_name(g_ftest[i].name);
		if (force || (ft_test_norminette(g_ftest[i].name) && ft_check_sysfunc(g_ftest[i].name)))
		{
			ft_reset_presult();
			ft_time_function(RESET);
			ft_grade((*g_ftest[i].f)(g_ftest[i].name));
		}
	}
}
