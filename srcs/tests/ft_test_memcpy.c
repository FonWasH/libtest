/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_memcpy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 21:39:19 by juperez           #+#    #+#             */
/*   Updated: 2024/03/30 10:26:44 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

static bool	ft_run_test(const void *src, size_t n)
{
	char	user[] = "................";
	char	libc[] = "................";

	n = n > 16 ? 16 : n;
	ft_time_function(USER_START);
	ft_memcpy((void *)user, src, n);
	ft_time_function(USER_END_LIBC_START);
	memcpy((void *)libc, src, n);
	ft_time_function(LIBC_END);
	if (strcmp(user, libc))
	{
		ft_result_input_sizet(n);
		ft_result_input_str((char *)src, NULL);
		ft_result_output_str(user, libc);
		ft_print_result(true);
	}
	return (true);
}

bool	ft_test_memcpy(char *name)
{
	size_t		i = 0, grade = 0;

	(void)name;
	while (g_str1_tests[i])
	{
		grade += ft_run_test((const void *)g_str1_tests[i], strlen(g_str1_tests[i]));
		i++;
	}
	return (grade == i);
}
