/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_strrchr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 09:27:27 by juperez           #+#    #+#             */
/*   Updated: 2024/03/28 20:29:56 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

bool	ft_test_strrchr(char *name, void **test)
{
	const char	*tests = test ? (const char *)test[0] : g_str1_tests[1];
	int			i = -129, grade = -129;
	char		*user, *libc;
	bool		success;

	(void)name;
	while (i < 256)
	{
		ft_time_function(USER_START);
		user = ft_strrchr(tests, i);
		ft_time_function(USER_END_LIBC_START);
		libc = strrchr(tests, i);
		ft_time_function(LIBC_END);
		success = (user == libc);
		if (!success)
		{
			ft_result_input_str((char *)tests, NULL);
			ft_result_input_int(i);
			ft_result_output_str(user, libc);
			ft_print_result(true);
		}
		grade += success;
		i++;
	}
	return (grade == i);
}