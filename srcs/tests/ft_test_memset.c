/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_memset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 08:06:06 by juperez           #+#    #+#             */
/*   Updated: 2024/03/28 08:38:33 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

static bool	ft_test_memset_size(char *user, char *libc, int c)
{
	size_t	size[] = {0, 1, 8, 16};
	size_t	count = sizeof(size) / sizeof(size[0]);

	for (size_t i = 0; i < count; i++)
	{
		ft_time_function(USER_START);
		ft_memset(user, c, size[i]);
		ft_time_function(USER_END_LIBC_START);
		memset(libc, c, size[i]);
		ft_time_function(LIBC_END);
		if (strcmp(user, libc))
		{
			ft_result_input_sizet(size[i]);
			ft_result_input_int(c);
			ft_result_output_str(user, libc);
			ft_print_result(true);
			return (false);
		}
	}
	return (true);
}

bool	ft_test_memset(char *name, void **test)
{
	char		**tests = test ? (char **)test : (char **)g_chr_tests;
	size_t		i = 0, grade = 0;
	char		user[] = "................", libc[] = "................";

	(void)name;
	while (tests[0][i])
	{
		grade += ft_test_memset_size(user, libc, (int)tests[0][i]);;
		i++;
	}
	return (grade == i);
}
