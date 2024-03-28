/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_strlcat.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 08:48:30 by juperez           #+#    #+#             */
/*   Updated: 2024/03/28 12:03:46 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

bool	ft_test_strlcat(char *name, void **test)
{
	const char	*tests = test ? *(const char **)test : g_str_tests[1];
	size_t		size[] = {0, 1, 4, 5, 8, 16, 20};
	size_t		i = 0, grade = 0, count = sizeof(size) / sizeof(size[0]), user_r, libc_r;
	char		user[] = "DEST\0................", libc[] = "DEST\0................";
	bool		success;

	(void)name;
	while (i < count)
	{
		ft_time_function(USER_START);
		user_r = ft_strlcat(user, tests, size[i]);
		ft_time_function(USER_END_LIBC_START);
		libc_r = strlcat(libc, tests, size[i]);
		ft_time_function(LIBC_END);
		success = (!strcmp(user, libc) && user_r == libc_r);
		if (!success)
		{
			ft_result_input_sizet(size[i]);
			ft_result_input_str((char *)tests, NULL);
			ft_result_output_sizet(user_r, libc_r);
			ft_result_output_str(user, libc);
			ft_print_result(true);
		}
		grade += success;
		i++;
	}
	return (grade == i);
}
