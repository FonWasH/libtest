/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_strjoin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 09:31:09 by juperez           #+#    #+#             */
/*   Updated: 2024/03/30 20:10:14 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

const char	*g_str1_tests[] = {
	"\t\n\v\f\r ",
	"Hello World!",
	"abcdefghijklmnopqrstuvwxyz",
	"42",
	"#",
	"",
	NULL
};

const char	*g_str2_tests[] = {
	"Hello World!",
	"Hello42",
	"abcdefghijklmnopqrstuvwxyz",
	"abcdefghijklmnopqrstuvwxyzABC",
	"abc",
	"abcABC",
	"42",
	"#",
	"",
	NULL
};

static bool	ft_run_test()
{
	char	*user, *expected;

	ft_time_function(USER_START);
	user = ft_strjoin();
	ft_time_function(USER_END);
	expected = ;
	if (strcmp(user, expected))
	{
		ft_result_input_str();
		ft_result_input_chr();
		ft_result_input_int();
		ft_result_input_sizet();
		ft_result_output_str(user, expected);
		ft_result_output_chr();
		ft_result_output_int();
		ft_result_output_sizet();
		ft_print_result(false);
		free(user);
		return (false);
	}
	free(user);
	return (true);
}

bool	ft_test_strjoin(char *name)
{
	size_t	i = 0, grade = 0;

	(void)name;
	while ()
	{

	}
	return (grade == i);
}
