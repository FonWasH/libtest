/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_striteri.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 09:32:05 by juperez           #+#    #+#             */
/*   Updated: 2024/05/22 01:22:56 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

char		*g_striteri_str[] = {
	"helLO WorlD!",
	"abcdefghijklMNOpqrstuvwXYZ",
	"42",
	"",
	NULL
};

const char	*g_estriteri[] = {
	"Hello world!",
	"Abcdefghijklmnopqrstuvwxyz",
	"42",
	"",
	NULL
};

static void	ft_test_function(unsigned int i, char *s)
{
	*s = i ? tolower(*s) : toupper(*s);
}

static bool	ft_run_test(char *s, void (*f)(unsigned int, char *), char *e)
{
	char	*user;

	user = strdup(s);
	ft_time_function(USER_START);
	ft_striteri(user, f);
	ft_time_function(USER_END);
	if (strcmp(user, e))
	{
		ft_result_input_str(s, NULL);
		ft_result_output_str(user, e);
		ft_print_result(false);
		free(user);
		return (false);
	}
	free(user);
	return (true);
}

bool	ft_test_striteri(char *name)
{
	size_t	i = 0, grade = 0;

	(void)name;
	while (g_striteri_str[i])
	{
		grade += ft_run_test(g_striteri_str[i], ft_test_function, (char *)g_estriteri[i]);
		i++;
	}
	return (grade == i);
}
