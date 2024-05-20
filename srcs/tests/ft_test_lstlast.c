/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_lstlast.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 09:33:51 by juperez           #+#    #+#             */
/*   Updated: 2024/05/20 15:38:28 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

static bool	ft_run_test(void)
{
	t_list	*lst = NULL, *last = NULL;
	size_t	i = 0;

	while (g_revn_tests[i])
	{
		ft_lstadd_front(&lst, ft_lstnew((void *)g_revn_tests[i]));
		i++;
	}
	ft_time_function(USER_START);
	last = ft_lstlast(lst);
	ft_time_function(USER_END);
	if (strcmp((char *)last->content, (char *)g_sortn_tests[i - 1]))
	{
		ft_result_input_str((char *)g_sortn_tests[i - 1], NULL);
		ft_result_output_str((char *)last->content, (char *)g_sortn_tests[i - 1]);
		ft_print_result(false);
		ft_free_lst(lst);
		return (false);
	}
	ft_free_lst(lst);
	return (true);
}

bool	ft_test_lstlast(char *name)
{
	(void)name;
	return (ft_run_test());
}
