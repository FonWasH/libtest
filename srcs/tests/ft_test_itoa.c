/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_itoa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 09:48:58 by juperez           #+#    #+#             */
/*   Updated: 2024/03/25 19:00:19 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

bool	ft_test_itoa(char *name, void **test)
{
	const char	**tests = test ? (const char **)test : g_itoa_tests;	
	size_t		i = 0, grade = 0;
	char		*user;
	bool		success;

	(void)name;
	while (tests[i])
	{
		ft_time_function(USER_START);
		user = ft_itoa(atoi(tests[i]));
		ft_time_function(USER_END);
		success = (!strcmp(user, tests[i]));
		if (!success)
			ft_print_fail_strstr(tests[i], user, (char *)tests[i]);
		grade += success;
		free(user);
		i++;
	}
	return (grade == i);
}
