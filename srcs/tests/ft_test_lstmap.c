/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_lstmap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 09:34:50 by juperez           #+#    #+#             */
/*   Updated: 2024/05/20 15:58:06 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

static bool	ft_run_test(void)
{
	t_list	*lst = NULL;
	t_list	*new = NULL;
	t_list	*tmp = NULL;

	for (size_t i = 0; g_lowa_tests[i]; i++)
		ft_lstadd_back(&lst, ft_lstnew(strdup((char *)g_lowa_tests[i])));
	ft_time_function(USER_START);
	new = ft_lstmap(lst, ft_duptoupper, free);
	ft_time_function(USER_END);
	tmp = new;
	for (size_t i = 0; g_uppa_tests[i]; i++)
	{
		if (strcmp((char *)tmp->content, (char *)g_uppa_tests[i]))
		{
			ft_result_input_str((char *)g_uppa_tests[i], NULL);
			ft_result_output_str((char *)tmp->content, (char *)g_uppa_tests[i]);
			ft_print_result(false);
			ft_lstclear(&lst, free);
			ft_lstclear(&new, free);
			return (false);
		}
		tmp = tmp->next;
	}
	ft_lstclear(&lst, free);
	ft_lstclear(&new, free);
	return (true);
}

bool	ft_test_lstmap(char *name)
{
	(void)name;
	return (ft_run_test());
}
