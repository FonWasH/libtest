/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_memcmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 09:30:15 by juperez           #+#    #+#             */
/*   Updated: 2024/03/28 20:29:56 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

static bool	ft_run_test(const void *s1, const void *s2, size_t n)
{
	int	user, libc;

	ft_time_function(USER_START);
	user = ft_memcmp(s1, s2, n);
	ft_time_function(USER_END_LIBC_START);
	libc = memcmp(s1, s2, n);
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

static bool	ft_test_size(const void *s1, const void *s2)
{
	size_t	i = 0, grade = 0;
	size_t	s1_len = strlen((char *)s1), s2_len = strlen((char *)s2);
	size_t	size = s1_len <= s2_len ? s1_len : s2_len;

	while (i < size)
	{
		grade += ft_run_test(s1, s2, i);
		i++;
	}
	return (grade == i);
}

static bool	ft_test_tofind(const void *s1)
{
	size_t	i = 0, grade = 0;

	while (g_str2_tests[i])
	{
		grade += ft_test_size(s1, (const void *)g_str2_tests[i]);
		i++;
	}
	return (grade == i);
}

bool	ft_test_memcmp(char *name, void **test)
{
	const char	**tests = test ? (const char **)test : g_str1_tests;
	size_t		i = 0, grade = 0;

	(void)name;
	while (tests[i])
	{
		grade += ft_test_tofind((const void *)tests[i]);
		i++;
	}
	return (grade == i);
}
