/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_substr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 09:30:55 by juperez           #+#    #+#             */
/*   Updated: 2024/03/29 14:53:33 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

const char	*expected[] ={
	"Hello",
	"Hello World!",
	"World!",
	"World!",
	"!",
	"",
	NULL,
};

bool	ft_test_substr(char *name, void **test)
{
	unsigned int	start[] = {0, 0, 6, 6, 11, 0};
	size_t			len[] = {5, 15, 6, 15, 1, 0};
	size_t			i = 0, grade = 0;
	char			*user, *libc;
	bool			success;

	(void)name;
	(void)test;
	while (expected[i])
	{
		ft_time_function(USER_START);
		user = ft_substr(g_str1_tests[1], start[i], len[i]);
		ft_time_function(USER_END);
		libc = (char *)expected[i];
		success = (!strcmp(user, libc));
		if (!success)
		{
			ft_result_input_str((char *)g_str1_tests[1], NULL);
			ft_result_input_int((int)start[i]);
			ft_result_input_sizet(len[i]);
			ft_result_output_str(user, libc);
			ft_print_result(true);
		}
		grade += success;
		free(user);
		i++;
	}
	return (grade == i);
}
