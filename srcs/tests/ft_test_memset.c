/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_memset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 08:06:06 by juperez           #+#    #+#             */
/*   Updated: 2024/03/29 17:31:47 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

static bool	ft_run_test(int c, size_t n)
{
	char	user[] = "................";
	char	libc[] = "................";

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
		ft_print_result();
		return (false);
	}
	return (true);
}

static bool	ft_test_size(int c)
{
	size_t	i = 0, grade = 0;

	while (i < 16)
	{
		grade += ft_run_test(c, i);
		i++;
	}
	return (grade == i);
}

bool	ft_test_memset(char *name)
{
	int	i = CHAR_MIN - 1, grade = CHAR_MIN - 1;

	(void)name;
	while (i <= UCHAR_MAX + 1)
	{
		grade += ft_test_size(i);
		i++;
	}
	return (grade == i);
}
