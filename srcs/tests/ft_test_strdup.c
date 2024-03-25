/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_strdup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 09:49:04 by juperez           #+#    #+#             */
/*   Updated: 2024/03/25 19:00:19 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

bool	ft_test_strdup(char *name, void **test)
{
	const char	**tests = test ? (const char **)test : g_str_tests;
	size_t		i = 0, grade = 0;
	char		*user, *orig;
	bool		success;

	(void)name;
	while (tests[i])
	{
		ft_time_function(USER_START);
		user = ft_strdup(tests[i]);
		ft_time_function(USER_END_ORIG_START);
		orig = strdup(tests[i]);
		ft_time_function(ORIG_END);
		success = (!strcmp(user, orig) && (strlen(user) == strlen(orig)));
		if (!success)
			ft_print_fail_strstr(tests[i], user, orig);
		grade += success;
		free(user);
		free(orig);
		i++;
	}
	return (grade == i);
}
