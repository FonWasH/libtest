/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_lstdelone.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 09:34:14 by juperez           #+#    #+#             */
/*   Updated: 2024/05/20 14:58:03 by juperez          ###   ########.fr       */
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

	lst = ft_lstnew(ft_strdup("test"));
	ft_time_function(USER_START);
	ft_lstdelone(lst, test_free);
	ft_time_function(USER_END);
	if (g_node_freed != 1)
	{
		ft_print_result(false);
		printf(LST_FREE);
		return (false);
	}
	return (true);
}

bool	ft_test_lstdelone(char *name)
{
	(void)name;
	g_node_freed = 0;
	return (ft_run_test());
}
