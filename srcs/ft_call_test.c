/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_call_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 08:42:22 by juperez           #+#    #+#             */
/*   Updated: 2024/05/07 11:26:05 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

static bool	ft_check_functions(char *name, const t_ftest *ftest)
{
	for (size_t i = 0; ftest[i].name; i++)
	{
		if (!strcmp(name, ftest[i].name))
		{
			system(TITLE);
			printf("\n");
			ft_print_name(name);
			if (ft_test_norminette(name) && ft_check_sysfunc(name))
			{
				ft_reset_presult();
				ft_time_function(RESET);
				ft_grade((*ftest[i].f)(name));
			}
			return (true);
		}
	}
	return (false);
}

bool	ft_call_test(char *name)
{
	if (!ft_check_functions(name, g_fmandatory))
		if (!ft_check_functions(name, g_fbonus))
			return (false);
	return (true);
}

void	ft_call_all_test(bool title, bool force, const t_ftest *ftest)
{
	if (title)
		system(TITLE);
	for (size_t i = 0; ftest[i].name; i++)
	{
		printf("\n");
		ft_print_name(ftest[i].name);
		if (force || (ft_test_norminette(ftest[i].name) && ft_check_sysfunc(ftest[i].name)))
		{
			ft_reset_presult();
			ft_time_function(RESET);
			ft_grade((*ftest[i].f)(ftest[i].name));
		}
	}
}
