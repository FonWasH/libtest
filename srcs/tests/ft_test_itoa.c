/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_itoa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 09:48:58 by juperez           #+#    #+#             */
/*   Updated: 2024/03/30 10:27:03 by juperez          ###   ########.fr       */
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

static bool	ft_run_test(char *n_str)
{
	int		n = atoi(n_str);
	char	*user;

	ft_time_function(USER_START);
	user = ft_itoa(n);
	ft_time_function(USER_END);
	if (strcmp(user, n_str))
	{
		ft_result_input_int(n);
		ft_result_output_str(user, n_str);
		ft_print_result(false);
		free(user);
		return (false);
	}
	free(user);
	return (true);
}

bool	ft_test_itoa(char *name)
{
	size_t	i = 0, grade = 0;

	(void)name;
	while (g_itoa_tests[i])
	{
		grade += ft_run_test((char *)g_itoa_tests[i]);
		i++;
	}
	return (grade == i);
}
