/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_all_mandatory.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 07:49:06 by juperez           #+#    #+#             */
/*   Updated: 2024/03/18 13:27:43 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

void	ft_all_mandatory(void)
{
	size_t	i;

	i = 0;
	while (g_ftest[i].name)
	{
		if (ft_test_norminette(g_ftest[i].name))
			ft_print_grade((*g_ftest[i].f)(g_ftest[i].name, g_ftest[i].test));
		i++;
	}
}
