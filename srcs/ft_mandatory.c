/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandatory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 07:49:06 by juperez           #+#    #+#             */
/*   Updated: 2024/03/27 21:36:12 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

void	ft_mandatory(bool title)
{
	if (title)
		system(TITLE);
	for (size_t i = 0; g_ftest[i].name; i++)
	{
		printf("\n");
		if (ft_test_norminette(g_ftest[i].name) && ft_check_sysfunc(g_ftest[i].name))
		{
			ft_reset_presult();
			ft_time_function(RESET);
			ft_grade((*g_ftest[i].f)(g_ftest[i].name, NULL));
		}
	}
}
