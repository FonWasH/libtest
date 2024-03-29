/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_strdup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 09:49:04 by juperez           #+#    #+#             */
/*   Updated: 2024/03/29 17:31:47 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

static bool	ft_run_test(const char *s)
{
	char	*user, *libc;

	ft_time_function(USER_START);
	user = ft_strdup(s);
	ft_time_function(USER_END_LIBC_START);
	libc = strdup(s);
	ft_time_function(LIBC_END);
	if (strcmp(user, libc))
	{
		ft_result_input_str((char *)s, NULL);
		ft_result_output_str(user, libc);
		ft_print_result();
		free(user);
		free(libc);
		return (false);
	}
	free(user);
	free(libc);
	return (true);
}

bool	ft_test_strdup(char *name)
{
	size_t	i = 0, grade = 0;

	(void)name;
	while (g_str1_tests[i])
	{
		grade += ft_run_test(g_str1_tests[i]);
		i++;
	}
	return (grade == i);
}
