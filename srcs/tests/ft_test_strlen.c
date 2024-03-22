/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_strlen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 09:42:04 by juperez           #+#    #+#             */
/*   Updated: 2024/03/22 12:27:22 by juperez          ###   ########.fr       */
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
		ft_time_function("user_start");
		user = ft_strlen(tests[i]);
		ft_time_function("user_end orig_start");
		orig = strlen(tests[i]);
		ft_time_function("orig_end");
		success = (user == orig);
		if (!success)
			ft_print_test_strint(tests[i], (int)user, (int)orig);
		grade += success;
		i++;
	}
	return (grade == i);
}
