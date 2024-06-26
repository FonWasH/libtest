/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_strchr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 09:26:37 by juperez           #+#    #+#             */
/*   Updated: 2024/03/30 10:26:48 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

static bool	ft_run_test(const char *s, int c)
{
	char	*user, *libc;

	ft_time_function(USER_START);
	user = ft_strchr(s, c);
	ft_time_function(USER_END_LIBC_START);
	libc = strchr(s, c);
	ft_time_function(LIBC_END);
	if (!(user == libc))
	{
		ft_result_input_str((char *)s, NULL);
		ft_result_input_int(c);
		ft_result_output_str(user, libc);
		ft_print_result(true);
		return (false);
	}
	return (true);
}

bool	ft_test_strchr(char *name)
{
	int	i = CHAR_MIN - 1, grade = CHAR_MIN - 1;

	(void)name;
	while (i <= UCHAR_MAX + 1)
	{
		grade += ft_run_test(g_str1_tests[1], i);
		i++;
	}
	return (grade == i);
}
