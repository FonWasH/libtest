/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_substr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 09:30:55 by juperez           #+#    #+#             */
/*   Updated: 2024/03/30 10:55:32 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

char	*g_expect[] = {
	"Hello",
	"Hello World!",
	"World!",
	"World!",
	"!",
	" ",
	"",
	NULL,
};

static bool	ft_run_test(char const *s, unsigned int start, size_t len, char *e)
{
	char	*user, *libc;

	ft_time_function(USER_START);
	user = ft_substr(s, start, len);
	ft_time_function(USER_END);
	libc = e;
	if (strcmp(user, libc))
	{
		ft_result_input_str((char *)s, NULL);
		ft_result_input_int((int)start);
		ft_result_input_sizet(len);
		ft_result_output_str(user, libc);
		ft_print_result(false);
		free(user);
		return (false);
	}
	free(user);
	return (true);
}

bool	ft_test_substr(char *name)
{
	unsigned int	start[] = {0, 0, 6, 6, 11, 5, 0};
	size_t			len[] = {5, 15, 6, 15, 1, 1, 0};
	size_t			i = 0, grade = 0;

	(void)name;
	while (g_expect[i])
	{
		grade += ft_run_test(g_str1_tests[1], start[i], len[i], g_expect[i]);
		i++;
	}
	return (grade == i);
}
