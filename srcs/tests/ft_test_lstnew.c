/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_lstnew.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 09:33:12 by juperez           #+#    #+#             */
/*   Updated: 2024/05/19 16:08:01 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

static bool	ft_run_test(void *content)
{
	t_list	*user = NULL;

	ft_time_function(USER_START);
	user = ft_lstnew(content);
	ft_time_function(USER_END);
	if (strcmp((char *)user->content, (char *)content))
	{
		ft_result_input_str((char *)content, NULL);
		ft_result_output_str((char *)user->content, NULL);
		ft_print_result(false);
		free(user);
		return (false);
	}
	free(user);
	return (true);
}

bool	ft_test_lstnew(char *name)
{
	size_t	i = 0, grade = 0;

	(void)name;
	while (g_str2_tests[i])
	{
		grade += ft_run_test((void *)g_str2_tests[i]);
		i++;
	}
	return (grade == i);
}
