/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_memchr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 09:30:00 by juperez           #+#    #+#             */
/*   Updated: 2024/03/28 20:29:56 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

static bool	ft_run_test(const void *s, int c, size_t n)
{
	void	*user, *libc;

	ft_time_function(USER_START);
	user = ft_memchr(s, c, n);
	ft_time_function(USER_END_LIBC_START);
	libc = memchr(s, c, n);
	ft_time_function(LIBC_END);
	if (!(user == libc))
	{
		ft_result_input_str((char *)s, NULL);
		ft_result_input_int(c);
		ft_result_input_sizet(n);
		ft_result_output_str((char *)user, (char *)libc);
		ft_print_result(true);
		return (false);
	}
	return (true);
}

static bool	ft_test_size(const void *s, int c, size_t size)
{
	size_t	i = 0, grade = 0;

	while (i < size)
	{
		grade += ft_run_test(s, c, i);
		i++;
	}
	return (grade == i);
}

bool	ft_test_memchr(char *name, void **test)
{
	const void	*tests = test ? (const void *)test[0] : (const void *)g_str1_tests[1];
	int			i = -129, grade = -129;

	(void)name;
	while (i < 256)
	{
		grade += ft_test_size(tests, i, strlen((char *)tests));
		i++;
	}
	return (grade == i);
}
