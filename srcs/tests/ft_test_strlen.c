/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_strlen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 09:42:04 by juperez           #+#    #+#             */
/*   Updated: 2024/03/28 20:29:56 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

bool	ft_test_strlen(char *name, void **test)
{
	const char	**tests = test ? (const char **)test : g_str1_tests;
	size_t		i = 0, grade = 0, user, libc;
	bool		success;

	(void)name;
	while (tests[i])
	{
		ft_time_function(USER_START);
		user = ft_strlen(tests[i]);
		ft_time_function(USER_END_LIBC_START);
		libc = strlen(tests[i]);
		ft_time_function(LIBC_END);
		success = (user == libc);
		if (!success)
		{
			ft_result_input_str((char *)tests[i], NULL);
			ft_result_output_sizet(user, libc);
			ft_print_result(true);
		}
		grade += success;
		i++;
	}
	return (grade == i);
}
