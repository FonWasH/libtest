/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_ascii.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 08:42:03 by juperez           #+#    #+#             */
/*   Updated: 2024/03/30 10:26:33 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

static void	ft_get_functions(char *name, int (**user)(int), int (**libc)(int))
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
			*libc = fascii[i].libc;
		}
	}
}

static bool	ft_run_test(int (*f_user)(int), int (*f_libc)(int), int c)
{
	int	user, libc;

	ft_time_function(USER_START);
	user = (*f_user)(c);
	ft_time_function(USER_END_LIBC_START);
	libc = (*f_libc)(c);
	ft_time_function(LIBC_END);
	if (!(libc == user))
	{
		ft_result_input_int(c);
		ft_result_output_int(user, libc);
		ft_print_result(true);
		return (false);
	}
	return (true);
}

static bool	ft_test_irange(int (*f_user)(int), int (*f_libc)(int))
{
	int	i = CHAR_MIN - 1, grade = CHAR_MIN - 1;

	while (i <= UCHAR_MAX + 1)
	{
		grade += ft_run_test(f_user, f_libc, i);
		i++;
	}
	return (grade == i);
}

bool	ft_test_ascii(char *name)
{
	int	(*f_user)(int), (*f_libc)(int);

	ft_get_functions(name, &f_user, &f_libc);
	return (ft_test_irange(f_user, f_libc));
}
