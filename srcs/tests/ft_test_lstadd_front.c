/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_lstadd_front.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 09:33:25 by juperez           #+#    #+#             */
/*   Updated: 2024/05/20 15:39:41 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

static bool	ft_run_test(void)
{
	t_list	*user = NULL;
	t_list	*tmp = NULL;
	size_t	user_size = 0, size = 0;

	ft_time_function(USER_START);
	while (g_revn_tests[size])
	{
		ft_lstadd_front(&user, ft_lstnew((void *)g_revn_tests[size]));
		size++;
	}
	ft_time_function(USER_END);
	tmp = user;
	user_size = ft_lst_size(user);
	if (user_size != size)
	{
		ft_result_input_sizet(size);
		ft_result_output_sizet(user_size, size);
		ft_print_result(false);
		printf(LST_SIZE);
		ft_free_lst(user);
		return (false);
	}
	for (size_t i = 0; g_sortn_tests[i]; i++)
	{
		if (strcmp((char *)tmp->content, (char *)g_sortn_tests[i]))
		{
			ft_result_input_str((char *)g_sortn_tests[i], NULL);
			ft_result_output_str((char *)tmp->content, (char *)g_sortn_tests[i]);
			ft_print_result(false);
			ft_free_lst(user);
			return (false);
		}
		tmp = tmp->next;
	}
	ft_free_lst(user);
	return (true);
}

bool	ft_test_lstadd_front(char *name)
{
	(void)name;
	return (ft_run_test());
}
