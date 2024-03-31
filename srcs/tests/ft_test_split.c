/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 09:31:37 by juperez           #+#    #+#             */
/*   Updated: 2024/03/31 12:35:01 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

const char	*g_split_str[] = {
	"   Hello    World !   ",
	"  42  ",
	"42",
	"   ",
	"",
	"a b c d e f",
	"abc def",
	NULL
};

const char	*g_esplit[][7] = {
	{"Hello", "World", "!", NULL},
	{"42", NULL},
	{"42", NULL},
	{NULL},
	{NULL},
	{"a", "b", "c", "d", "e", "f", NULL},
	{"abc", "def", NULL}
};

static void	ft_free(char **user)
{
	for (size_t i = 0; user[i]; i++)
		free(user[i]);
	free(user);
}

static bool	ft_check_result(char **user, char **e)
{
	for (size_t i = 0; e[i]; i++)
	{
		if (e[i] && !user[i])
			return (false);
		if (!e[i] && user[i])
			return (false);
		if (e[i] && user[i] && strcmp(user[i], e[i]))
			return (false);
	}
	return (true);
}

static bool	ft_run_test(char const *s, char c, char **e)
{
	char	**user;

	ft_time_function(USER_START);
	user = ft_split(s, c);
	ft_time_function(USER_END);
	if (!ft_check_result(user, e))
	{
		ft_result_input_str((char *)s, NULL);
		ft_result_input_chr(c);
		ft_result_output_tabstr(user, e);
		ft_print_result(false);
		ft_free(user);
		return (false);
	}
	ft_free(user);
	return (true);
}

bool	ft_test_split(char *name)
{
	size_t	i = 0, grade = 0;

	(void)name;
	while (g_split_str[i])
	{
		grade += ft_run_test(g_split_str[i], ' ', (char **)g_esplit[i]);
		i++;
	}
	return (grade == i);
}
