/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_strjoin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 09:31:09 by juperez           #+#    #+#             */
/*   Updated: 2024/03/30 20:25:47 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

const char	*g_strjoin_s1[] = {
	"Hello",
	"4",
	"",
	"abc",
	"",
	NULL
};

const char	*g_strjoin_s2[] = {
	" World!",
	"2",
	"",
	"",
	"abc",
	NULL
};

const char	*g_estrjoin[] = {
	"Hello World!",
	"42",
	"",
	"abc",
	"abc",
	NULL
};

static bool	ft_run_test(char const *s1, char const *s2, char *e)
{
	char	*user;

	ft_time_function(USER_START);
	user = ft_strjoin(s1, s2);
	ft_time_function(USER_END);
	if (strcmp(user, e))
	{
		ft_result_input_str((char *)s1, (char *)s2);
		ft_result_output_str(user, e);
		ft_print_result(false);
		free(user);
		return (false);
	}
	free(user);
	return (true);
}

bool	ft_test_strjoin(char *name)
{
	size_t	i = 0, grade = 0;

	(void)name;
	while (g_strjoin_s1[i])
	{
		grade += ft_run_test(
				g_strjoin_s1[i], g_strjoin_s2[i], (char *)g_estrjoin[i]);
		i++;
	}
	return (grade == i);
}
