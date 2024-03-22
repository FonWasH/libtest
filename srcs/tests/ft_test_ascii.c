/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_ascii.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 08:42:03 by juperez           #+#    #+#             */
/*   Updated: 2024/03/22 12:24:19 by juperez          ###   ########.fr       */
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

bool	ft_test_ascii(char *name, void **test)
{
	const char	**tests = test ? (const char **)test : NULL;
	int			i = 0, grade = 0, user, orig;
	int			(*f_user)(int), (*f_orig)(int);
	bool		success;

	ft_get_test_functions(name, &f_user, &f_orig);
	if (tests)
	{
		while (tests[0][i])
		{
			ft_time_function("user_start");
			user = (*f_user)(tests[0][i]);
			ft_time_function("user_end orig_start");
			orig = (*f_orig)(tests[0][i]);
			ft_time_function("orig_end");
			success = (orig == user);
			if (!success)
				ft_print_test_chrint(tests[0][i], user, orig);
			grade += success;
			i++;
		}
	}
	else
	{
		i = -128;
		grade = -128;
		while (i <= 255)
		{
			ft_time_function("user_start");
			user = (*f_user)(i);
			ft_time_function("user_end orig_start");
			orig = (*f_orig)(i);
			ft_time_function("orig_end");
			success = (orig == user);
			if (!success)
				ft_print_test_chrint(i, user, orig);
			grade += success;
			i++;
		}
	}
	return (grade == i);
}
