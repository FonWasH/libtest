/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_lstclear.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 09:34:28 by juperez           #+#    #+#             */
/*   Updated: 2024/05/20 14:57:57 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

static void	test_free(void *ptr)
{
	free(ptr);
	g_node_freed = 1;
}

static bool	ft_run_test(void)
{
	t_list	*lst = NULL;

	for (size_t i = 0; g_revn_tests[i]; i++)
		ft_lstadd_back(&lst, ft_lstnew((void *)strdup(g_revn_tests[i])));
	ft_time_function(USER_START);
	ft_lstclear(&lst, test_free);
	ft_time_function(USER_END);
	if (g_node_freed != 1)
	{
		ft_print_result(false);
		printf(LST_FREE);
		return (false);
	}
	return (true);
}

bool	ft_test_lstclear(char *name)
{
	(void)name;
	g_node_freed = 0;
	return (ft_run_test());
}
