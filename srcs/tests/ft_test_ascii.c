/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_ascii.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 08:42:03 by juperez           #+#    #+#             */
/*   Updated: 2024/03/25 19:00:09 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

static void	ft_get_test_functions(char *name, int (**user)(int), int (**orig)(int))
{
	const t_fascii	fascii[] = {
	{"ft_isalnum", ft_isalnum, isalnum},
	{"ft_isalpha", ft_isalpha, isalpha},
	{"ft_isascii", ft_isascii, isascii},
	{"ft_isdigit", ft_isdigit, isdigit},
	{"ft_isprint", ft_isprint, isprint},
	{"ft_tolower", ft_tolower, tolower},
	{"ft_toupper", ft_toupper, toupper},
	{NULL, NULL, NULL}
	};

	for (size_t i = 0; fascii[i].name; i++)
	{
		if (!strcmp(name, fascii[i].name))
		{
			*user = fascii[i].user;
			*orig = fascii[i].orig;
		}
	}
}

static bool	ft_test_irange(int (*f_user)(int), int (*f_orig)(int))
{
	int		i = -129, grade = -129;
	int		user, orig;
	bool	success;

	while (i <= 256)
	{
		ft_time_function(USER_START);
		user = (*f_user)(i);
		ft_time_function(USER_END_ORIG_START);
		orig = (*f_orig)(i);
		ft_time_function(ORIG_END);
		success = (orig == user);
		if (!success)
			ft_print_fail_chrint(i, user, orig);
		grade += success;
		i++;
	}
	return (grade == i);
}

static bool	ft_test_tab(int (*f_user)(int), int (*f_orig)(int), const char **tests)
{
	size_t	i = 0, grade = 0;
	int		user, orig;
	bool	success;

	while (tests[0][i])
	{
		ft_time_function(USER_START);
		user = (*f_user)(tests[0][i]);
		ft_time_function(USER_END_ORIG_START);
		orig = (*f_orig)(tests[0][i]);
		ft_time_function(ORIG_END);
		success = (orig == user);
		if (!success)
			ft_print_fail_chrint(tests[0][i], user, orig);
		grade += success;
		i++;
	}
	return (grade == i);
}

bool	ft_test_ascii(char *name, void **test)
{
	int	(*f_user)(int), (*f_orig)(int);

	ft_get_test_functions(name, &f_user, &f_orig);
	return (test ? ft_test_tab(f_user, f_orig, (const char **)test) : ft_test_irange(f_user, f_orig));
}
