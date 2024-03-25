/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_atoi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 09:48:50 by juperez           #+#    #+#             */
/*   Updated: 2024/03/25 19:00:19 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

bool	ft_test_atoi(char *name, void **test)
{
	const char	**tests = test ? (const char **)test : g_atoi_tests;
	size_t		i = 0, grade = 0;
	int			user, orig;
	bool		success;

	(void)name;
	while (tests[i])
	{
		ft_time_function(USER_START);
		user = ft_atoi(tests[i]);
		ft_time_function(USER_END_ORIG_START);
		orig = atoi(tests[i]);
		ft_time_function(ORIG_END);
		success = (user == orig);
		if (!success)
			ft_print_fail_strint(tests[i], user, orig);
		grade += success;
		i++;
	}
	return (grade == i);
}
