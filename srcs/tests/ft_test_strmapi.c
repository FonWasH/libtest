/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_strmapi.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 09:31:51 by juperez           #+#    #+#             */
/*   Updated: 2024/03/31 13:16:13 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

const char		*g_strmapi_str[] = {
	"helLO WorlD!",
	"abcdefghijklMNOpqrstuvwXYZ",
	"42",
	"",
	NULL
};

const char		*g_estrmapi[] = {
	"Hello world!",
	"Abcdefghijklmnopqrstuvwxyz",
	"42",
	"",
	NULL
};

static char	ft_test_function(unsigned int i, char c)
{
	return (i ? tolower(c) : toupper(c));
}

static bool	ft_run_test(char const *s, char (*f)(unsigned int, char), char *e)
{
	char	*user;

	ft_time_function(USER_START);
	user = ft_strmapi(s, f);
	ft_time_function(USER_END);
	if (strcmp(user, e))
	{
		ft_result_input_str((char *)s, NULL);
		ft_result_output_str(user, e);
		ft_print_result(false);
		free(user);
		return (false);
	}
	free(user);
	return (true);
}

bool	ft_test_strmapi(char *name)
{
	size_t	i = 0, grade = 0;

	(void)name;
	while (g_strmapi_str[i])
	{
		grade += ft_run_test(
				g_strmapi_str[i], ft_test_function, (char *)g_estrmapi[i]);
		i++;
	}
	return (grade == i);
}
