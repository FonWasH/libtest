/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_strtrim.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 09:31:22 by juperez           #+#    #+#             */
/*   Updated: 2024/05/22 01:22:12 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

const char	*g_strtrim_s1[] = {
	"   Hello World!   ",
	"eeeHello World!ooo",
	"Hello World!ooo",
	"eeeHello World!",
	"42",
	"",
	NULL
};

const char	*g_strtrim_set[] = {
	" ",
	"eo",
	"eo",
	"eo",
	"",
	"42",
	NULL
};

const char	*g_estrtrim[] = {
	"Hello World!",
	"Hello World!",
	"Hello World!",
	"Hello World!",
	"42",
	"",
	NULL
};

static bool	ft_run_test(char const *s1, char const *set, char *e)
{
	char	*user;

	ft_time_function(USER_START);
	user = ft_strtrim(s1, set);
	ft_time_function(USER_END);
	if (strcmp(user, e))
	{
		ft_result_input_str((char *)s1, (char *)set);
		ft_result_output_str(user, e);
		ft_print_result(false);
		free(user);
		return (false);
	}
	free(user);
	return (true);
}

bool	ft_test_strtrim(char *name)
{
	size_t	i = 0, grade = 0;

	(void)name;
	while (g_strtrim_s1[i])
	{
		grade += ft_run_test(g_strtrim_s1[i], g_strtrim_set[i], (char *)g_estrtrim[i]);
		i++;
	}
	return (grade == i);
}
