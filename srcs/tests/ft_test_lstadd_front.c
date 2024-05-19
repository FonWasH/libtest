/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_lstadd_front.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 09:33:25 by juperez           #+#    #+#             */
/*   Updated: 2024/05/19 16:45:52 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

const char	*g_lstadd_front_str[] = {
	"5",
	"4",
	"3",
	"2",
	"1",
	NULL
};

const char	*g_front_order_str[] = {
	"1",
	"2",
	"3",
	"4",
	"5",
	NULL
};

static bool	ft_run_test(void)
{
	t_list	*user = NULL;
	t_list	*tmp = NULL;
	size_t	size = 0;

	ft_time_function(USER_START);
	for (size_t i = 0; g_lstadd_front_str[i]; i++)
		ft_lstadd_front(&user, ft_lstnew((void *)g_lstadd_front_str[i]));
	ft_time_function(USER_END);
	tmp = user;
	size = lst_size(user);
	if (size != 5)
	{
		ft_result_input_sizet(5);
		ft_result_output_sizet(size, 5);
		ft_print_result(false);
		printf(LST_FRONT);
		free_lst(user);
		return (false);
	}
	for (size_t i = 0; g_front_order_str[i]; i++)
	{
		if (strcmp((char *)tmp->content, (char *)g_front_order_str[i]))
		{
			ft_result_input_str((char *)g_front_order_str[i], NULL);
			ft_result_output_str((char *)tmp->content, (char *)g_front_order_str[i]);
			ft_print_result(false);
			free_lst(user);
			return (false);
		}
		tmp = tmp->next;
	}
	free_lst(user);
	return (true);
}

bool	ft_test_lstadd_front(char *name)
{
	(void)name;
	return (ft_run_test());
}
