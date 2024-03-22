/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_memcpy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 21:39:19 by juperez           #+#    #+#             */
/*   Updated: 2024/03/22 12:27:22 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

bool	ft_test_memcpy(char *name, void **test)
{
	const char	**tests = test ? (const char **)test : g_str_tests;
	size_t		i = 0, grade = 0, test_len;
	char		*user, *orig;
	bool		success;

	(void)name;
	while (tests[i])
	{
		test_len = strlen(tests[i]);
		user = (char *)malloc(sizeof(char) * test_len + 1);
		orig = (char *)malloc(sizeof(char) * test_len + 1);
		if (!user || !orig)
		{
			fprintf(stderr, "Error: Memory allocation\n");
			exit(EXIT_FAILURE);
		}
		user[test_len] = '\0';
		orig[test_len] = '\0';
		ft_time_function("user_start");
		ft_memcpy(user, tests[i], strlen(tests[i]));
		ft_time_function("user_end orig_start");
		memcpy(orig, tests[i], strlen(tests[i]));
		ft_time_function("orig_end");
		success = (!strcmp(user, orig));
		if (!success)
			ft_print_test_strstr(tests[i], user, orig);
		grade += success;
		free(user);
		free(orig);
		i++;
	}
	return (grade == i);
}
