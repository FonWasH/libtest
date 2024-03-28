/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_memcpy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 21:39:19 by juperez           #+#    #+#             */
/*   Updated: 2024/03/28 08:37:56 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

bool	ft_test_memcpy(char *name, void **test)
{
	const void	**tests = test ? (const void **)test : (const void **)g_str_tests;
	size_t		i = 0, grade = 0, test_len;
	char		*user, *libc;
	bool		success;

	(void)name;
	while (tests[i])
	{
		test_len = strlen(tests[i]);
		user = (char *)malloc(sizeof(char) * test_len + 1);
		libc = (char *)malloc(sizeof(char) * test_len + 1);
		if (!user || !libc)
		{
			fprintf(stderr, ERROR_MEM);
			exit(EXIT_FAILURE);
		}
		user[test_len] = '\0';
		libc[test_len] = '\0';
		ft_time_function(USER_START);
		ft_memcpy((void *)user, tests[i], test_len);
		ft_time_function(USER_END_LIBC_START);
		memcpy((void *)libc, tests[i], test_len);
		ft_time_function(LIBC_END);
		success = (!strcmp(user, libc));
		if (!success)
		{
			ft_result_input_sizet(test_len);
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
