/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_memset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 08:06:06 by juperez           #+#    #+#             */
/*   Updated: 2024/03/22 14:12:05 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

static bool	ft_test_memset_size(char *user, char *orig, char c)
{
	size_t	size[] = {0, 1, 8, 16};
	size_t	count = sizeof(size) / sizeof(size[0]);

	for (size_t i = 0; i < count; i++)
	{
		ft_time_function(USER_START);
		ft_memset(user, c, size[i]);
		ft_time_function(USER_END_ORIG_START);
		memset(orig, c, size[i]);
		ft_time_function(ORIG_END);
		if (strcmp(user, orig))
			return (false);
	}
	return (true);
}

bool	ft_test_memset(char *name, void **test)
{
	const char	**tests = test ? (const char **)test : g_memset_tests;
	size_t		i = 0, grade = 0;
	char		user[] = "                ", orig[] = "                ";
	bool		success;

	(void)name;
	while (tests[0][i])
	{
		success = ft_test_memset_size(user, orig, tests[0][i]);
		if (!success)
			ft_print_test_chrstr(tests[0][i], user, orig);
		grade += success;
		i++;
	}
	return (grade == i);
}
