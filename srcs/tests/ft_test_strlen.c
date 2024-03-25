/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_strlen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 09:42:04 by juperez           #+#    #+#             */
/*   Updated: 2024/03/25 19:00:19 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

bool	ft_test_strlen(char *name, void **test)
{
	const char	**tests = test ? (const char **)test : g_str_tests;
	size_t		i = 0, grade = 0;
	size_t		user, orig;
	bool		success;

	(void)name;
	while (tests[i])
	{
		ft_time_function(USER_START);
		user = ft_strlen(tests[i]);
		ft_time_function(USER_END_ORIG_START);
		orig = strlen(tests[i]);
		ft_time_function(ORIG_END);
		success = (user == orig);
		if (!success)
			ft_print_fail_strint(tests[i], (int)user, (int)orig);
		grade += success;
		i++;
	}
	return (grade == i);
}
