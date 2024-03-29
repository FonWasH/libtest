/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_strlen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 09:42:04 by juperez           #+#    #+#             */
/*   Updated: 2024/03/29 17:40:51 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

static bool	ft_run_test(const char *s)
{
	size_t	user, libc;

	ft_time_function(USER_START);
	user = ft_strlen(s);
	ft_time_function(USER_END_LIBC_START);
	libc = strlen(s);
	ft_time_function(LIBC_END);
	if (!(user == libc))
	{
		ft_result_input_str((char *)s, NULL);
		ft_result_output_sizet(user, libc);
		ft_print_result();
		return (false);
	}
	return (true);
}

bool	ft_test_strlen(char *name)
{
	size_t	i = 0, grade = 0;

	(void)name;
	while (g_str1_tests[i])
	{
		grade += ft_run_test(g_str1_tests[i]);
		i++;
	}
	return (grade == i);
}
