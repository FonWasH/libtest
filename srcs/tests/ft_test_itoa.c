/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_itoa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 09:48:58 by juperez           #+#    #+#             */
/*   Updated: 2024/03/28 08:38:04 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

const char	*g_itoa_tests[] = {
	"42",
	"-42",
	"0",
	"-2147483648",
	"2147483647",
	"-1",
	"1",
	"100",
	NULL
};

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
		{
			ft_result_input_int(atoi(tests[i]));
			ft_result_output_str(user, (char *)tests[i]);
			ft_print_result(true);
		}
		grade += success;
		free(user);
		i++;
	}
	return (grade == i);
}
