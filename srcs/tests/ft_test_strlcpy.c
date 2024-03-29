/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_strlcpy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 09:25:46 by juperez           #+#    #+#             */
/*   Updated: 2024/03/28 17:31:09 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

bool	ft_test_strlcpy(char *name, void **test)
{
	const char	*tests = test ? *(const char **)test : g_str_tests[1];
	size_t		i = 0, grade = 0, user_r, libc_r;
	char		user[] = "................", libc[] = "................";
	bool		success;

	(void)name;
	while (i < 16)
	{
		ft_time_function(USER_START);
		user_r = ft_strlcpy(user, tests, i);
		ft_time_function(USER_END_LIBC_START);
		libc_r = strlcpy(libc, tests, i);
		ft_time_function(LIBC_END);
		success = (!strcmp(user, libc) && user_r == libc_r);
		if (!success)
		{
			ft_result_input_sizet(i);
			ft_result_input_str((char *)tests, NULL);
			ft_result_output_sizet(user_r, user_r);
			ft_result_output_str(user, libc);
			ft_print_result(true);
		}
		grade += success;
		i++;
	}
	return (grade == i);
}
