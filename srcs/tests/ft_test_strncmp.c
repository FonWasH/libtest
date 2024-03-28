/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_strncmp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 09:27:51 by juperez           #+#    #+#             */
/*   Updated: 2024/03/28 15:36:44 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

const char	*g_s2[] = {
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

static bool	ft_run_test(const char *s1, const char *s2, size_t n)
{
	int	user, libc;

	ft_time_function(USER_START);
	user = ft_strncmp(s1, s2, n);
	ft_time_function(USER_END_LIBC_START);
	libc = strncmp(s1, s2, n);
	ft_time_function(LIBC_END);
	if (!(user == libc))
	{
		ft_result_input_sizet(n);
		ft_result_input_str((char *)s1, (char *)s2);
		ft_result_output_int(user, libc);
		ft_print_result(true);
		return (false);
	}
	return (true);
}

static bool	ft_test_size(const char *s1, const char *s2)
{
	size_t	size[] = {0, 1, 2, 4, 8, 16};
	size_t	i = 0, grade = 0, count = sizeof(size) / sizeof(size[0]);

	while (i < count)
	{
		grade += ft_run_test(s1, s2, size[i]);
		i++;
	}
	return (grade == i);
}

static bool	ft_test_tofind(const char *s1)
{
	size_t	i = 0, grade = 0;

	while (g_s2[i])
	{
		grade += ft_test_size(s1, g_s2[i]);
		i++;
	}
	return (grade == i);
}

bool	ft_test_strncmp(char *name, void **test)
{
	const char	**tests_s1 = test ? (const char **)test : g_str_tests;
	size_t		i = 0, grade = 0;

	(void)name;
	while (tests_s1[i])
	{
		grade += ft_test_tofind(tests_s1[i]);
		i++;
	}
	return (grade == i);
}
