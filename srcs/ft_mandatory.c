/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandatory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 07:49:06 by juperez           #+#    #+#             */
/*   Updated: 2024/03/22 14:08:16 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

void	ft_mandatory(bool title)
{
	if (title)
		system("./scripts/title.sh");
	for (size_t i = 0; g_ftest[i].name; i++)
	{
		printf("\n");
		if (ft_test_norminette(g_ftest[i].name))
		{
			ft_time_function(RESET);
			ft_print_grade((*g_ftest[i].f)(g_ftest[i].name, NULL));
		}
	}
}
