/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_strnstr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 09:30:29 by juperez           #+#    #+#             */
/*   Updated: 2024/03/30 10:26:56 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

static bool	ft_run_test(const char *str, const char *to_find, size_t len)
{
	char	*user, *libc;

	ft_time_function(USER_START);
	user = ft_strnstr(str, to_find, len);
	ft_time_function(USER_END_LIBC_START);
	libc = strnstr(str, to_find, len);
	ft_time_function(LIBC_END);
	if (!(user == libc))
	{
		ft_result_input_sizet(len);
		ft_result_input_str((char *)str, (char *)to_find);
		ft_result_output_str(user, libc);
		ft_print_result(true);
		return (false);
	}
	return (true);
}

static bool	ft_test_size(const char *str, const char *to_find)
{
	size_t	i = 0, grade = 0;

	while (i < 30)
	{
		grade += ft_run_test(str, to_find, i);
		i++;
	}
	return (grade == i);
}

static bool	ft_test_tofind(const char *str)
{
	size_t	i = 0, grade = 0;

	while (g_str2_tests[i])
	{
		grade += ft_test_size(str, g_str2_tests[i]);
		i++;
	}
	return (grade == i);
}

bool	ft_test_strnstr(char *name)
{
	size_t	i = 0, grade = 0;

	(void)name;
	while (g_str1_tests[i])
	{
		grade += ft_test_tofind(g_str1_tests[i]);
		i++;
	}
	return (grade == i);
}
