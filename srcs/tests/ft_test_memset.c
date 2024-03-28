/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_memset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 08:06:06 by juperez           #+#    #+#             */
/*   Updated: 2024/03/28 15:46:07 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

static bool	ft_run_test(char *user, char *libc, int c, size_t n)
{
	ft_time_function(USER_START);
	ft_memset(user, c, n);
	ft_time_function(USER_END_LIBC_START);
	memset(libc, c, n);
	ft_time_function(LIBC_END);
	if (strcmp(user, libc))
	{
		ft_result_input_sizet(n);
		ft_result_input_int(c);
		ft_result_output_str(user, libc);
		ft_print_result(true);
		return (false);
	}
	return (true);
}

static bool	ft_test_size(char *user, char *libc, int c)
{
	size_t	i = 0, grade = 0;

	while (i < 16)
	{
		grade += ft_run_test(user, libc, c, i);
		i++;
	}
	return (grade == i);
}

static bool	ft_test_irange(char *user, char *libc)
{
	int	i = -129, grade = -129;

	while (i <= 256)
	{
		grade += ft_test_size(user, libc, i);
		i++;
	}
	return (grade == i);
}

static bool	ft_test_tab(char *user, char *libc, char *tests)
{
	size_t	i = 0, grade = 0;

	while (tests[i])
	{
		grade += ft_test_size(user, libc, (int)tests[i]);
		i++;
	}
	return (grade == i);
}

bool	ft_test_memset(char *name, void **test)
{
	char		user[] = "................", libc[] = "................";

	(void)name;
	return (test ? ft_test_tab(user, libc, (char *)test[0]) : ft_test_irange(user, libc));
}
