/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_strdup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 09:49:04 by juperez           #+#    #+#             */
/*   Updated: 2024/03/28 08:37:39 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

bool	ft_test_strdup(char *name, void **test)
{
	const char	**tests = test ? (const char **)test : g_str_tests;
	size_t		i = 0, grade = 0;
	char		*user, *libc;
	bool		success;

	(void)name;
	while (tests[i])
	{
		ft_time_function(USER_START);
		user = ft_strdup(tests[i]);
		ft_time_function(USER_END_LIBC_START);
		libc = strdup(tests[i]);
		ft_time_function(LIBC_END);
		success = (!strcmp(user, libc) && (strlen(user) == strlen(libc)));
		if (!success)
		{
			ft_result_input_str((char *)tests[i], NULL);
			ft_result_output_str(user, libc);
			ft_print_result(true);
		}
		grade += success;
		free(user);
		free(libc);
		i++;
	}
	return (grade == i);
}
