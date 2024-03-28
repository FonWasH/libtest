/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_strchr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 09:26:37 by juperez           #+#    #+#             */
/*   Updated: 2024/03/28 13:22:04 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

const char		*g_strchr_tests[] = {
	"abcdefghijklmnopqrstuvwxyz",
	"salut42",
	NULL
};

bool	ft_test_strchr(char *name, void **test)
{
	const char	**tests = test ? (const char **)test : g_strchr_tests;
	size_t		i = 0, grade = 0;
	char		*user, *libc;
	bool		success;

	(void)name;
	while (tests[1][i])
	{
		ft_time_function(USER_START);
		user = ft_strchr(tests[0], (int)tests[1][i]);
		ft_time_function(USER_END_LIBC_START);
		libc = strchr(tests[0], (int)tests[1][i]);
		ft_time_function(LIBC_END);
		success = (user == libc);
		if (!success)
		{
			ft_result_input_str((char *)tests[0], NULL);
			ft_result_input_int((int)tests[1][i]);
			ft_result_output_str(user, libc);
			ft_print_result(true);
		}
		grade += success;
		i++;
	}
	return (grade == i);
}
