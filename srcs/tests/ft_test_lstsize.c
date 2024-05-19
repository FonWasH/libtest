/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_lstsize.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 09:33:39 by juperez           #+#    #+#             */
/*   Updated: 2024/05/19 17:04:14 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

static bool	ft_run_test(void)
{
	t_list	*lst = NULL;
	size_t	user_size = 0, size = 0;

	for (size_t i = 0; g_sortn_tests[i]; i++)
		ft_lstadd_front(&lst, ft_lstnew((void *)g_sortn_tests[i]));
	ft_time_function(USER_START);
	user_size = ft_lstsize(lst);
	ft_time_function(USER_END);
	size = lst_size(lst);
	if (user_size != size)
	{
		ft_result_input_sizet(size);
		ft_result_output_sizet(user_size, size);
		ft_print_result(false);
		printf(LST_SIZE);
		free_lst(lst);
		return (false);
	}
	free_lst(lst);
	return (true);
}

bool	ft_test_lstsize(char *name)
{
	(void)name;
	return (ft_run_test());
}
