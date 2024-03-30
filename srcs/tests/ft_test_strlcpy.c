/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_strlcpy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 09:25:46 by juperez           #+#    #+#             */
/*   Updated: 2024/03/30 10:26:52 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

static bool	ft_run_test(const char *src, size_t size)
{
	char	user_dst[] = "................";
	char 	libc_dst[] = "................";
	size_t	user, libc;

	ft_time_function(USER_START);
	user = ft_strlcpy(user_dst, src, size);
	ft_time_function(USER_END_LIBC_START);
	libc = strlcpy(libc_dst, src, size);
	ft_time_function(LIBC_END);
	if (strcmp(user_dst, libc_dst) && !(user == libc))
	{
		ft_result_input_sizet(size);
		ft_result_input_str((char *)src, NULL);
		ft_result_output_sizet(user, libc);
		ft_result_output_str(user_dst, libc_dst);
		ft_print_result(true);
		return (false);
	}
	return (true);
}

bool	ft_test_strlcpy(char *name)
{
	size_t	i = 0, grade = 0;

	(void)name;
	while (i < 16)
	{
		grade += ft_run_test(g_str1_tests[1], i);
		i++;
	}
	return (grade == i);
}
