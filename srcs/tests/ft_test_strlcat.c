/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_strlcat.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 08:48:30 by juperez           #+#    #+#             */
/*   Updated: 2024/03/29 19:16:38 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

static bool	ft_run_test(const char *src, size_t size)
{
	char	user_dst[] = "DEST\0............................";
	char 	libc_dst[] = "DEST\0............................";
	size_t	user, libc;

	ft_time_function(USER_START);
	user = ft_strlcat(user_dst, src, size);
	ft_time_function(USER_END_LIBC_START);
	libc = strlcat(libc_dst, src, size);
	ft_time_function(LIBC_END);
	if (strcmp(user_dst, libc_dst) && !(user == libc))
	{
		ft_result_input_sizet(size);
		ft_result_input_str((char *)src, NULL);
		ft_result_output_sizet(user, libc);
		ft_result_output_str(user_dst, libc_dst);
		ft_print_result();
		return (false);
	}
	return (true);
}

bool	ft_test_strlcat(char *name)
{
	size_t	size[] = {0, 1, 2, 4, 8, 16, 32};
	size_t	i = 0, grade = 0, count = sizeof(size) / sizeof(size[0]);

	(void)name;
	while (i < count)
	{
		grade += ft_run_test(g_str1_tests[1], size[i]);
		i++;
	}
	return (grade == i);
}
